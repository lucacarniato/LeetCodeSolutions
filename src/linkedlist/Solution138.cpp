using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution138
{
public:
    Node* copyRandomList(Node* head)
    {
        if (!head)
        {
            return nullptr;
        }

        // make a copy and save the node in an hash table
        Node* headClone = new Node(head->val);
        Node* cn = head;
        Node* cnc = headClone;
        unordered_map<Node*, Node*> nextNodes;
        while (cn)
        {
            nextNodes[cn] = cn->next;
            cn = cn->next;
            if (cn)
            {
                cnc->next = new Node(cn->val);
            }
            else
            {
                cnc->next = nullptr;
            }
            cnc = cnc->next;
        }

        // assign the next node to the cloned node
        cn = head;
        cnc = headClone;
        while (cn)
        {
            cn->next = cnc;
            cn = nextNodes[cn];
            cnc = cnc->next;
        }

        // now assign the next random
        cn = head;
        cnc = headClone;
        while (cn)
        {
            if (cn->random)
            {
                cnc->random = cn->random->next;
            }
            cnc = cnc->next;
            cn = nextNodes[cn];
        }
        // now restore the next pointer in the original list
        cn = head;
        while (cn)
        {
            cn->next = nextNodes[cn];
            cn = cn->next;
        }
        return headClone;
    }
};
