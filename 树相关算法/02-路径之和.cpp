//
// Created by mengjiale on 2018/5/19.
//

#include <iostream>
#include <vector>
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
private:
    void preOrder(TreeNode *root, std::vector<int> &s, int target, int &sum, std::vector<std::vector<int>> &res)
    {
        if (root == NULL) {
            return;
        }
        sum += root->value;  // 遍历一个节点更新一个路径值
        s.push_back(root->value);
        if (root->left == NULL && root->right == NULL && sum == target) {  // 当到达叶节点并且路径中的节点值之和与给定的值相等, 将路径添加到结果
            res.push_back(s);
        }
        preOrder(root->left, s, target, sum, res);
        preOrder(root->right, s, target, sum, res);

        sum -= root->value;
        s.pop_back();

    }

public:
    std::vector<std::vector<int>> pathSum(TreeNode *root, int target)
    {
        std::vector<int> s;  // 定义一个栈，用来存放路径
        std::vector<std::vector<int>> res;  // 定义结果的变量
        int sum = 0;  // 定义一个变量，用来统计栈中的元素的和是否与目标值相等

        preOrder(root, s, target, sum, res);
        return res;
    }
};

/**
 * 树的按层遍历
 * @param root
 */
void printNodeByLevel(TreeNode *root)
{
    TreeNode *last = NULL;
    TreeNode *nlast = NULL;
    last = root;
    std::queue<TreeNode *> q;

    // 根节点入队列
    q.push(root);
    while (!q.empty()) {
        // 根节点出队列
        std::cout << q.front()->value << "\t";
        // 左孩子入队列
        if (q.front()->left != NULL) {
            q.push(q.front()->left);
            nlast = q.front()->left;
        }
        // 右孩子入队列
        if (q.front()->right != NULL) {
            q.push(q.front()->right);
            nlast = q.front()->right;
        }
        // 到达一层的末尾，输出换行符
        if (q.front() == last) {
            std::cout << std::endl;
            last = nlast;
        }
        q.pop();
    }
}

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
    printNodeByLevel(&a);

    Solution solve;
    std::vector<std::vector<int>> result = solve.pathSum(&a, 22);
    for (auto i : result) {
        for (auto j : i) {
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
}