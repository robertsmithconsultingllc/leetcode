// C++BinaryTreeMaximumPathSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>
#include <algorithm>
#include <climits>

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
    int maxPathSum(TreeNode* root) 
    {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    int maxGain(TreeNode* node, int& maxSum) 
    {
        if (node == nullptr) 
            return 0;
        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);
        int currentPathSum = node->val + leftGain + rightGain;
        maxSum = max(maxSum, currentPathSum);
        return node->val + max(leftGain, rightGain);
    }
};

int main() 
{
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}
