#include <iostream>

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = nullptr; // NUll
        right = nullptr;
    }
};

class BinaryTree
{
private:
    TreeNode *root;

public:
    BinaryTree() : root(nullptr) {}

    // Insertion
    void insert(int val)
    {
        root = insertRecursive(root, val);
    }

    // Search
    bool search(int val)
    {
        return searchRecursive(root, val);
    }

    // Deletion
    void remove(int val)
    {
        root = removeRecursive(root, val);
    }

    // Find Minimum
    int findMin()
    {
        TreeNode *minNode = findMinRecursive(root);
        return minNode ? minNode->data : -1; // Return -1 if the tree is empty
    }

    // Find Maximum
    int findMax()
    {
        TreeNode *maxNode = findMaxRecursive(root);
        return maxNode ? maxNode->data : -1; // Return -1 if the tree is empty
    }

    // Inorder Traversal
    void printInorder()
    {
        inorderTraversal(root);
    }

private:
    TreeNode *insertRecursive(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < node->data)
        {
            node->left = insertRecursive(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertRecursive(node->right, val);
        }
        return node;
    }

    bool searchRecursive(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (val == node->data)
        {
            return true;
        }
        else if (val < node->data)
        {
            return searchRecursive(node->left, val);
        }
        else
        {
            return searchRecursive(node->right, val);
        }
    }

    TreeNode *removeRecursive(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (val < node->data)
        {
            node->left = removeRecursive(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = removeRecursive(node->right, val);
        }
        else
        {
            // Node with only one child or no child
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children, get the inorder successor (smallest in the right subtree)
            TreeNode *temp = findMinRecursive(node->right);
            node->data = temp->data;
            node->right = removeRecursive(node->right, temp->data);
        }
        return node;
    }

    TreeNode *findMinRecursive(TreeNode *node)
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }

    TreeNode *findMaxRecursive(TreeNode *node)
    {
        while (node && node->right)
        {
            node = node->right;
        }
        return node;
    }

    void inorderTraversal(TreeNode *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);

    std::cout << "Inorder Traversal: ";
    tree.printInorder();
    std::cout << std::endl;

    int searchValue = 3;
    bool found = tree.search(searchValue);
    if (found)
    {
        std::cout << searchValue << " found in the tree." << std::endl;
    }
    else
    {
        std::cout << searchValue << " not found in the tree." << std::endl;
    }

    int minValue = tree.findMin();
    int maxValue = tree.findMax();

    std::cout << "Minimum value in the tree: " << minValue << std::endl;
    std::cout << "Maximum value in the tree: " << maxValue << std::endl;

    tree.remove(2);

    std::cout << "Inorder Traversal after removing 2: ";
    tree.printInorder();
    std::cout << std::endl;

    return 0;
}
