#include<iostream>
#include <iomanip>

using namespace std;
int main() {
	int num;
	double n,w,shuju,quanzhi;
	cin>>num;
	for (int i=0;i<num;i++){
		cin>>n>>w;
		shuju+=n*w;
		quanzhi+=w;
	}
	cout<<fixed<<setprecision(3)<<shuju/quanzhi;
	return 0;
}
