#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Node{
    public:
        Node* next;
        int val;
        Node(int val):val(val), next(nullptr) {

        }          
};

Node *getIntersectionNode(Node *a, Node *b) {
            if(!a and b)    return a;
            if(a and !b)    return b;
            if(!a and !b)    return b;

            unordered_set<Node*> us; Node* itr = a;
            while(itr){                
                us.insert(itr);
                itr = itr->next;
            }
            itr = b;
            while(itr){
                if(us.find(itr)!=us.end())
                    return itr;                                               
                itr = itr->next;
            }
            
            return nullptr;
    }