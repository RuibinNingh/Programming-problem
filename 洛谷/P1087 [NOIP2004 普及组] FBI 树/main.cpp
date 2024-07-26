#include <iostream>
#include <string>
using namespace std;

// 判断字符串的类型：B, I, 或 F
char judgeType(const string &s) {
	bool has0 = false, has1 = false;
	for (char c : s) {
		if (c == '0') has0 = true;
		if (c == '1') has1 = true;
	}
	if (has0 && has1) return 'F';
	else if (has0) return 'B';
	else return 'I';
}

// 递归构造FBI树并进行后序遍历
void constructFBITree(const string &s, string &result) {
	if (s.size() == 1) {
		result += judgeType(s);
		return;
	}
	
	int mid = s.size() / 2;
	string left = s.substr(0, mid);
	string right = s.substr(mid);
	
	constructFBITree(left, result);
	constructFBITree(right, result);
	result += judgeType(s);
}

int main() {
	int n;
	string s;
	
	cin >> n;
	cin >> s;
	
	string result;
	constructFBITree(s, result);
	
	cout << result << endl;
	
	return 0;
}

