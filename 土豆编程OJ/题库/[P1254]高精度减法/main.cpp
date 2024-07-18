#include <iostream>
#include <string>
#include <algorithm> // 用于字符串反转
using namespace std;

int main() {
	// 读取两个大数
	string a, b;
	cin >> a >> b;
	
	// 标记结果是否为负数
	bool isNegative = false;
	
	// 确保a始终是较大的数
	if (a < b) {
		swap(a, b);
		isNegative = true; // 如果交换了，结果是负数
	}
	
	// 反转字符串以便从最低位开始计算
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	// 补齐b的长度，使其与a等长
	while (b.length() < a.length()) {
		b.push_back('0');
	}
	
	string result = "";
	int carry = 0; // 借位
	
	// 从最低位开始逐位相减
	for (size_t i = 0; i < a.length(); ++i) {
		int digitA = a[i] - '0'; // 将字符转换为数字
		int digitB = b[i] - '0';
		
		int diff = digitA - digitB - carry;
		if (diff < 0) {
			diff += 10;
			carry = 1; // 借位
		} else {
			carry = 0;
		}
		
		result.push_back(diff + '0'); // 将数字转换为字符
	}
	
	// 去掉结果前面的零
	while (result.length() > 1 && result.back() == '0') {
		result.pop_back();
	}
	
	// 反转结果字符串
	reverse(result.begin(), result.end());
	
	// 如果结果是负数，添加负号
	if (isNegative) {
		cout << "-";
	}
	
	// 输出结果
	cout << result << endl;
	
	return 0;
}

