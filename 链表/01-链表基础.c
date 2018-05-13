#include <stdio.h>

// 定义链表的节点
typedef struct ListNode{
    int value;
    struct ListNode *next;
}ListNode;

int main(void)
{
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;

    a.value = 10;
    b.value = 20;
    c.value = 30;
    d.value = 40;
    e.value = 50;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    ListNode *head = &a;
    while (head) {
        printf("%d\n", head->value);
        head = head->next;
    }

    return 0;
}
