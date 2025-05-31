#include <algorithm>
using namespace std;

class Node{
    public:
        Node* next;
        int val;
        Node(int val):val(val), next(nullptr) {

        }          
};

Node* createNode(int val){
        Node *node = new Node(val);
        return node;
    }
    
    Node* insertNode(Node* head, Node* node){
          if(!head)
              return node;
          
          if(!head->next){
              head->next = node;
              return head;
          }
          insertNode(head->next, node);
          return head;
    }
    
    Node* findIntersection(Node* a, Node* b) {
        // code goes here.
        if(!a and !b)
            return a;
        if(a and !b)
            return a;
        if(!a and b)
            return b;
            
        Node* p = a, *q = b;
        Node *c = nullptr;
        
        while(p!=nullptr and q!=nullptr){
            if(p->val == q->val){
                Node* node = createNode(p->val);
                c = insertNode(c, node); 
                p=p->next; 
                q=q->next;
            }
            else if(p->val > q->val)
                q=q->next;
            else // if(p->val < q->val)
                p=p->next;
        }
        return c;
    }