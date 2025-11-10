#include <iostream>
#include <string>

// Define the Node struct
struct Node
{
    std::string data;
    Node *next;
    Node *prev;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node *&head, std::string value)
{
    Node *newNode = new Node{value, head, nullptr};
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to delete a node with a specific value
void deleteNode(Node *&head, std::string value)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            //update prv
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
                if (head != nullptr)
                {
                    head->prev = nullptr;
                }
            }
            //update nxt
            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            delete current;
            return; // Node found and deleted
        }
        current = current->next;
    }
}

// Function to print all elements in the list forward
void printListForward(const Node *head)
{
    const Node *current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to print all elements in the list backward
void printListBackward(const Node *tail)
{
    const Node *current = tail;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->prev;
    }

    std::cout << std::endl;
}

int main()
{
    Node *head = nullptr; // Initialize an empty list
    Node *tail = nullptr; // Initialize the tail

    // Insert nodes at the beginning
    insertAtBeginning(head, "Alice");
    insertAtBeginning(head, "Bob");
    insertAtBeginning(head, "Charlie");

    // Print the list forward
    std::cout << "List forward: ";
    printListForward(head);

    // Print the list backward
    tail = head; // Set the tail to the head for backward traversal
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    std::cout << "List backward: ";
    printListBackward(tail);

    // Delete a node
    deleteNode(head, "Bob");

    // Print the updated list forward
    std::cout << "List forward after deletion: ";
    printListForward(head);

    // Clean up memory (free dynamically allocated nodes)
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
