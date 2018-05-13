//
// Created by mengjiale on 2018/5/12.
//
#include <iostream>

struct ListNode {
    int value;
    ListNode *next;

    ListNode(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class Solution {
public:
    ListNode *partition(ListNode *head, int index)
    {
        // 使用两个临时头结点, 一个作为大于index的节点的头结点，一个作为小于index的节点的头结点
        ListNode less_head(0);
        ListNode more_head(0);
        ListNode* less_ptr = &less_head;
        ListNode* more_ptr = &more_head;
        // 遍历初始链表，遇到值大于index的就将该节点挂到more_head的后面
        while (head) {
            if (head->value < index) {
                less_ptr->next = head;
                less_ptr = head;
            }
            else {
                more_ptr->next = head;
                more_ptr = head;
            }
            head = head->next;
        }
        // 将more_head 挂到 less_head后面
        less_ptr->next = more_head.next;
        more_ptr->next = NULL;
        return less_head.next;
    }
};

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);

    ListNode *head = &a;
    a.next = &c;
    b.next = &e;
    c.next = &g;
    d.next = &f;
    e.next = NULL;
    f.next = &b;
    g.next = &d;
    while (head) {
        std::cout << head->value << "\t";
        head = head->next;
    }
    std::cout << std::endl;
    head = &a;
    Solution solu;
    ListNode *res = solu.partition(head, 4);
    while (res) {
        std::cout << res->value << "\t";
        res = res->next;
    }
    std::cout << std::endl;

}
