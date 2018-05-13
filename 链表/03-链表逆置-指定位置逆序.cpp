#include <iostream>

using namespace std;

// 定义链表的结构
struct ListNode {
    // 数据域
    int value;
    ListNode* next;

    // 构造函数
    ListNode(int x): value(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head, int m, int n)  // 返回链表逆序后头结点的指针
        {
            int change_len = n - m + 1; // 计算需要逆置的节点的个数
            ListNode *pre_head = NULL; // 初始化开始逆置的节点的前驱
            ListNode *result = head; // 最终转化后的链表头节点
            // 步骤1：找到开始逆置的节点和该节点的前驱节点
            while (head && --m) {
                pre_head = head;  // 开始逆置的节点的前驱节点
                head = head->next; // 开始逆置的节点
            }
            // 步骤2：从head开始，逆置change_len个节点
            // 将modify_list_tail 指向当前的head,即逆置后的链表尾
            ListNode *modify_list_tail = head;
            ListNode *new_head = NULL;
            // 逆置change_len个节点
            while (head && change_len) {
                ListNode *next = head->next; 
                head->next = new_head;
                new_head = head;
                head = next;
                change_len--;
            }
            // 步骤3：将pre_head与new_head连接，modify_list_tail与head连接
            modify_list_tail->next = head;
            if (pre_head) {
                pre_head->next = new_head;
            }
            else {
                result = new_head;
            }

            return result;
        }
};

int main()
{
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    ListNode *head = &a;
    cout << "逆置之前：";
    while (head) {
        cout << head->value << "\t";
        head = head->next;
    }
    cout << endl;
    Solution s;
    ListNode *res = s.reverseList(&a, 2, 4);
    cout << "逆置之后：";
    while(res) {
        cout << res->value << "\t";
        res = res->next;
    }
    cout << endl;
    return 0;
}
