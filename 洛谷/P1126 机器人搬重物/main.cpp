#include <cstdio>
#include <queue>
 
enum DIR {
	//方向定义 
	EAST = 0,
	SOUTH,
	WEST,
	NORTH
};
 
struct POS {                                                            
	int x, y;//坐标
	int dir;//方向
	int dis;//距离 
	
};
 
const int MAXN = 54;
struct MAZE {
	int row, col;//长宽 
	int x1, y1;//起点 
	int x2, y2;//终点
	int map[MAXN][MAXN];//迷宫数据
	bool visit[MAXN][MAXN][4];//访问性 
	int dir;
};
 
int bfs(MAZE &maze);
 
int main() {
	MAZE maze={};
	scanf("%d %d", &maze.row, &maze.col);
	
	int i, j;
	for (i=1; i<=maze.row; i++) {
		for (j=1; j<=maze.col; j++) {
			scanf("%d", &maze.map[i][j]);
			//注意机器人体积 
			if (maze.map[i][j]==1) {
				maze.map[i-1][j]=1;
				maze.map[i][j-1]=1;
				maze.map[i-1][j-1]=1;
			}
		}
	}
	
	char dir;
	scanf("%d %d %d %d %c", &maze.x1, &maze.y1, &maze.x2, &maze.y2, &dir);
	if (dir=='S') {
		maze.dir = SOUTH;
	} else if (dir=='W') {
		maze.dir = WEST;
	} else if (dir == 'N') {
		maze.dir = NORTH;
	} else {
		maze.dir = EAST;
	}
	
	//特别处理 
	if (maze.x2<1||maze.x2>=maze.row||maze.y2<1||maze.y2>=maze.col||maze.map[maze.x2][maze.y2]==1) {
		printf("-1\n");
		return 0;
	}
	
	printf("%d\n", bfs(maze));
	
	return 0;
}
 
int bfs(MAZE &maze) {
	std::queue<POS> q;
	
	//起点
	POS cur;
	cur.x   = maze.x1;
	cur.y   = maze.y1; 
	cur.dir = maze.dir;
	cur.dis = 0;
	q.push(cur);
	maze.visit[maze.x1][maze.y1][maze.dir] = true;
	
	//开始遍历 
	POS next;
	const int dx[4] = {0,1,0,-1};
	const int dy[4] = {1,0,-1,0};
	//const int dx[4] = {1,0,-1,0};
	//const int dy[4] = {0,1,0,-1};
 
	int i;
	while (q.empty()!=true) {
		cur = q.front();
		q.pop();
		
		//判断是否终点
		if (cur.x==maze.x2&&cur.y==maze.y2) {
			return cur.dis;
		}
		
		//开始走路
		for (i=1; i<=3; i++) {
			next.x = cur.x + dx[cur.dir]*i;
			next.y = cur.y + dy[cur.dir]*i;
			
			//判断是否在迷宫内
			if (next.x<1||next.x>=maze.row||next.y<1||next.y>=maze.col||maze.map[next.x][next.y]==1)  {
				break;
			} else if (maze.visit[next.x][next.y][cur.dir]==false) {
				maze.visit[next.x][next.y][cur.dir] = true;
				next.dis = cur.dis + 1;
				next.dir = cur.dir;
				q.push(next);
			}
		}
		
		//左转
		next.x = cur.x;
		next.y = cur.y;
		next.dir = cur.dir - 1;
		if (next.dir==-1) {
			next.dir = NORTH;
		}
		if (maze.visit[next.x][next.y][next.dir]==false) {
			maze.visit[next.x][next.y][next.dir] = true;
			next.dis = cur.dis + 1;
			q.push(next);
		}
		
		//右转 
		next.dir = cur.dir + 1;
		if (next.dir==4) {
			next.dir = EAST;
		}
		if (maze.visit[next.x][next.y][next.dir]==false) {
			maze.visit[next.x][next.y][next.dir] = true;
			next.dis = cur.dis + 1;
			q.push(next);
		}
	}
	
	return -1;
}