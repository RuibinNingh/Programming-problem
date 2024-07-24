#include<iostream>
#include<vector>
using namespace std;
vector<int>a(1001,0);
int shulie(int m,int num){
	int n=m/2;//符合条件的个数
	num+=n;//加上符合条件的个数
	for(int i=n;i>1;i--){//循环并筛选掉不符条件的的
		if(a[i]==0){a[i]=shulie(i,0);num+=a[i];}
		else num+=a[i];}
	return num;
}
int main() {
	/*freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	fclose(stdin);
	fclose(stdout);*/
	freopen("nums.in", "r", stdin);
	freopen("nums.out", "w", stdout);
	int n;
	cin>>n;
	if(n/2==0){
		cout<<1;
		return 0;
	}
	cout<<shulie(n,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/**
 * @runId: 1176401
 * @language: C++
 * @author: 土豆编程538581
 * @submitTime: 2024-07-12 10:33:35
 */
