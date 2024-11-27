#include <iostream>

using namespace std;



class Stack {

private:

    int top;

    int maxSize;

    int* stackArray;



public:

    Stack(int size) {

        maxSize = size;

        stackArray = new int[maxSize];

        top = -1;

    }



    ~Stack() {

        delete[] stackArray;

    }



    bool isEmpty() {

        return top == -1; 

    }



    bool isFull() {

        return top == maxSize - 1; 

    }



    void push(int value) {

        if (isFull()) {

            cout << "Stack is full. Cannot push " << value << endl;

            return;

        }

        stackArray[++top] = value;

        cout << "Pushed " << value << " onto the stack." << endl;

    }



    void pop() {

        if (isEmpty()) {

            cout << "Stack is empty. Cannot pop." << endl;

            return;

        }

        cout << "Popped " << stackArray[top] << " from the stack." << endl;

        top--; 

    }



    int peek() {

        if (isEmpty()) {

            cout << "Stack is empty. Cannot peek." << endl;

            return -1; 

        }

        return stackArray[top]; 

    }

};



int main() {

    Stack Stack(5);



    cout << "Is empty ?: " << Stack.isEmpty() << endl; 



    Stack.push(10);

    Stack.push(20);

    Stack.push(30);



    cout << "Is full ?: " << Stack.isFull() << endl; 



    Stack.push(40);

    Stack.push(50);



    cout << "Top element: " << Stack.peek() << endl; 



    cout << "Is full ?: " << Stack.isFull() << endl; 



    Stack.pop();

    Stack.pop();



    cout << "Top element after popping: " << Stack.peek() << endl; 



    Stack.push(60); 



    return 0;

}
