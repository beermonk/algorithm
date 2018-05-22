//
// Created by mengjiale on 2018/5/21.
//

#include <iostream>
#include <vector>

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
private:
    void preOrder(TreeNode *root, std::vector<int> &path, std::vector<std::vector<int>> &result)
    {
        if (root == NULL) {
            return;
        }

        path.push_back(root->value);

        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
        }

        preOrder(root->left, path, result);
        preOrder(root->right, path, result);

        path.pop_back();

    }

public:
    void findPath(TreeNode *root)
    {
        std::vector<std::vector<int>> result;  // 存放所有的路径的变量
        std::vector<int> path;
        preOrder(root, path, result);
        for (auto i : result) {
            for (auto j : i) {
                std::cout << j << "\t";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode i(5);
    TreeNode j(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &i;
    f.right = &j;
    Solution solve;
    solve.findPath(&a);
}