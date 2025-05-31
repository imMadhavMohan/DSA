#include <iostream>
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

Node* insertNodeBegin(Node* node, Node* head){ // insertion in beginning
    if(head == nullptr)
        return node;
    Node* addNode = head;
    node->next = addNode;
    head = node;
    return head;
}

Node* removeDuplicate(Node* head){
    if(!head or !(head->next))
        return head;
    
    unordered_set<int> us; // find, empty, size, insert, erase// store val in 
    Node* itr = head, *prev = nullptr;
    while(itr!=nullptr){        
        if(us.find(itr->val)==us.end())
            us.insert(itr->val);
        else{            
               prev->next = itr->next;
               itr = prev;                                             
        }     
        prev = itr;   
        itr = itr->next;
    }
    return head;
}

void printLL(Node* head){    
    if(head == nullptr) // 6 5 4 1 3 2 1
        return;    
    cout<<head->val<<" ";
    printLL(head->next);
}

int main(){  
    Node* head = nullptr; int n = 6;

    for(int i=1;i<=n;i++){
        Node* node = new Node(i);
        head = insertNodeBegin(node, head);
        if(i==3){
            Node* node = new Node(1);
            head = insertNodeBegin(node, head);
        }
    }
    printLL(head); cout<<endl;
    removeDuplicate(head);
    printLL(head);
    return 0;
}