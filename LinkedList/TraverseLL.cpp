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

Node* insertNodeEnd(Node* node, Node* head){ // insertion in end
    if(head->next == nullptr){
        head->next = node;
        return head;
    }
    // Node* prev = head;
    insertNodeEnd(node, head->next);
    return head; // prev
}

Node* deleteNodeEnd(Node* head){
    if(head->next->next == nullptr){
        head->next = nullptr;
        return head;
    }
    deleteNodeEnd(head->next);
    return head;
}

void printLL(Node* head){    
    if(head->next == nullptr){
        cout<<head->val<<" ";
        cout<<endl;
        return;
    }
    cout<<head->val<<" ";
    printLL(head->next);
}

Node* deleteNodeVal(Node* head, int val, Node* prev){
    if(head->val == val){
        prev->next = head->next;        
        return head;
    }    
    deleteNodeVal(head->next, val, head);
    return head;
}

int main(){
    Node* head = nullptr;
    for(int i=0;i<5;i++){
        Node* node = new Node(i+1);
        head = insertNodeBegin(node, head);
    }
    printLL(head);
    for(int i=0;i<5;i++){
        Node* node = new Node(i+2);
        head = insertNodeEnd(node, head);
    }    
    printLL(head);    
    
    head = deleteNodeEnd(head); // delete from end
    printLL(head);

    head = deleteNodeEnd(head); // delete from end
    printLL(head);

    Node* prev = head;
    head = deleteNodeVal(head, 1, prev);
    printLL(head);
    
    return 0;
}