#include<iostream>
using namespace std;
int main() {
	
	string a;
	int num=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		num+=a[i]-'0';
	}
	cout<<num;
	return 0;
}
