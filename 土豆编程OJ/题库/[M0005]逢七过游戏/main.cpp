#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	if (n % 7 == 0 || n >= 10 || n >= m) {
		cout << "无法进行" << endl;
		return 0;
	}
	
	for (int i = n; i <= m; i++) {
		if (i % 7 == 0 || to_string(i).find('7') != string::npos) {
			cout << "过" << endl;
		} else {
			cout << i << endl;
		}
	}
	return 0;
}

