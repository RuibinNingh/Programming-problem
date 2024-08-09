#include <iostream>
using namespace std;
const int N = 9, M = 1 << N;
int g[N][N];
int row[N], col[N], cell[3][3];
int ones[M]; //获取所有二进制形式中1的个数
int log[M]; //获取log(n)
int ans = -1;
//预处理每行每列每个小九宫格可选数字的状态
void init() 
{
    for(int i = 0; i < 9; i ++)
        row[i] = col[i] = (1 << 9) - 1;
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j ++)
            cell[i][j] = (1 << 9) - 1;
}
void fill(int x, int y, int t, bool is_set)
{
    int s = 1 << (t - 1); //要改变的状态，状态从0开始，所以要减1
    if(is_set) //填数
    {
        g[x][y] = t;
        //填完数，该数的状态设为不可行
        row[x] -= s, col[y] -= s, cell[x/3][y/3] -= s; 
    }
    else //清空
    {
        g[x][y] = 0;
        //清空后，该数的状态设为可行
        row[x] += s, col[y] += s, cell[x/3][y/3] += s;
    }
}
//获取x行y列可选数字的状态
int get(int x, int y)
{
    return row[x] & col[y] & cell[x/3][y/3];
}
//获取x行y列填数字t的分数
int get_score(int x, int y, int t)
{
    return (min(min(x, 8 - x), min(y, 8 - y)) + 6) * t;
}
int lowbit(int x)  // 返回末尾的1
{
    return x & -x;
}
void dfs(int cnt, int score)
{
    if(cnt == 0) 
    {
        ans = max(ans, score);
        return; //全部填完
    }
    //优化搜索顺序，寻找可选数字最少的行列
    int minv = 10, x, y;
    for(int i = 0; i < 9; i ++)
        for(int j = 0; j < 9; j ++)
        {
            if(g[i][j] == 0)
            {
                int state = get(i, j);
                if(ones[state] < minv)
                {
                    minv = ones[state], x = i, y = j;
                }
            }
        }
    //从x行y列开始搜索
    int state = get(x, y); //从x行y列可选数字的状态
    for(int i = state; i != 0; i -= lowbit(i))
    {
        int t = log[lowbit(i)] + 1; //获取对应要填的数1~9，map中映射的是0~8，所以要+1
        fill(x, y, t, true);
        dfs(cnt - 1, score + get_score(x, y, t));
        fill(x, y, t, false); //回溯，恢复现场
    }
}
int main()
{
    init();
    //统计每个状态中1的个数
    for(int i = 0; i < 1 << 9; i ++)
        for(int j = 0; j < 9; j ++)
            ones[i] += i >> j & 1; 
    //预处理log(i)，方便快速获取要填的数字，注意预处理的是0~8
    for(int i = 0; i < 9; i ++) log[1 << i] = i;
    
    int cnt = 0, score = 0; //一共要填cnt个数
    for(int i = 0; i < 9; i ++)
        for(int j = 0; j < 9; j ++)
        {
            cin >> g[i][j];
            if(g[i][j] != 0) //数字已填
            {
                fill(i, j, g[i][j], true); //填数
                score += get_score(i, j, g[i][j]);
            }
            else cnt ++;
        }
    
    //暴力搜索，一共要填cnt个数，目前的分数为score
    dfs(cnt, score);
    cout << ans << endl;
}
