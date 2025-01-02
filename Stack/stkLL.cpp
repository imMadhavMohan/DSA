#include <iostream>
using namespace std;

class Stk {
private:
    struct Node { // Nice
        int val;
        Node* next;
        Node(int value) : val(value), next(nullptr) {}
    };

    Node* head;
    int top;
    int size;

public:
    // Constructor
    Stk(int maxSize) : head(nullptr), top(-1), size(maxSize) {}

    // Push an element onto the stack
    void push(int val) {
        if (top == size - 1) {
            cout << "Stack overflow\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        top++;
    }

    // Pop an element from the stack
    void pop() { // head as removal
        if (top == -1) {
            cout << "Stack underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        top--;
    }

    // Peek the top element of the stack
    void peek() { // head as top
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Peeked element: " << head->val << endl;
    }

    // Print the entire stack
    void printStk() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = head;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~Stk() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Stk stk(5); // Create a stack with a maximum size of 5

    // Push elements onto the stack
    for (int i = 0; i < 5; i++) {
        stk.push(i + 1);
    }

    // Print the stack
    stk.printStk();

    // Pop two elements
    stk.pop();
    stk.pop();

    // Print the stack again
    stk.printStk();

    // Push another element
    stk.push(9);

    // Peek the top element
    stk.peek();

    // Print the final state of the stack
    stk.printStk();

    return 0;
}
