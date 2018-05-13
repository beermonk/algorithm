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
        ListNode* reverseList(ListNode* head)  // 返回链表逆序后头结点的指针
        {
            ListNode* new_head = NULL;

            while (head) {
                // 保留旧链表head指向的节点的下一个节点
                ListNode* next = head->next;
                // 将head指向的节点的next指向new_head
                head->next = new_head;
                // 将新链表的new_head指向新插入的节点
                new_head = head;
                // 遍历链表
                head = next;
            }
            return new_head;
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
    ListNode* res = s.reverseList(&a);
    cout << "逆置之后：";
    while(res) {
        cout << res->value << "\t";
        res = res->next;
    }
    cout << endl;
    return 0;
}
