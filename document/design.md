main 函数
    显示菜单并获取用户选择。
    根据用户选择执行操作：
    如果迷宫入口或出口被堵，则继续下一次循环。
    调用 dfs 函数从入口开始搜索路径。
    如果找到路径，打印迷宫和路径。
    释放内存。
    结束程序。
isValid 函数
    检查坐标是否在迷宫内部。
    检查坐标位置是否不是墙壁。
    检查坐标位置是否未被访问过。
    返回坐标的有效性。
dfs 函数
    检查是否到达出口，如果是，标记路径并返回 true。
    循环尝试 8 个方向的移动。
    对于每个方向，计算下一个坐标。
    检查下一个坐标是否有效（调用isValid 函数）。
    如果有效，标记路径并递归调用 dfs。
    如果递归调用返回 true，则返回 true。
    如果没有找到路径，回溯并返回 false。
menu 函数
    1，调用 defaultInput 函数。
    2，调用 inputMazeSize 和 inputMaze 函数。
返回用户选择。
辅助函数
    inputMazeSize 函数用于输入迷宫尺寸。
    inputMaze 函数用于输入迷宫数据。
    allocateMemory 和 deallocateMemory 函数用于分配和释放动态数组内存。
    printMazeWithPath 和 printPath 函数用于输出迷宫和路径。