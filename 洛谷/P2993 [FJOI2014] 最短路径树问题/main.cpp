#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int tu[205][205],cj[205],n,m;
int main()
{
    // 初始化tu数组为无穷大
    memset(tu,0x3f,sizeof(tu));
    // 初始化cj数组为无穷大
    memset(cj,0x3f,sizeof(cj));
    // 输入n和m
    cin>>n>>m;
    // 输入cj数组
    for(int i=0;i<n;i++)
    {
        cin>>cj[i];
    }
    // 初始化tu数组对角线为0
    for(int i=0;i<n;i++)
    tu[i][i]=0;
    // 输入m条边，更新tu数组
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        tu[a][b]=c;
        tu[b][a]=c;
    }
        
int k,tt=0;
 // 输入k
 cin>>k;

// 对每条边进行处理
for(int i=1;i<=k;i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        // 当cj[tt]小于等于t时，更新tu数组
        while(cj[tt]<=t){
            for(int j=0;j<n;j++)
            for(int jj=0;jj<n;jj++)                 	    tu[j][jj]=
                min(tu[j][tt]+tu[tt][jj],tu[j][jj]);
            tt++;
        }
        // 如果tu[x][y]为无穷大，或者cj[x]大于t，或者cj[y]大于t，则输出-1
        if(tu[x][y]==inf||cj[x]>t||cj[y]>t)
            cout<<"-1"<<endl;
        // 否则输出tu[x][y]
        else cout<<tu[x][y]<<endl;
    }
    return 0;
}