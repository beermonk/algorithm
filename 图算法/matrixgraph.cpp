// Created by mengjiale on 2018/4/16.
/*
 *邻接矩阵存储图
 *使用两个数组来存储，一个一维数组用来存储顶点，一个二维数组用来保存边
 * */
#include <iostream>
using namespace std;

#define MAXVEX 100
#define INFINITY 65535  // 表示权值的无穷大

typedef int EdgeType;
typedef char VertexType;

typedef struct {
    VertexType vexs[MAXVEX]; // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];  // 邻接矩阵可以看成边表
    int numNodes, numEdges;  // 顶点数和边数
} MGraph;

/*创建无向图的邻接矩阵表示*/
void CreateMGraph(MGraph *Gp)
{
    int i, j, k, w;
    cout << "请输入顶点和边的个数" << endl;
    cin >> Gp->numNodes >> Gp->numEdges;
    cout << "请输入顶点信息" << endl;
    for (i = 0; i < Gp->numNodes; i++) {
        cin >> Gp->vexs[i];
    }
    for (i = 0; i < Gp->numNodes; i++) {
        for (j = 0; j < Gp->numNodes; j++) {
            if (i == j) {
                Gp->arc[i][j] = 0;  // 该顶点没有到自己的边
            }
            else {
                Gp->arc[i][j] = INFINITY; // 权重初始化
            }
        }
    }
    for (k = 0; k < Gp->numEdges; k++)
    {
        cout << "请输入边（vi, vj)的上标i，下标j和权值w（空格分隔）:" << endl;
        cin >> i >> j >> w;
        Gp->arc[i][j] = w;
        Gp->arc[j][i] = Gp->arc[i][j];/* 因为是无向图，矩阵对称 */
    }
}

/*创建图的邻接表表示*/
int main(void)
{
    MGraph MG;
    CreateMGraph(&MG);
    return 0;
}
