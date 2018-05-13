//
// Created by mengjiale on 2018/5/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int value;
    ListNode *next;

    ListNode(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

bool cmp(const ListNode *a, const ListNode *b)
{
    return a->value > b->value;
}

class Solution {
public:
    ListNode *merge1(std::vector<ListNode *> &head_vector)
    {
        std::vector<ListNode *> node_vec;
        for (int i = 0; i < head_vector.size(); i++) {
            ListNode *head = head_vector[i]; // 将所有的节点放入vector
            while (head) {
                node_vec.push_back(head);
                head = head->next;
            }
            if (node_vec.size() == 0) {
                return NULL;
            }
        }
        std::sort(node_vec.begin(), node_vec.end(), cmp);  // 将vector中的节点全部排序
        // 将排序后的节点重新连接
        for (int i = 0; i < node_vec.size(); i++) {
            node_vec[i] = node_vec[i]->next;
        }
        node_vec[node_vec.size() - 1]->next = NULL;

        return node_vec[0];
    }

    /**
     * 分治方法实现k各有序链表的合并
     * @param head_vector
     * @return
     */
    ListNode *merge2(std::vector<ListNode *> &head_vector)
    {
        if (head_vector.size() == 0) {
            return NULL;
        }
        if (head_vector.size() == 1) {
            return head_vector[0];
        }
        if (head_vector.size() == 2) {
            return mergeTwoList(head_vector[0], head_vector[1]);
        }
        int mid = head_vector.size() / 2;
        std::vector<ListNode*> sub1_lists;
        std::vector<ListNode*> sub2_lists;
        for (int i = 0; i < mid; i++) {
            sub1_lists.push_back(head_vector[i]);
        }
        for (int i = mid;i < head_vector.size(); i++) {
            sub2_lists.push_back(head_vector[i]);
        }

        ListNode* l1 = merge2(sub1_lists);
        ListNode* l2 = merge2(sub2_lists);

        return mergeTwoList(l1, l2);
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
}