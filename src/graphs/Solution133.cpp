#include "../shared/GraphNode.hpp"

using namespace std;

class Solution133
{
public:
    GraphNode* cloneGraph(GraphNode* node)
    {
        if (!node)
        {
            return nullptr;
        }

        GraphNode* result = new GraphNode(node->val);
        std::queue<GraphNode*> q;
        q.push(node);

        std::unordered_map<GraphNode*, GraphNode*> cloned_nodes;
        cloned_nodes.emplace(node, result);

        while (!q.empty())
        {
            auto cn = q.front();
            q.pop();

            for (GraphNode* neighbor : cn->neighbors)
            {
                if (!cloned_nodes.contains(neighbor))
                {
                    cloned_nodes[neighbor] = new GraphNode(neighbor->val);
                    q.push(neighbor);
                }

                cloned_nodes[cn]->neighbors.push_back(cloned_nodes[neighbor]);
            }
        }
        return result;
    }
};
