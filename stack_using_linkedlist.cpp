#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node* next;

       Node(T value) {
        data = value;
        next = nullptr; 
    }
};

template <typename T>
class Stack {
private:
    Node<T>* head; // Head node

public: 
    Stack() {
        head = new Node<T>(T()); // Head node
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
        delete head; // Delete the head node
    }

    void push(T x) {
        Node<T>* newNode = new Node<T>(x);
        newNode->next = head->next; // Point to the current top
        head->next = newNode; // Update head to point to the new node
        cout << x << " Added" << endl;
    }

    bool isEmpty() const {
        return head->next == nullptr; // Check if there are any elements
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack empty!" << endl;
            return T(); // Return default value of T
        }
        Node<T>* temp = head->next; // Get the current top
        T poppedValue = temp->data;
        head->next = temp->next; // Update head to point to the next node
        delete temp; // Free the memory
        return poppedValue;
    }

    void print() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node<T>* current = head->next; // Start from the first real element
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<char> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');
   
    cout << s1.pop() << endl;

    s1.print();
    
    return 0;
}
