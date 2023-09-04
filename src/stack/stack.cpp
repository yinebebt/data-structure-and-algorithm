#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100; // Maximum size for the vector

class Stack
{
private:
    vector<int> data;

public:
    // Constructor to initialize the stack
    Stack()
    {
        data.reserve(MAX_SIZE); // Reserve space for the maximum size
    }

    // Push an element onto the stack
    void push(int value)
    {
        if (data.size() >= MAX_SIZE)
        {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }
        data.push_back(value); // Add value to the end of the data.
    }

    // Pop and return the top element from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;
        }
        int top_element = data.back(); // Returns the last element of data.
        data.pop_back();
        return top_element;
    }

    // Return the top element of the stack without popping it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value for an empty stack
        }
        return data.back();
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return data.empty();
    }

    // Return the size of the stack
    int size()
    {
        return data.size();
    }
};

int main()
{
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.peek() << endl;

    while (!myStack.isEmpty())
    {
        cout << "Popped: " << myStack.pop() << endl;
    }

    cout << "Stack size after popping all elements: " << myStack.size() << endl;

    return 0;
}


//stack-trace
void greet(string name) {
    cout << "hello, " << name << "!" << endl;
    greet2(name);
    cout << "getting ready to say bye..." << endl;
    bye();
}

void greet2(string name) {
    cout << "how are you, " << name << "?" << endl;
}

void bye() {
    cout << "ok bye!" << endl;
}

int main() {
    string name = "Abebe";
    greet(name);

    return 0;
}

