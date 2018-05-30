//
// Created by mengjiale on 2018/5/24.
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
private:
    /**
     * 将整数转化为字符串
     */
    void changeIntToString(int val, std::string &strVal)
    {
        std::string temp;
        while(val) {
            temp += val % 10 + '0';
            val = val / 10;
        }
        // 逆序temp，写入strVal
        for (int i = temp.length() - 1; i >= 0; i--) {
            strVal += temp[i];
        }
        strVal += '#';
    }
public:
    /**
     * 二叉查找树按层遍历
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

    /**
     * 二叉查找树插入节点
     */
    void insertNode(TreeNode *root, TreeNode *node)
    {
        if (node->value < root->value) {  // 如果待插入的节点的值小于此时访问到的节点的值, 说明要在此时访问的节点的左子树进行操作
            if (root->left) {  // 如果左子树不为空, 就继续访问左子树
                insertNode(root->left, node);
            }
            else {  // 如果左子树为空，直接将待插入的节点插入
                root->left = node;
            }
        }
        else {
            if (root->right) {
                insertNode(root->right, node);
            }
            else {
                root->right = node;
            }
        }
    }

    /**
     * 二叉查找树查找操作
     */
    bool searchNode(TreeNode *root, int target)
    {
        if (root->value == target) {
            return true;
        }
        if (root->value > target) {  // 左子树
            if (!root->left)  {
                return false;
            }
            else {
                searchNode(root->left, target);
            }
        }
        if (root->value < target) {  // 右子树
            if (!root->right) {
                return false;
            }
            else {
                searchNode(root->right, target);
            }
        }
    }
    /**
     * 二叉查找树的前序遍历与复原
     */
    void preOrder(TreeNode *root, std::string &data)
    {
        if (!root) {
            return;
        }
        std::string strValue;
        changeIntToString(root->value, strValue);
        data += strValue;
        preOrder(root->left, data);
        preOrder(root->right, data);
    }
};


int main()
{
    TreeNode a(1);
    TreeNode b(3);
    TreeNode c(6);
    TreeNode d(8);
    TreeNode e(10);
    TreeNode f(15);
    b.left = &a;
    b.right = &c;
    d.right = &e;
    d.left = &b;
    e.right = &f;

    Solution solve;
//    std::cout << "未插入节点之前" << ":  " << std::endl;
//    solve.printNodeByLevel(&d);
//    TreeNode g(5);
//    solve.insertNode(&d, &g);
//    std::cout << "插入节点之后" << ":  " << std::endl;
//    solve.printNodeByLevel(&d);
//    bool res = solve.searchNode(&d, 20);
//    std::cout << res << std::endl;
    std::string res;
    solve.preOrder(&d, res);
    std::cout << res << std::endl;
}