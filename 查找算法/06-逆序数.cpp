//
// Created by mengjiale on 2018/5/25.
//
#include <iostream>
#include <vector>

struct BSTNode {
    int value;
    int count;  // count记录该节点的左子树的节点个数, 在构建二叉树的时候如果待插入的节点值小于当前节点值count++就可以
    BSTNode *left;
    BSTNode *right;

    BSTNode(int val)
    {
        this->value = val;
        this->count = 0;
        this->right = NULL;
        this->left = NULL;
    }
};

class Solution {
private:
    void insertNode(BSTNode *root, BSTNode *node, int &count_small)
    {
        if (node->value <= root->value) {  // 如果待插入的节点的值小于此时访问到的节点的值, 说明要在此时访问的节点的左子树进行操作
            root->count++;
            if (root->left) {  // 如果左子树不为空, 就继续访问左子树
                insertNode(root->left, node, count_small);
            }
            else {  // 如果左子树为空，直接将待插入的节点插入
                root->left = node;
            }
        }
        else {
            count_small = root->count + 1;
            if (root->right) {
                insertNode(root->right, node, count_small);
            }
            else {
                root->right = node;
            }
        }
    }
};

int main()
{
    std::vector<int> num{1, -2, 5, 3, 1, 9, -7, 5};
}
