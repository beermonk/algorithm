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
        vector<int> LayerOrder(TreeNode *root)
        {
            queue<TreeNode*> q;
            vector<int> v;

            queue.push(root->value); // 根节点入队列
            while (!queue.empty()) {
                TreeNode *temp = q.front();
                v.push_back(temp->value);
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            return v;
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
    solution.LayerOrder(&a);
}

