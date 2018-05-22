#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {}

    TreeNode(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// 二叉树遍历的非递归实现
void preOrder(TreeNode *root, vector<int> &path)
{
    stack<pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while (!s.empty()) {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if (root == NULL)
            continue;
        if (visited) {
            path.push_back(root->value);
        }
        else {
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
            s.push(make_pair(root, true));
        }
    }
}

// 二叉树的先序遍历, 递归实现
void preTraverse(TreeNode *t)
{
    if (t != NULL) {
        cout << t->value << "\t";
        preTraverse(t->left);
        preTraverse(t->right);
    }
}

/**
 * 二叉树的按层遍历, 使用queue
 * 1. 使用两个变量last表示正在打印的当前行的最右节点，nlast表示下一行的最右节点
 * 2. 如何更新last和nlast，只需记录最先加入到队列的节点
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
        // 根节点出队列, 同时左右孩子节点入队列
        std::cout << q.front()->value << std::endl;
        if (q.front()->left != NULL) {
            q.push(q.front()->left);
            nlast = q.front()->left;
        }

        if (q.front()->right != NULL) {
            q.push(q.front()->right);
            nlast = q.front()->right;
        }
        if (q.front() == last) {
            std::cout << std::endl;
            last = nlast;
        }
        q.pop();
    }
}

int main()
{
    TreeNode a(10);
    TreeNode b(20);
    TreeNode c(30);
    TreeNode d(40);
    TreeNode e(50);
    TreeNode f(60);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    e.left = &f;
    /*
    preTraverse(&a);
    cout << endl;
    vector<int> res;
    preOrder(&a, res);
    for (auto i:res) {
        cout << i << "\t";
    }
    cout << endl;
     */
    printNodeByLevel(&a);


    return 0;
}

