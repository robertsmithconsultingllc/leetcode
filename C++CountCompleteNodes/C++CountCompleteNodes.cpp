// C++CountCompleteNodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    int countNodes(TreeNode* root) 
    {
        static int counter = 1;
        if (root->left)
            countNodes(root->left);
        cout << root->val << " ";
        if (root->right)
            countNodes(root->right);
        return counter++;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    int ans = Solution().countNodes(root);
    return 0;
}

