//
// Created by mengjiale on 2018/5/22.
//

#include <iostream>
#include <queue>

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
    std::vector<int> rightsideview(TreeNode *root)
    {
        std::queue<std::pair<TreeNode*, int>> Q;
        std::vector<int> view;
        if (root) {
            Q.push(std::make_pair(root, 0));
        }
        while (!Q.empty()) {
            TreeNode* node = Q.front().first;  // 当前访问的节点
            int depth = Q.front().second;  // 当前访问的节点的层数
            Q.pop();
            if (view.size() == depth) {
                view.push_back(node->value);
            }
            else {
                view[depth] = node->value;
            }
            if (node->left) {
                Q.push(std::make_pair(node->left, depth+1));
            }
            if (node->right) {
                Q.push(std::make_pair(node->right, depth+1));
            }
        }
        return view;
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
    a.right = &c;
    b.right = &e;
    c.right = &d;
    e.left = &f;

    Solution solve;
    std::vector<int> res;
    res = solve.rightsideview(&a);
    for (auto i : res) {
        std::cout << i << std::endl;
    }
}