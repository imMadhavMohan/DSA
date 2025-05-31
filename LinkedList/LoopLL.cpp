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
    if(head->next == nullptr){
        cout<<head->val<<" ";
        cout<<endl;
        return;
    }
    cout<<head->val<<" ";
    printLL(head->next);
}

bool loop(Node* head){
    if(head==nullptr)
        return false;
        
    Node* slow = head, *fast = head;

    while(fast != slow){
        slow = slow->next;
        fast = fast->next->next;
        if(fast->next == nullptr or fast == nullptr)
            return false;
    }    
    return true;
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
    
    cout<<loop(head)?"Loop\n":"No loop\n";
    return 0;
}