#include <iostream>
using namespace std;

const int MAXLength = 101;  //MAXLength 最大迷宫尺寸
int maze[MAXLength][MAXLength]; //迷宫数组：1代表墙壁，0代表通路
int path[MAXLength][MAXLength]; //路径数组：标记已经访问过的路径
int maze_x, maze_y;  //maze_x maze_y 迷宫的行数和列数 

/* 8个可能的移动方向
dir[i][0]为水平偏移
dir[i][1]为垂直偏移
*/
int dir[8][2] = {
    {0, 1}, // 右
    {1, 1}, // 右下
    {1, 0}, // 下
    {1, -1}, // 左下
    {0, -1}, // 左
    {-1, -1}, // 左上
    {-1, 0}, // 上
    {-1, 1} // 右上
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
    return x >= 0 && x < maze_x && y >= 0 && y < maze_y 
    && maze[x][y] == 0 && path[x][y] == 0;
}

/* dfs 递归函数，进行深度优先搜索。
尝试每个可能的方向，直到找到出口或者所有路径都尝试过为止
 */
bool dfs(int x, int y) {
    // 如果到达出口
    if (x == maze_x - 1 && y == maze_y - 1) {
        path[x][y] = 8; // 以8标记路径
        cout << "已找到迷宫出口"<<endl;
        return true;
    }

    // 尝试所有可能的移动方向
    for (int i = 0; i < 8; i++) {
        int nextX = x + dir[i][0];//原始x+偏移量dir
        int nextY = y + dir[i][1];

        // 如果下一个位置有效
        if (isValid(nextX, nextY)) {
            path[x][y] = 8; // 标记路径

            if (dfs(nextX, nextY)) // 递归搜索
                return true;
            else {
                // 如果没有找到解决方案，回溯
                path[x][y] = 0;
            }
        }
    }
    return false;//未能找到出口
}

//输出迷宫路径
void printMazeWithPath() {
    cout << "迷宫路径如下(8为所走通路)"<<endl;
    for (int i = 0; i < maze_x; i++) {
        for (int j = 0; j < maze_y; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}
//输出二维数组
void printPath() {
    cout <<"二维数组如下"<<endl;
    for (int i = 0; i < maze_x; i++) {
        for (int j = 0; j < maze_y; j++) {
            if (path[i][j] == 8)
                cout << "(" << i << ", " << j << ") ";
        }
    }
    cout << endl;
    cout << endl;
}
// 输入路径数组
void inputMaze(){
    cout << "请以二元组(i,j)形式输入迷宫(其中1代表墙壁 0代表通路)"<<endl;
    for (int i = 0; i < maze_x; i++) {
            for (int j = 0; j < maze_y; j++) {
                cin >> maze[i][j];
                path[i][j] = 0; // 初始化路径数组
            }
        }
        
}
void defaultInput() {
    // 预定义的默认迷宫数据
    int defaultMaze[10][10] = {
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 0}
    };
    cout << "默认迷宫输入为"<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<defaultMaze[i][j]<<" ";
        }cout<<endl;
    }
    maze_x = maze_y = 10; // 设置迷宫大小为10x10
    for (int i = 0; i < maze_x; i++) {
        for (int j = 0; j < maze_y; j++) {
            maze[i][j] = defaultMaze[i][j];
            path[i][j] = 0;
        }
    }
}


int menu() {
    int selectnum;
    cout << "# # # # # # # # # # # # # #" << endl;
    cout << "# Maze Problem for C++    #" << endl;
    cout << "# Main menu               #" << endl;
    cout << "# 1. Default input        #" << endl;
    cout << "# 2. Enter maze manually  #" << endl;
    cout << "# 0. Exit!                #" << endl;
    cout << "# # # # # # # # # # # # # #" << endl;
    cout << "Please enter number to select: ";
    cin >> selectnum;
    switch (selectnum) {
        case 1:
            defaultInput();
            break;
        case 2:
            cout << "请输入迷宫长宽"<<endl; 
            cout << "长宽不大于100,用空格隔开"<<endl;
            cin >> maze_x >> maze_y;
            inputMaze();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid selection. Please try again." << endl;
            break;
    }
    cout << endl;
    return selectnum;
}
int main() {
    while (menu() != 0) {
        
        if (dfs(0, 0)) {// 从入口开始搜索
            printMazeWithPath(); // 打印带路径的迷宫
            printPath(); // 打印路径
        } else {
            cout << "No path found." << endl;
        }
    }
    return 0;
}