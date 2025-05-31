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

Node* reverseLL(Node* head){    
    if(head==nullptr or head->next==nullptr)
        return head;
    
    Node* prevNode = nullptr, *currNode = head, *nextNode = nullptr;

    while(currNode != nullptr){
        nextNode = currNode->next; // handling edge terminating case
        currNode->next = prevNode; // reverse node
        prevNode = currNode;    
        currNode = nextNode; // node to be processed    
    }
    head = prevNode;
    return head;
}

Node* reverseRecursiveLL(Node* currNode, Node* prevNode = nullptr){    
    if(currNode==nullptr)        
        return prevNode; // newHead

    Node* nextNode = currNode->next;     
    currNode->next = prevNode;
    prevNode = currNode;
    currNode = nextNode;

    /*prevNode = currNode;    
    currNode = nextNode; see recursion logic*/
    return reverseRecursiveLL(nextNode, prevNode); // rest of the code to be reversed, nextNode = act as currNode & currNode act as prevNode
}

Node* reverseList(Node* head){ // recursively reverse
    if(head==nullptr or head->next==nullptr)
        return head;    
    return reverseRecursiveLL(head);
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
    
    // head = reverseLL(head);
    // printLL(head);

    // head = reverseList(head);
    // printLL(head);

    head = reverseList(head);
    printLL(head);
    return 0;
}