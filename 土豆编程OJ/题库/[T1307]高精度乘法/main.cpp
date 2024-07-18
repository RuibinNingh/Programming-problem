#include <iostream>
#include <vector>
using namespace std;

vector<int> num_a, num_b, num_result;

// 读取输入并将字符串数字转换为整数数组
void read() {
	string a, b;
	cin >> a >> b;
	// 将字符串逆序存入 num_a 和 num_b 数组中，数字字符转换为对应的整数
	for (int i = a.size() - 1; i >= 0; --i)
		num_a.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; --i)
		num_b.push_back(b[i] - '0');
}

// 大整数乘法
void multiply() {
	int m = num_a.size();
	int n = num_b.size();
	// 结果数组初始化为长度为 m+n，初始值为 0
	num_result.resize(m + n, 0);
	
	// 执行乘法操作，模拟手工竖式计算
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int product = num_a[i] * num_b[j];
			// 将乘积加到对应的位置
			num_result[i + j] += product;
			// 处理进位
			num_result[i + j + 1] += num_result[i + j] / 10;
			num_result[i + j] %= 10;
		}
	}
	
	// 去除结果数组前导零
	while (num_result.size() > 1 && num_result.back() == 0)
		num_result.pop_back();
}

// 输出结果
void print_result() {
	// 从高位到低位输出结果数组
	for (int i = num_result.size() - 1; i >= 0; --i)
		cout << num_result[i];
	cout << endl;
}

int main() {
	read();
	multiply();
	print_result();
	return 0;
}
