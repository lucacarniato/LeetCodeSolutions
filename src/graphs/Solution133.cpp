/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(!node)
        {
            return nullptr;
        }
        
        Node* result = new Node(node->val);
        std::queue<Node*> q;
        q.push(node);

        std::unordered_map<Node*, Node*> cloned_nodes;
        cloned_nodes.emplace(node, result);

        while(!q.empty())
        {
            auto cn =  q.front();
            q.pop();

            for (Node* neighbor : cn->neighbors) 
            {
                if(!cloned_nodes.contains(neighbor))
                {
                    cloned_nodes[neighbor] = new Node(neighbor->val); 
                    q.push(neighbor);  
                }

                cloned_nodes[cn]->neighbors.push_back(cloned_nodes[neighbor]); 
            }
        }
        return result;
    }
};