#include <iostream>
#include <string>

// Define the Node struct
struct Node
{
    std::string data;
    Node *next;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node *&head, std::string value)
{
    Node *newNode = new Node{value, head};
    head = newNode;
}

// Function to delete a node with a specific value
void deleteNode(Node *&head, std::string value)
{
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            if (prev != nullptr)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
            return; // Node found and deleted
        }
        prev = current;
        current = current->next;
    }
}

// Function to print all elements in the list
void printList(Node *head)
{
    const Node *current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

// Function to read the value at a specific index
std::string readAtIndex(Node *head, int index)
{
    const Node *current = head;
    int currentIndex = 0;

    while (current != nullptr)
    {
        if (currentIndex == index)
        {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }
    return ""; // Index out of bounds
}

int main()
{
    Node *head = nullptr; // Initialize an empty list

    // Insert nodes at the beginning
    insertAtBeginning(head, "Alice");
    insertAtBeginning(head, "Bob");
    insertAtBeginning(head, "Charlie");

    // Print the initial list
    std::cout << "Initial list: ";
    printList(head);

    // Delete a node
    deleteNode(head, "Bob");

    // Print the updated list
    std::cout << "List after deletion: ";
    printList(head);

    // Read a value at a specific index
    int index = 1;
    std::string value = readAtIndex(head, index);
    if (!value.empty())
    {
        std::cout << "Value at index " << index << ": " << value << std::endl;
    }
    else
    {
        std::cout << "Index " << index << " is out of bounds." << std::endl;
    }

    // Clean up memory (free dynamically allocated nodes)
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    std::cout << "List after deletion:"
              << head << "\n";
    return 0;
}
