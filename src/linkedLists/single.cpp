#include <iostream>
#include <string>

struct Node {
    std::string data;  //value
    Node *next;  //pointer which point to a Node object/type
};

int main() {
    // Create linked list nodes
    Node *node1 = new Node{"Alice", nullptr};
    Node *node2 = new Node{"Bob", nullptr};
    Node *node3 = new Node{"Charlie", nullptr};

    // Connect the nodes
    node1->next = node2;
    node2->next = node3;

    // Traverse and print the linked list
    Node *current = node1;
    while (current != nullptr) {
        std::cout << "Data: " << current->data << std::endl;  //dereferencing pointer- getting the value
        current = current->next;
    }

    // Free memory to avoid memory leaks)
    delete node1;
    delete node2;
    delete node3;

    return 0;
}
