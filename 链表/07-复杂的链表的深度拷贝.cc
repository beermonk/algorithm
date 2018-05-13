//
// Created by mengjiale on 2018/5/12.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct RandomListNode {
    int value;
    RandomListNode *next, *random;

    RandomListNode(int value)
    {
        this->value = value;
        this->next = NULL;
        this->random = NULL;
    }
};

class Solution {
public:
    RandomListNode *deepCopy(RandomListNode *head)
    {
        std::map<RandomListNode *, int> node_map; // 原始链表节点到地址的映射
        std::vector<RandomListNode *> node_vector; // 新链表的节点的地址
        RandomListNode *ptr = head;
        int i = 0;
        while (ptr) {  // 将新链表节点存入node_vector中
            node_vector.push_back(new RandomListNode(ptr->value));
            node_map[ptr] = i;
            ptr = ptr->next;
            i++;
        }
        node_vector.push_back(0);
        ptr = head;
        i = 0;
        while (ptr) {  // 再次遍历原始链表，连接新链表的next指针和random指针
            node_vector[i]->next = node_vector[i + 1];
            if (ptr->random) {
                int id = node_map[ptr->random];
                node_vector[i]->random = node_vector[id];
            }
            ptr = ptr->next;
            i++;
        }
        return node_vector[0];
    }
};

int main()
{
    RandomListNode a(5);
    RandomListNode b(3);
    RandomListNode c(6);
    a.next = &b;
    b.next = &c;
    a.random = &c;
    b.random = &a;
    c.random = &c;

    Solution solution;
    RandomListNode *res = solution.deepCopy(&a);

}
