#include<iostream>
#include<algorithm> 
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define N 1010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,st,du[N],m,tmp[N],ans[N<<3],top;
map<pair<int,int>,int> mp; //(u,v)
vector<int> edge[N];
void Euler(int u){
	while(1){
		while(tmp[u]<edge[u].size()&&!mp[make_pair(u,edge[u][tmp[u]])])tmp[u]++;//如果反向边被走过就不走了
		if(tmp[u]>=edge[u].size())break;
		int v=edge[u][tmp[u]];
		mp[make_pair(u,v)]--;
		mp[make_pair(v,u)]--;//标记反向边
		++tmp[u];
		Euler(v);
	}
	ans[++top]=u;
}
int main(){
	m=read();st=n=550;
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		edge[u].push_back(v);
		edge[v].push_back(u);
		du[u]++,du[v]++;
		st=min(st,min(u,v));	
		mp[make_pair(u,v)]++,mp[make_pair(v,u)]++;	
	}
	for(int i=1;i<=n;++i){
		if(du[i]&1){
			st=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		sort(edge[i].begin(),edge[i].end());//按编号从小到大排序
	}
	Euler(st);
	while(top)printf("%d\n",ans[top--]); //倒序输出
	return 0;
}