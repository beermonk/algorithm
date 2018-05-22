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
    void preOrder(TreeNode *root, TreeNode *target, std::vector<TreeNode *> &path, std::vector<TreeNode *> &result,
                  int &finish)
    {
        if (root == NULL || finish == 1)
            return;

        path.push_back(root);  // 先序遍历节点入栈

        if (root == target) {  // 找到目标节点
            finish = 1;
            result = path;
        }

        preOrder(root->left, target, path, result, finish);
        preOrder(root->right, target, path, result, finish);

        path.pop_back();
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        std::vector<TreeNode *> p_path;  // 寻找从根节点到p节点的路径
        std::vector<TreeNode *> q_path;  // 寻找从根节点到q节点的路径
        std::vector<TreeNode *> result1;
        std::vector<TreeNode *> result2;
        int finish = 0;

        preOrder(root, p, p_path, result1, finish);  // p节点的路径
        for (auto path : result1) {
            std::cout << path->value << "\t";
        }
        finish = 0;
        std::cout << std::endl;
        preOrder(root, q, q_path, result2, finish);  // q节点的路径
        for (auto path : result2) {
            std::cout << path->value << "\t";
        }
        std::cout << std::endl;
        // 两个路径上最后一个相同的点即为最近公共祖先
        int min = result1.size() < result2.size() ? result1.size() : result2.size();
        TreeNode* res = 0;
        for (int i = 0; i < min; i++) {
            if (result1[i] == result2[i]) {
                res = result1[i];
            }
        }
        return res;
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
    TreeNode *res = solve.lowestCommonAncestor(&a, &e, &j);
    std::cout << res->value << std::endl;
}
