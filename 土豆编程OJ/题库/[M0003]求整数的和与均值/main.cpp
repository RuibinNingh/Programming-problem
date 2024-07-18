#include<iostream>
using namespace std;
int main() {
	int n,sum=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int Input=0;
		scanf("%d",&Input);
		sum+=Input;
	}
	printf("%d %.2f",sum,(double)sum/n);
	return 0;
}
