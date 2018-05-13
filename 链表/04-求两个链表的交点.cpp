//
// Created by mengjiale on 2018/5/11.
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
    /**
     * 方法1：使用set，将链表A的节点地址插入到set中，然后将B中节点地址在set中查找
     * @param headA
     * @param headB
     * @return
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *intersectionNode;
        set<ListNode *> node_set;
        // 将链表A中的地址插入set中
        while (headA)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (node_set.find(headB) != node_set.end())
            {
                cout << "找到了" << endl;
                return headB;
            }
            headB = headB->next;
        }
        return NULL;

    }

    /**
     * 获取链表的节点的个数
     * @param head
     * @return
     */
    int getLinkListLength(ListNode *head)
    {
        int length = 0;
        while (head)
        {
            length++;
            head = head->next;
        }
        return length;
    }

    /**
     * @param1: 为较长链表的长度
     * @param2: 为较短链表的长度
     * @param3: 为较长链表的头结点
     * return  返回两个节点对齐的位置
     * */
    ListNode *forward_long_list(int long_len, int short_len, ListNode *head)
    {
        int delta = long_len - short_len;
        while (head && delta)
        {
            head = head->next;
            delta--;
        }

        return head;
    }

    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
    {
        ListNode *a = NULL;
        int lengthA = getLinkListLength(headA);
        int lengthB = getLinkListLength(headB);
        if (lengthA > lengthB)
        {
            ListNode *headA = forward_long_list(lengthA, lengthB, headA);
        }
        else
        {
            ListNode *headB = forward_long_list(lengthB, lengthA, headB);
        }
        while (headA && headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
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

    ListNode *headA = &a;
    a.next = &c;
    c.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = NULL;

    ListNode *headB = &b;
    b.next = &d;
    d.next = &e;
    while (headA)
    {
        cout << headA->value << "\t";
        headA = headA->next;
    }
    cout << endl;
    while (headB)
    {

        cout << headB->value << "\t";
        headB = headB->next;
    }
    cout << endl;
    Solution solu;
    ListNode *res = solu.getIntersectionNode1(&a, &b);
    cout << res->value << endl;
    return 0;
}

