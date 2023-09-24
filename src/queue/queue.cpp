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
        delete[] arr; // deallocates the entire dynamically allocated array and frees the memory used by the array
    }

    // enqueue to add an element to the rear of the queue
    void enqueue(int item) //10
    {
        if (isFull())
        {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        rear = (rear + 1) % capacity; // Circular queue
        arr[rear] = item;
        size++;
    }

    // dequeue remove and return an element from the front of the queue
    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return -1; // Assuming -1 represents an error or an empty queue
        }
        int item = arr[front];
        front = (front + 1) % capacity; // Circular queue
        size--;
        return item;
    }

    // isEmpty check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // isFull check if the queue is full
    bool isFull()
    {
        return size == capacity;
    }

    // getSize get the number of elements in the queue
    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue queue(5); // Create a queue with a capacity of 5

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;   // print "Dequeued: 1"
    std::cout << "Queue size: " << queue.getSize() << std::endl; // print "Queue size: 2"

    return 0;
}
