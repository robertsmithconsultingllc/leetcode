// C++BinaryTreeRightSideView.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

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

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> rightSideView{}; 
        int level = 0;
        printLevelOrder(root, rightSideView, level);
        return rightSideView;
    }

    void printLevelOrder(TreeNode* root, vector<int>& rightSideView, int& level) 
    {
        if (root == NULL) 
            return;
        queue<TreeNode*> q;
        q.push(root);
        rightSideView.push_back(root->val);
        while (!q.empty()) 
        {
            int height = (int)q.size();
            for (int i = 0; i < height; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                cout << tmp->val << " ";
                if (tmp->left != NULL) 
                    q.push(tmp->left);
                if (tmp->right != NULL) 
                    q.push(tmp->right);
            }
            if(q.size())
                rightSideView.push_back(q.back()->val);
            cout << "level " << level++ << endl;
        }
    }
};

/*
Output: [1,3,13,6]
*/
int main(void)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(13);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    vector<int> ans = Solution().rightSideView(root);
    for (auto n : ans)
    {
        cout << n << " ";
    }
    return 0;
}

