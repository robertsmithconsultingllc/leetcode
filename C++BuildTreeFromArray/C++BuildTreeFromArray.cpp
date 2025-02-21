// C++BuildTreeFromArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Function to recursively build the tree from
// inorder and preorder traversals

using namespace std;

#include <iostream>
#include <vector>
#include <random>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{

public:
	
	TreeNode* searchOrInsert(TreeNode** leaf, int val, bool key)
	{
		if ((*leaf) == NULL)
			if (key)
				return (*leaf) = new TreeNode(val);
			else
				return NULL;
		if (((*leaf)->val > val))
			return searchOrInsert((&(*leaf)->left), val, key);
		else if (((*leaf)->val < val))
			return searchOrInsert((&(*leaf)->right), val, key);
		return (*leaf);
	}

	void printInorder(TreeNode** leaf, int index)
	{
		if ((*leaf) == NULL)
			return;
		if ((*leaf)->left != NULL)
			printInorder((&(*leaf)->left), index + 1);
		for (int i = 0; i < index; i++)
			cout << "    ";
		printf("(%d) : level %d\n", (unsigned int)(*leaf)->val, index);
		if ((*leaf)->right != NULL)
			printInorder((&(*leaf)->right), index + 1);
	}
};

int main()
{
	Solution ptr;
	TreeNode* node{}; vector<int> data; 
	random_device rd; // Obtain a random number from hardware
	mt19937 gen(rd()); // Seed the generator
	uniform_int_distribution<> distr(1, 100); // Define the range
	cout << "Array converted to a binary tree: " << endl;
	int random_number{};
	for (int i = 0; i < 10; i++)
		data.push_back(random_number = distr(gen));
	for (int i = 0; i < 10; i++)
		ptr.searchOrInsert(&node, data[i], true);
	ptr.printInorder(&node, 0);
	return 0;
}
