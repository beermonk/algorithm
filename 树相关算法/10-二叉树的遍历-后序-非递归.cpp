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

        void posOrder(TreeNode *root)
        {
            std::stack<TreeNode*> s1;
            std::stack<TreeNode*> s2;

            s1.push(root);

            while (!s1.empty()) {
                root = s1.top();
                s1.pop();
                s2.push(root);
                if (root->left != NULL) {
                    s1.push(root->left);
                }
                if (root->right != NULL) {
                    s1.push(root->right);
                }
            }

            while (!s2.empty()) {
                root = s2.top();
                std::cout << root->value << "\t";
                s2.pop();
            }
            std::cout << std::endl;
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
    solution.posOrder(&a);
}

