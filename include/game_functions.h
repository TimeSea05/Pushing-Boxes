#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

// 绘制关卡
void draw_map(int map[20][20]);

// 4组移动函数
// flag_x代表当前玩家位置的横坐标，flag_y代表当前玩家的纵坐标

// 向上移动
int move_up(int flag_x, int flag_y, int map[20][20]);
// 向下移动
int move_down(int flag_x, int flag_y, int map[20][20]);
// 向左移动
int move_left(int flag_x, int flag_y, int map[20][20]);
// 向右移动
int move_right(int flag_x, int flag_y, int map[20][20]);

// 玩家的移动
// 此处使用指针是为了绕过C语言中函数按值传递的特性
// 来更改记录玩家位置的整数值
void move(int *p_flag_x, int *p_flag_y, int map[20][20]);

// 检查玩家是否获胜
// x数组存储目标位置的的x坐标，y数组存储目标位置的y坐标
// box_number是箱子的个数
int check_for_success(int x[], int y[], int box_number, int map[20][20]);

// 获得地图关卡中的基本信息
// 如玩家的初始位置、箱子的数目、目标位置的坐标
// 此处仍然使用指针作为参数，方便绕过C按值传递的特性
void get_map_info(int *p_flag_x, int *p_flag_y, int *p_box_number, int target_pos_x[], int target_pos_y[], int map[20][20]);

// 执行游戏
// 在执行游戏中需要改变相当多的参量
// 因此此处仍然使用指针作为参数，绕过C按值传递的特性
void play_game(int *p_flag_x, int *p_flag_y, int *p_box_number, int target_pos_x[], int target_pos_y[], int map[20][20]);

#endif