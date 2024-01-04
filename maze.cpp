#include <iostream>
#include <vector>
using namespace std;

const int MAXLength = 100;  //MAXLength 最大迷宫尺寸
int maze[MAXLength][MAXLength]; //maze 迷宫本身 1代表墙壁 0代表通路
int path[MAXLength][MAXLength]; //path 标记已经访问过的路径
int m, n;  //m n 迷宫的行数和列数 

vector<pair<int, int>> solution; // 保存路径的向量

// 8个可能的移动方向
int dir[8][2] = {
    {0, 1}, // 东
    {1, 1}, // 东南
    {1, 0}, // 南
    {1, -1}, // 西南
    {0, -1}, // 西
    {-1, -1}, // 西北
    {-1, 0}, // 北
    {-1, 1} // 东北
};

/*isValid
用于检查一个坐标是否可以访问,
不是墙壁被访问过。
x,y在迷宫索引范围内
maze[x][y] == 0: 迷宫在 (x, y) 的位置必须是通路。
path[x][y] == 0: 路径数组 path 在 (x, y) 的位置还没有被访问过
*/
bool isValid(int x, int y) {
    // 检查坐标是否在迷宫内部&&不是墙壁&&未被访问过
    return x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0 && path[x][y] == 0;
}

/* dfs 递归函数，进行深度优先搜索。
尝试每个可能的方向，直到找到出口或者所有路径都尝试过为止
 */
bool dfs(int x, int y) {
    // 如果到达出口
    if (x == m - 1 && y == n - 1) {
        solution.push_back({x, y}); // 添加出口坐标到路径
        path[x][y] = 8; // 标记路径
        return true;
    }

    // 尝试所有可能的移动方向
    for (int i = 0; i < 8; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];

        // 如果下一个位置有效
        if (isValid(nextX, nextY)) {
            path[x][y] = 8; // 标记路径
            solution.push_back({x, y}); // 添加当前坐标到路径

            if (dfs(nextX, nextY)) // 递归搜索
                return true;
            else {
                // 如果没有找到解决方案，回溯
                path[x][y] = 0;
                solution.pop_back();
            }
        }
    }
    return false;
}

//打印迷宫
void printMaze() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}
//打印路径
void printPath() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

/*入口为左上角(0,0),出口为右下角(m-1,n-1)*/
//模拟输入如下
/* 
5 5
0 0 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 1 0 0
1 1 1 1 0 
*/
int main() {
    // 输入迷宫大小
    cin >> m >> n;
    
    // 输入迷宫数据

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            path[i][j] = 0; // 初始化路径数组
        }
    }

    // 从入口开始搜索
    if (dfs(0, 0)) {
        printPath(); // 打印路径
        for (auto& p : solution) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
