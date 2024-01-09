// 已丢弃
/* 
#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100
int maze[MAXLENGTH][MAXLENGTH];
int path[MAXLENGTH][MAXLENGTH];
int m, n;

int solutionX[MAXLENGTH * MAXLENGTH]; // 保存路径的X坐标
int solutionY[MAXLENGTH * MAXLENGTH]; // 保存路径的Y坐标
int solutionSize = 0;

// 检查坐标(x, y)是否为有效移动
int isValid(int x, int y) {
    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0 && path[x][y] == 0) {
        return 1;
    }
    return 0;
}

int dfs(int x, int y) {
    // 如果到达出口
    if (x == m - 1 && y == n - 1) {
        solutionX[solutionSize] = x;
        solutionY[solutionSize] = y;
        solutionSize++;
        path[x][y] = 1; // 标记路径
        return 1;
    }

    // 检查当前位置是否有效
    if (isValid(x, y)) 
    {
        path[x][y] = 1; // 标记为已走过
        solutionX[solutionSize] = x;
        solutionY[solutionSize] = y;
        solutionSize++;

        // 向右走
        if (dfs(x, y + 1)) return 1;
        // 向下走
        if (dfs(x + 1, y)) return 1;
        // 向左走
        if (dfs(x, y - 1)) return 1;
        // 向上走
        if (dfs(x - 1, y)) return 1;
        if (dfs(x - 1, y-1)) return 1;
        if (dfs(x - 1, y+1)) return 1;
        if (dfs(x + 1, y+1)) return 1;
        if (dfs(x + 1, y-1)) return 1;        
        // 如果这条路不通，回溯
        path[x][y] = 0;
        solutionSize--; // 回溯路径长度减一
    }

    return 0; // 没有找到路径
}

void printPath() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}
int main() {
    printf("请输入迷宫的行数和列数: ");
    scanf("%d %d", &m, &n);

    printf("请输入迷宫布局（0表示通路，1表示障碍）:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
            path[i][j] = 0;
        }
    }
    printf("\n");
    if (dfs(0, 0)) {
        
        printPath();
        
        printf("找到的路径为:\n");
        for (int i = 0; i < solutionSize; i++) {
            printf("(%d, %d) ", solutionX[i], solutionY[i]);
        }
        printf("\n");
    } else {
        printf("没有找到路径。\n");
    }

    return 0;
}
 */