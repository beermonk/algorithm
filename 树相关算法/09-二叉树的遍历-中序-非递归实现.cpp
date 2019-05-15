#include <iostream>
#include <stack>

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
    public:
        void midOrder(TreeNode *root)
        {
            if (root == NULL) {
                return;
            }

            midOrder(root->left);
            std::cout << root->value << std::endl;
            midOrder(root->right);
        }

        void midOrder1(TreeNode *root)
        {
            std::stack<TreeNode*> stack;

            while (!stack.empty() || root != NULL) {
                if (root != NULL) {
                    stack.push(root);  // 不停的把左子树压入栈中
                    root = root->left;
                }
                else {
                    root = stack.top();
                    stack.pop();
                    std::cout << root->value << std::endl;
                    root = root->right;
                }
            } 

        }
};



int main()
{
    TreeNode a(1);
    TreeNode b(3);
    TreeNode c(2);
    TreeNode d(8);
    TreeNode e(7);
    TreeNode f(5);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    e.left = &f;

    Solution solution;
    solution.midOrder(&a);
    solution.midOrder1(&a);
}

