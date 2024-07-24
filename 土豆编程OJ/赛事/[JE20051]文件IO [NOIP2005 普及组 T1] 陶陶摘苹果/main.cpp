#include <iostream>
using namespace std;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	
	int num=0,m,a[10]={};
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<10;i++){
		if(a[i]<=m+30){
			num+=1;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
}
