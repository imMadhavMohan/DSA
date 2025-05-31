#include <iostream>
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

void printLL(Node* head){    
    if(head == nullptr)
        return;    
    cout<<head->val<<" ";
    printLL(head->next);
}

Node* reverseLL(Node* head, int k, Node* prev = nullptr){
    if(head==nullptr or !k)
        return prev;
    Node* next = head->next;
    head->next = prev;
    return reverseLL(next, k-1, head);
}

Node* rotateInk(Node* head, int k){
    if(head==nullptr)  
        return head;
    Node* itr = head; int cnt = k;
    while(itr != nullptr and cnt){
        cnt--;
        itr = itr->next;
    }
    if(cnt) // means cnt > 0 & itr = nullptr, k nodes aren't available
        return head;
    
    Node* newHead = reverseLL(head, k);
    
    if(itr!=nullptr) // itr->next!=nullptr
        head->next = rotateInk(itr, k); //itr;

    return newHead;  
}

/*
fast->next = nullptr or fast == nullptr
1 2 3 4 5 6 7
        8  
*/

int main(){
    Node* head = nullptr;
    int n = 7;
    for(int i=n;i>0;i--){
        Node* node = new Node(i);
        head = insertNodeBegin(node, head);        
    }
    printLL(head);
    cout<<"hi\n";

    head = rotateInk(head, 3);
    
    printLL(head);
    cout<<"hi\n";
    return 0;
}