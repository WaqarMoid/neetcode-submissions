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
private:
    unordered_map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
    
    if(node==nullptr)
    return nullptr;

    if(mp.find(node)!=mp.end())
    {
        return mp[node];
    }

    Node* clonednode=new Node(node->val);
    mp[node]=clonednode;

    for(Node* neighbor:node->neighbors)
    {
        clonednode->neighbors.push_back(cloneGraph(neighbor));
    }

    return clonednode;

    }
};
