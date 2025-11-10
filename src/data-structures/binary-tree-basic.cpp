#include <iostream>

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

int main()
{
	Node* root = new Node(1);

	/* following is the tree after above statement
	1
	/ \
	nullptr nullptr
	*/
	root->left = new Node(2);
	root->right = new Node(3);

	/* 2 and 3 become left and right children of 1
	  1
	 / \
	2   3
	/ \ / \
	nullptr nullptr nullptr nullptr
	*/
	root->left->left = new Node(4);
	/* 4 becomes left child of 2
		1
	/ \
	2	 3
	/ \ / \
	4 nullptr nullptr nullptr
	/ \
	nullptr nullptr
	*/

	// Clean up memory
	delete root->left->left;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}
