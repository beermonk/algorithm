//
// Created by mengjiale on 2018/5/22.
//

#include <iostream>
#include <vector>

struct GraphNode {  // 图的邻接表表示的数据结构
    int label;  // 图的顶点的值
    std::vector<GraphNode *> neighbors;

    GraphNode(int label)
    {
        this->label = label;
    }
};

/**
 * 图的深度优先搜索
 */
void DFS_graph(GraphNode *node, int visit[])
{
    visit[node->label] = 1;  // 将节点标记为被访问过
    std::cout << node->label << "\t";
    for (int i = 0; i < node->neighbors.size(); i++) {
        if (visit[node->neighbors[i]->label] == 0) {
            DFS_graph(node->neighbors[i], visit);
        }
    }
}

int main()
{
    /**
     *
    // 邻接矩阵表示图
    const int MAX_N = 5;
    int Graph[MAX_N][MAX_N] = {0};
    Graph[0][2] = 1;
    Graph[0][4] = 1;
    Graph[1][0] = 1;
    Graph[1][2] = 1;
    Graph[2][3] = 1;
    Graph[3][4] = 1;
    Graph[4][3] = 1;

    std::cout << "Graph: " << std::endl;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            std::cout << Graph[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    */
    // 邻接表表示图
    const int MAX_N = 5;
    GraphNode *Graph[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        Graph[i] = new GraphNode(i);
    }
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[3]);

    int visit[MAX_N] = {0};
    for (int i = 0; i < MAX_N; i++) {
        if (visit[i] == 0) {  // 如果一个节点没有被访问
            std::cout << "From label " << Graph[i]->label << ": ";
            DFS_graph(Graph[0], visit);
            std::cout << std::endl;
        }
    }

    for (int i = 0; i < MAX_N; i++) {
        delete Graph[i];
    }
}