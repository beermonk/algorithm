//
// Created by mengjiale on 2018/5/12.
//
#include <iostream>
#include <set>

using namespace std;

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
    ListNode *detectCycle(ListNode *head)
    {
        set<ListNode *> my_set;
        while (head) {
            if (my_set.find(head) != my_set.end()) {
                cout << "找到了" << endl;
                return head;
            }
            my_set.insert(head);
            head = head->next;
        }
        cout << "没找到" << endl;
        return NULL;
    }

    ListNode *detectCycle2(ListNode *head)
    {
        ListNode *slow, *fast = head;
        ListNode *meet = NULL;
        while (fast) {  // 如果有环的话，找到fast和slow的交点
            slow = slow->next;
            fast = fast->next;
            if (!fast) {
                return NULL;
            }
            fast = fast->next;
            if (fast == slow) {  // 找fast和slow的交点
                meet = fast;
                break;
            }
        }

        if (meet == NULL) {  // 如果没有交点说明没有环
            return NULL;
        }
        while (head && meet) {  // 有环，然后让meet和head同时出发，指针速度一样，相遇即为环的起点
            if (head == meet) {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }

        return NULL;
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
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &d;

    /*
    int n = 7;
    while (head && n)
    {
        cout << head->value << endl;
        head = head->next;
        n--;
    }
     */
    Solution sol;
//    ListNode *res = sol.detctCycle(head);
//    cout << res->value << endl;
    ListNode *res2 = sol.detectCycle2(head);
    cout << "找到了: " << res2->value << endl;
}
