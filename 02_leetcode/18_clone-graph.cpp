/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node) {
            return NULL;
        }
 
        map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;
        map<UndirectedGraphNode*, bool> visited;
 
        queue<UndirectedGraphNode*> q;
        q.push(node);
        // solve the head
        UndirectedGraphNode *head_new = new UndirectedGraphNode(node->label);
        mapping[node] = head_new;
        // solve other nodes
        UndirectedGraphNode *current_old=NULL, *current_new=NULL, *node_old=NULL, *node_new=NULL;
        vector<UndirectedGraphNode*> neighbors;
        while (!q.empty()) {
            current_old = q.front(); q.pop();
            current_new = mapping[current_old];
            if (true == visited[current_old]) {
                continue;
            }
 
            neighbors = current_old->neighbors;
            for (int i = 0; i < neighbors.size(); i++) {
                node_old = neighbors[i];
                if (NULL == mapping[node_old]) {
                    node_new = new UndirectedGraphNode(node_old->label);
                    mapping[node_old] = node_new;
                }
                else {
                    node_new = mapping[node_old];
                }              
                current_new->neighbors.push_back(node_new);
                if (true != visited[node_new]) {
                    q.push(node_old);
                }
            }
 
            visited[current_old] = true;
        }
 
        return head_new;
    }
};