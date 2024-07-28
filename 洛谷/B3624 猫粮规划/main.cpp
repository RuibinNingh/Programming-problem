#include<bits/stdc++.h>
using namespace std;
int n, l, r;
vector<int> w;
int DFS(int first, int nl) {
	int may = 0; // 多少种可能
	for (int i = first; i < n; i++) {
		int new_nl = nl + w[i];
		if (new_nl >= l && new_nl <= r)may += 1; // 如果能量在区间内，增加一种可能
		if (new_nl < r)may += DFS(i + 1, new_nl); // 继续搜索
	}
	return may; // 返回有多少种可能
}
int main() {
	cin >>n>>l>>r;
	w.resize(n);
	for (int i = 0; i < n; i++)cin >> w[i];
	cout << DFS(0, 0);
}
