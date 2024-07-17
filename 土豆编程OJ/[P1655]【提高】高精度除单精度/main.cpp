#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string a;
	int b;
	cin >> a >> b;
	
	vector<int> result;
	int remainder = 0;
	
	for (char digit : a) {
		int num = remainder * 10 + (digit - '0');
		result.push_back(num / b);
		remainder = num % b;
	}
	
	// 跳过前导零
	int i = 0;
	while (i < result.size() && result[i] == 0) {
		i++;
	}
	
	// 输出结果
	if (i == result.size()) {
		cout << 0 << endl; // 如果结果全部是0，输出0
	} else {
		for (; i < result.size(); i++) {
			cout << result[i];
		}
		cout << endl;
	}
	
	return 0;
}

