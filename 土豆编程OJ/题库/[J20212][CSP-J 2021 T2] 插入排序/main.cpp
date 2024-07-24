#include <bits/stdc++.h> // 包含所有标准库
using namespace std;
int b[8005]; // 数组 b 用于记录每个元素在排序后的索引
struct node { 
	int a; // 存储元素的值
	int w; // 存储元素的原始位置
} a[8005]; // 数组 a 用于存储所有元素
int main() {
	int n, q; // n 表示元素的数量，q 表示操作的数量
	scanf("%d %d",&n,&q);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i].a);
		a[i].w = i; // 记录每个元素的原始位置
	}
	//插入排序
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 2; j--) {
			if (a[j].a < a[j - 1].a) { // 如果当前元素小于前一个元素
				swap(a[j], a[j - 1]); // 交换两个元素
			} else {
				break; // 如果当前元素不小于前一个元素，停止内层循环
			}
		}
	}
	// 记录每个元素在排序后的索引
	for (int i = 1; i <= n; i++) {
		b[a[i].w] = i; // b 数组记录元素原始位置对应的排序后索引
	}
	
	while(q--) {
		int op; 
		scanf("%d",&op);
		if (op == 1) { // 操作1：修改
			int x, v;
			scanf("%d %d",&x,&v); // 输入要修改的元素位置 x 和新值 v
			int k = b[x]; // 获取x位置元素在排序后的索引
			a[k].a = v; // 修改元素的值
			
			// 向后调整位置  (修改后，调整该数位置)
			for (int j = k; j < n; j++) {
				//注意稳定性
				if (a[j].a > a[j + 1].a || (a[j].a == a[j + 1].a && a[j].w > a[j + 1].w)) {
					swap(a[j], a[j + 1]); // 交换两个元素
					swap(b[a[j].w], b[a[j + 1].w]); // 更新 b 数组
				} else {
					break; // 如果不需要交换，停止内层循环
				}
			}
			
			// 向前调整位置
			for (int j = k; j >= 2; j--) {
				if (a[j].a < a[j - 1].a || (a[j].a == a[j - 1].a && a[j].w < a[j - 1].w)) {
					swap(a[j], a[j - 1]); // 交换两个元素
					swap(b[a[j].w], b[a[j - 1].w]); // 更新 b 数组
				} else {
					break; // 如果不需要交换，停止内层循环
				}
			}
		} else { // 操作2：查询
			int x;
			scanf("%d",&x); // 输入要查询的元素位置 x
			printf("%d\n",b[x]); // 输出元素 x 在排序后的索引
		}
	}
	return 0;
}
