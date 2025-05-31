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

Node* deleteMid(Node* head){ // we can insert at middle also
    if(head == nullptr or head->next == nullptr)
        return head;
    Node* slow = head, *fast = head, *prev = nullptr;
    while(fast != nullptr and fast->next != nullptr){ // edge case for ODD & EVEN nodes
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    return slow;
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

int main(){
    Node* head = nullptr;
    for(int i=0;i<6;i++){
        Node* node = new Node(i+1);
        head = insertNodeBegin(node, head);
    }

    Node* mid = deleteMid(head);
    cout<<"Mid is: "<<mid->val<<endl;
    printLL(head);
}