#include <iostream>

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
        int Depth(TreeNode *root)
        {
            if (root == NULL) {
                return 0;
            }
            return max(Depth(root->left), Depth(root->right)) + 1;
        }

        int max(int a, int b)
        {
            if (a >= b) {
                return a;
            }
            else {
                return b;
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
    int depth = solution.Depth(&a);
    std::cout << depth << std::endl;
}

