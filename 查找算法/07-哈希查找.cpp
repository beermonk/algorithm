//
// Created by mengjiale on 2018/5/25.
//
#include <iostream>
#include <vector>
#include <map>

struct ListNode {
    int value;
    ListNode *next;

    ListNode(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

/**
 * 基础知识：stl map
 */
void stlMapTest()
{
    std::map<std::string, int> hash_map;
    std::string str1 = "abc";
    std::string str2 = "aaaa";
    std::string str3 = "bbb";
    std::string str4 = "cccc";
    hash_map[str1] = 1;
    hash_map[str2] = 2;
    hash_map[str3] = 3;
    hash_map[str4] = 4;

    /*查找map中的元素*/
    if (hash_map.find(str1) != hash_map.end()) {
        std::cout << str1 << "....." << hash_map[str1] << std::endl;
    }

    /*遍历map*/
    for (std::map<std::string, int>::iterator it = hash_map.begin(); it != hash_map.end(); it++) {
        std::cout << it->first << it->second << std::endl;
    }
    for (auto i : hash_map) {  // c++11 遍历map的方法
        std::cout << i.first << i.second << std::endl;
    }
}

int hash_func(int key, int talbe_len)
{
    return key % talbe_len;
}

/**
 * 向hash表中插入数据
 * @param hash_talbe
 * @param node
 * @param table_len
 */
void insertIntoHashTable(ListNode *hash_talbe[], ListNode *node, int table_len)
{
    // 首先对节点进行hash计算
    int address = hash_func(node->value, table_len);
    node->next = hash_talbe[address]->next;
    hash_talbe[address]->next = node;
}

/**
 * 使用hash表进行查找
 * @return
 */
bool searchHashTable(ListNode *hash_table[], int value, int table_len)
{
    int address = hash_func(value, table_len);
    ListNode *head = hash_table[address];
    while (head) {
        if (head->value == value) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int main()
{
    /*
    // 定义一个hash表
    ListNode *hash_table[11] = {NULL};
    std::vector<int> num{1, 1, 4, 9, 20, 30, 150, 500};
    std::vector<ListNode *> hash_node_vec;
    for (int i = 0; i < num.size(); i++) {
        hash_node_vec.push_back(new ListNode(num[i]));
    }
    // 将节点插入hash表
    for (int i = 0; i < hash_node_vec.size(); i++) {
        insertIntoHashTable(hash_table, hash_node_vec[i], 11);
    }
    // 遍历hash表
    for (int i = 0; i < 11; i++) {
        std::cout << '[' << i << ']: ';
        ListNode *head = hash_table[i];
        while (head) {
            std::cout << head->value << '\t';
            head = head->next;
        }
    }
    */
    stlMapTest();
}

