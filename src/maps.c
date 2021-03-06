/**
 * map数组是整个关卡各个方块的分布图
 * 其中 0 代表这个位置什么方块也没有，
 *      1 代表这个位置是墙，
 *      2 代表这是箱子要填补的位置(目标位置)
 *      3 代表箱子的位置
 *      4 代表当前玩家的位置
 *      5 代表箱子和目标位置重合
 *      6 代表玩家和目标位置重合
 **/
// 第一关
int map_1[20][20] = {{0, 0, 1, 1, 1, 0, 0, 0},
                     {0, 0, 1, 2, 1, 0, 0, 0},
                     {0, 0, 1, 0, 1, 1, 1, 1},
                     {1, 1, 1, 3, 0, 3, 2, 1},
                     {1, 2, 0, 3, 4, 1, 1, 1},
                     {1, 1, 1, 1, 3, 1, 0, 0},
                     {0, 0, 0, 1, 2, 1, 0, 0},
                     {0, 0, 0, 1, 1, 1, 0, 0}};

// 第二关
int map_2[20][20] = {{1, 1, 1, 1, 1, 0, 0, 0, 0},
                     {1, 4, 0, 0, 1, 0, 0, 0, 0},
                     {1, 0, 3, 3, 1, 0, 1, 1, 1},
                     {1, 0, 3, 0, 1, 0, 1, 2, 1},
                     {1, 1, 1, 0, 1, 1, 1, 2, 1},
                     {0, 1, 1, 0, 0, 0, 0, 2, 1},
                     {0, 1, 0, 0, 0, 1, 0, 0, 1},
                     {0, 1, 0, 0, 0, 1, 1, 1, 1},
                     {0, 1, 1, 1, 1, 1, 0, 0, 0}};

// 第三关
int map_3[20][20] = {{0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                     {0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
                     {1, 1, 3, 1, 1, 1, 0, 0, 0, 1},
                     {1, 0, 4, 0, 3, 0, 0, 3, 0, 1},
                     {1, 0, 2, 2, 1, 0, 3, 0, 1, 1},
                     {1, 1, 2, 2, 1, 0, 0, 0, 1, 0},
                     {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}};

// 第四关
int map_4[20][20] = {{0, 1, 1, 1, 1, 0},
                     {1, 1, 0, 0, 1, 0},
                     {1, 4, 3, 0, 1, 0},
                     {1, 1, 3, 0, 1, 1},
                     {1, 1, 0, 3, 0, 1},
                     {1, 2, 3, 0, 0, 1},
                     {1, 2, 2, 5, 2, 1},
                     {1, 1, 1, 1, 1, 1}};

// 第五关
int map_5[20][20] = {{0, 1, 1, 1, 1, 1, 0, 0},
                     {0, 1, 0, 0, 1, 1, 1, 0},
                     {0, 1, 4, 3, 0, 0, 1, 0},
                     {1, 1, 1, 0, 1, 0, 1, 1},
                     {1, 2, 1, 0, 1, 0, 0, 1},
                     {1, 2, 3, 0, 0, 1, 0, 1},
                     {1, 2, 0, 0, 0, 3, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1}};