#include <bits/stdc++.h>
using namespace std;
bool isPrime(int a) {
	if (a < 2) return false; // 小于2的数不是素数
	for (int i = 2; i * i <= a; ++i)if (a % i == 0) return false;
	return true; // 否则是素数
}
void findCombinations(vector<int>& nums, int k, int start, int currentSum, int& count) {
	if (k == 0) { // 如果已经选择了k个数
		if (isPrime(currentSum)) { // 判断当前的和是否为素数
			count++; // 如果是素数，计数加1
		}
		return;
	}
	for (int i = start; i < nums.size(); i++)findCombinations(nums, k - 1, i + 1, currentSum + nums[i], count);
}
int main() {
	int n, k;
	cin >> n >> k; // 输入n和k
	vector<int> nums(n); // 定义一个大小为n的数组
	for (int i = 0; i < n; i++) cin >> nums[i]; // 输入数组元素
	int count = 0; // 用于计数和为素数的组合数量
	findCombinations(nums, k, 0, 0, count); // 调用递归函数
	cout << count; // 输出结果
	return 0;
}

