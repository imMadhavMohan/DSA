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
    
int countNodesinLoop(Node *head) {
    if (!head || !head->next)
        return 0;

    Node *slow = head, *fast = head; Node *itr;

    // Detect the loop using Floyd's cycle detection algorithm
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) { // Loop detected
            itr = slow;
            break;
        }
    }
    if(fast==nullptr or fast->next==nullptr)
        return 0;
    int cnt = 0; itr = itr->next;
    while(itr!=fast){
        itr = itr->next;
        cnt++;
    }

    return cnt+1; // No loop detected
}

