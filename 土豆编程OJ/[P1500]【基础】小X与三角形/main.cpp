#include <iostream>
using namespace std;

int countTriangles(int a, int b) {
	int cMin = abs(a - b) + 1; // 第三条边的最小长度
	int cMax = a + b - 1; // 第三条边的最大长度
	
	return cMax - cMin + 1; // 不同的三角形种类数
}

int main() {
	int a, b;
	cin >> a >> b;
	
	int result = countTriangles(a, b);
	cout <<  result << endl;
	
	return 0;
}
