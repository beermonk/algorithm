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
    void preOrder(TreeNode *root, TreeNode *&last)
    {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            last = root;
            return;
        }
        // 备份左右指针
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        // 定义左右子树最后一个节点变量
        TreeNode *left_last = NULL;
        TreeNode *right_last = NULL;
        if (left) {  // 如果有左子树
            preOrder(left, left_last);
            root->left = NULL;
            root->right = left;
            last = left_last;
        }
        if (right) {  // 如果有右子树
            preOrder(right, right_last);
            if (left_last) {
                left_last->right = right;
            }
            last = right_last;
        }
    }

public:
    void flatten(TreeNode *root)
    {
        TreeNode *last = NULL;
        preOrder(root, last);
    }
};

int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    a.right = &e;
    b.left = &c;
    b.right = &d;
    e.right = &f;
    Solution solve;
    solve.flatten(&a);
    TreeNode *root = &a;
    while (root) {
        if (root->left) {
            std::cout << "error" << std::endl;
        }
        std::cout << root->value << "\t";
        root = root->right;
    }
}