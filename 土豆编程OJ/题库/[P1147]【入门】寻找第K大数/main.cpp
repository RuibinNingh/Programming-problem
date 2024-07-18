#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int num[m]={};
	for(int i=0;i<m;i++){
		cin>>num[i];
	}
	sort(num,num+m,greater<int>());
	cout<<num[n-1];
}

