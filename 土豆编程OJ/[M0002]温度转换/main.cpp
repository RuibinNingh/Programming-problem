#include<iostream>
#include <iomanip>
using namespace std;
int main() {
	float C;
	cin >> C;
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<C*1.800+32;
	return 0;
}
