#include <iostream>
#include <vector>

const int MAX_SIZE = 100;

class Stack
{
private:
    std::vector<int> data;

public:
    Stack()
    {
        data.reserve(MAX_SIZE);
    }

    void push(int value)
    {
        if (data.size() >= MAX_SIZE)
        {
            std::cout << "Stack overflow. Cannot push." << std::endl;
            return;
        }
        data.push_back(value);
    }

    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return -1;
        }
        int top_element = data.back();
        data.pop_back();
        return top_element;
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return -1;
        }
        return data.back();
    }

    bool isEmpty()
    {
        return data.empty();
    }

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

    std::cout << "Stack size: " << myStack.size() << std::endl;
    std::cout << "Top element: " << myStack.peek() << std::endl;

    while (!myStack.isEmpty())
    {
        std::cout << "Popped: " << myStack.pop() << std::endl;
    }

    std::cout << "Stack size after popping all elements: " << myStack.size() << std::endl;

    return 0;
}
