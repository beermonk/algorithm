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
        void preOrder(TreeNode *root)
        {
            if (root == NULL) {
                return;
            }
            std::cout << root->value << std::endl;
            preOrder(root->left);
            preOrder(root->right);
        }

        void preOrder1(TreeNode *root)
        {
            std::stack<TreeNode*> stack;

            stack.push(root);  // 根节点入栈

            while (!stack.empty()) {
                TreeNode *temp = stack.top();
                std::cout << temp->value << std::endl;
                stack.pop();

                if (temp->right != NULL) {
                    stack.push(temp->right);
                }
                if (temp->left != NULL) {
                    stack.push(temp->left);
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
    solution.preOrder(&a);
    solution.preOrder1(&a);
}

