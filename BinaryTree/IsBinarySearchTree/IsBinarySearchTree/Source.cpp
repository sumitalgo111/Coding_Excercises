#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

bool IsBST(Node* root)
{
	int static mx = INT_MIN;

	if (root == NULL)
		return true;

	if (!IsBST(root->left))
		return false;

	if (root->data > mx)
		mx = root->data;
	else
		return false;

	if (!IsBST(root->right))
		return false;

	return true;
}

int main()
{
	Node* root = new Node(3);

	root->left = new Node(2);
	root->left->left = new Node(1);

	root->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);

	cout << " Binary Tree : " << ( (IsBST(root) ) ? "True" : "False") << endl;
}