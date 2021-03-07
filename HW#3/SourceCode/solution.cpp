#include "solution.h"
#include <queue>
#include <fstream>
using namespace std;

/* Fill free to implement any function on here */
unsigned long long int result;
unsigned long long int temp;

void leafSearch(TreeNode *node)
{
    if (node->left != NULL)
    {
        temp = temp * 10 + node->val;
        leafSearch(node->left);
        if (node->right != NULL)
            leafSearch(node->right);
        temp = temp / 10;
    }
    else
        result += node->val + temp * 10;
}

unsigned long long int Solution::getPathSum(struct TreeNode *root)
{
    /* Fill up with your own codes */
    result = temp = 0;
    leafSearch(root);
    return result;
}

struct TreeNode *Solution::buildTree(string filename)
{
    /* Fill up with your own codes */
    int n = 0;
    TreeNode *root = new TreeNode;
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> n;
        n -= 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            ifs >> front->val;
            if (n > 0)
            {
                front->left = new TreeNode;
                q.push(front->left);
                --n;
            }
            else
                front->left = NULL;

            if (n > 0)
            {
                front->right = new TreeNode;
                q.push(front->right);
                --n;
            }
            else
                front->right = NULL;
        }
    }
    return root;
}