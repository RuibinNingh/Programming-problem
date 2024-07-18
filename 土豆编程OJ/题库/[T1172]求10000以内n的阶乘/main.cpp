#include <iostream>
#include <vector>
using namespace std;

vector<int> num_result;

// 大整数乘法
void multiply(int n) {
	num_result.push_back(1); // 初始化结果为1
	
	// 执行乘法操作，模拟手工竖式计算
	for (int i = 2; i <= n; ++i) {
		int carry = 0; // 进位
		for (int j = 0; j < num_result.size(); ++j) {
			int product = num_result[j] * i + carry;
			num_result[j] = product % 10; // 更新当前位置的值
			carry = product / 10; // 计算进位
		}
		// 处理剩余的进位
		while (carry > 0) {
			num_result.push_back(carry % 10);
			carry /= 10;
		}
	}
}

// 输出结果
void print_result() {
	// 从高位到低位输出结果数组
	for (int i = num_result.size() - 1; i >= 0; --i)
		cout << num_result[i];
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	
	multiply(n);
	print_result();
	
	return 0;
}
