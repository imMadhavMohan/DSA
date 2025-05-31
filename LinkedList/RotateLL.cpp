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

Node* reverseLL(Node* curr, Node* prev = nullptr, int k = 0){ // head = curr
    if(curr == nullptr or !k){                
        return prev;
    }
    
    Node* next = curr->next;        
    curr->next = prev;        
    
    return reverseLL(next, curr, k-1);  // prev = head;
}

Node* rotateLL(Node* head, int k){
    // right rotate : (LL)rev , (0, k)rev, (k+1, n-1)rev
    if(k==0)
        return head;
        
    Node* itr = head; int cnt = 0, mv = k;
    while(itr!=nullptr) {
        cnt++;
        itr = itr->next;
    }
    
    head = reverseLL(head, nullptr, cnt); // whole LL rev    
    // printLL(head); // 1-6    

    Node* curr = head, *prev = nullptr, *nprev = nullptr; // rev 1st to prevNode & rev currNode -> nullptr;
    while(mv-- and curr!=nullptr) {
        prev = curr;
        curr = curr->next;        
    }    
    
    prev = reverseLL(head, nullptr, k);
    nprev = head;
    head->next = curr;
    head = prev;     
    // printLL(head); 0th to k-1 node


    curr = reverseLL(curr, nullptr, cnt-k);
    nprev->next = curr;  
    // printLL(head); // k+1th to n-1 node
    return head;      
}

int main(){
    Node* head = nullptr;
    int n = 3;
    for(int i=n;i>0;i--){
        Node* node = new Node(i);
        head = insertNodeBegin(node, head);
    }
    printLL(head);
    int rotate = 4 % n; // 7 ~= 3    
    head = rotateLL(head, rotate);

    printLL(head);
}