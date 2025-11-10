#include <iostream>

class Queue
{
private:
    int *arr;
    int front, rear, capacity, size;

public:
    Queue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int item)
    {
        if (isFull())
        {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    std::cout << "Queue size: " << queue.getSize() << std::endl;

    return 0;
}
