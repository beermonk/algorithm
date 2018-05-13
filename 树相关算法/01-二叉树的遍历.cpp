#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){}
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
    stack< pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            path.push_back(root->value);
        }
        else
        {
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
            s.push(make_pair(root, true));
        }
    }
}

// 二叉树的先序遍历, 递归实现
void preTraverse(TreeNode *t)
{
    if (t != NULL)
    {
        cout << t->value << "\t";
        preTraverse(t->left);
        preTraverse(t->right);
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

    preTraverse(&a);
    cout << endl;
    vector<int> res;
    preOrder(&a, res);
    for (auto i:res) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}

