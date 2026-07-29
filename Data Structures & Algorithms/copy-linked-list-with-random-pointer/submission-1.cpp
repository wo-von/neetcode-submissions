/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> old2new;
public:
    Node* copyRandomList(Node* head) {
        old2new.clear();
        old2new[nullptr] = nullptr;
        
        for(Node* curr = head; curr; curr = curr->next){
            Node* copy = new Node(curr->val);
            old2new[curr] = copy;
        }
        for (Node* curr = head; curr; curr = curr->next){
            if(old2new.find(curr->random) != old2new.end()){
                old2new[curr]->random =old2new[curr->random];    
            }
            old2new[curr]->next = old2new[curr->next];
        }
        return old2new[head];
    }
};
