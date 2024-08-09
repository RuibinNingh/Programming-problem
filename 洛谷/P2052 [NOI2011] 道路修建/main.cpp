#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 10000010;

// 定义全局变量
ll total_nodes, edge_count, total_cost;
// 定义子树大小数组和头节点数组
ll subtree_size[maxn], head[maxn];

// 定义边结构体
struct Edge {
    int weight, destination, next;
} edges[maxn * 2];

// 添加边函数
void add_edge(int source, int destination, int weight) {
    edge_count++;
    edges[edge_count].destination = destination;
    edges[edge_count].next = head[source];
    edges[edge_count].weight = weight;
    head[source] = edge_count;
}

// 深度优先搜索函数
void depth_first_search(int current_node, int parent_node) {
    // 初始化当前节点的子树大小为1
    subtree_size[current_node] = 1;
    // 遍历当前节点的所有邻接节点
    for (int i = head[current_node]; i; i = edges[i].next) {
        int neighbor = edges[i].destination;
        // 如果邻接节点是父节点，则跳过
        if (neighbor == parent_node) continue;
        // 递归调用深度优先搜索函数
        depth_first_search(neighbor, current_node);
        // 更新当前节点的子树大小
        subtree_size[current_node] += subtree_size[neighbor];
        // 更新总成本
        total_cost += edges[i].weight * abs(2 * subtree_size[neighbor] - total_nodes);
    }
}

int main() {
    // 输入节点总数
    cin >> total_nodes;
    // 输入边的信息
    for (int i = 1; i < total_nodes; i++) {
        int start_node, end_node, weight;
        scanf("%d%d%d", &start_node, &end_node, &weight);
        // 添加边
        add_edge(start_node, end_node, weight);
        add_edge(end_node, start_node, weight);
    }
    // 从节点1开始进行深度优先搜索
    depth_first_search(1, 0);
    // 输出总成本
    cout << total_cost << endl;
    return 0;
}
