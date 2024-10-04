#include <iostream>
using namespace std;

#define MAX 100


template <typename T>
class Stack {
private:
    T arr[MAX];
    int top;    

public: 
    Stack(){
        
        top =-1;
    }

    void push(T x){
        if(top>MAX){
            cout<<"Stack Overflow!";
            return;
        }
        arr[++top] = x;
        cout<<x<<" Added"<<endl;
    }

    bool isEmpty(){
        if(top ==-1)
            return true;
        else 
            return false;
    }

    T pop(){
        if(isEmpty()){
            cout<<"Stack empty!";
            return T();
        }
        
        return arr[top--];
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: "<<endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
        cout << endl;
    }
};

int main(){
    Stack<char> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');
   

    // cout<<s1.pop();

    s1.print();
   
}