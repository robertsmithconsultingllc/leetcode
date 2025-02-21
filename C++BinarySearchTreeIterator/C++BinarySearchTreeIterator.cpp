// C++BinarySearchTreeIterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator 
{
private:
    stack<TreeNode*> nodeStack;

    void pushAllLeft(TreeNode* node) 
    {
        while (node != nullptr) 
        {
            nodeStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) 
    {
        pushAllLeft(root);
    }

    int next() 
    {
        TreeNode* currentNode = nodeStack.top();
        nodeStack.pop();
        int result = currentNode->val;
        if (currentNode->right != nullptr) 
            pushAllLeft(currentNode->right);
        return result;
    }

    bool hasNext() 
    {
        return !nodeStack.empty();
    }
};

int main()
{
    string ans[] = { "false", "true" };
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    BSTIterator* iterator = new BSTIterator(root);
    cout << iterator->next() << ",";    // return 3
    while (iterator)
    {
        cout << iterator->next() << ",";
        if (iterator->hasNext())
            cout << "true,";
        else
        {
            cout << "false";
            break;
        }
    }
}


