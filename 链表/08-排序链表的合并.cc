//
// Created by mengjiale on 2018/5/13.
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
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode temp_head(0);  // 建立一个临时头结点
        ListNode *ptr = &temp_head;
        // 遍历两个链表，将比较小的节点挂在新的链表的后面
        while (head1 && head2) {
            if (head1->value > head2->value) {
                ptr->next = head2;
                head2 = head2->next;
            }
            else {
                ptr->next = head1;
                head1 = head1->next;
            }
            ptr = ptr->next;
        }
        if (head1) {  // head1链表有剩余
            ptr->next = head1;
        }
        if (head2) {  // head2链表有剩余
            ptr->next = head2;
        }
        return temp_head.next;
    }
};

int main()
{
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);

    ListNode d(0);
    ListNode e(5);
    ListNode f(7);

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    d.next = &e;
    e.next = &f;
    f.next = NULL;

    Solution solu;
    ListNode *head = solu.merge(&a, &d);
    while (head) {
        std::cout << head->value <<  "\t";
        head = head->next;
    }
    std::cout << std::endl;
}