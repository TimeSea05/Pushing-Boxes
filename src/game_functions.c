#include "game_functions.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
/**
 * 绘制关卡
 * 墙：■
 * 需要填补的位置(目标位置)：◎
 * 箱子：☆
 * 玩家：♀
 *
 * 除了这些最基本的元素之外，我们还需要考虑到以下因素
 * 当箱子☆与目标位置◎重合的时候，图标也应该发生变化
 * 目标位置+箱子：★
 * 目标位置+玩家：♂
 **/
void draw_map(int map[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
            if (map[i][j] == 0)
                printf("  "); // 此处需要注意，由于中文字符是全角的，所以需要两个空格
            else if (map[i][j] == 1)
                printf("■");
            else if (map[i][j] == 2)
                printf("◎");
            else if (map[i][j] == 3)
                printf("☆");
            else if (map[i][j] == 4)
                printf("♀");
            else if (map[i][j] == 5) // 5 == 2 + 3 代表目标位置和箱子重合
                printf("★");
            else if (map[i][j] == 6) //5 == 2 + 4 代表目标位置和玩家重合
                printf("♂");
        printf("\n");
    }
}

// 4组移动函数
// flag_x代表当前玩家位置的横坐标，flag_y代表当前玩家的纵坐标
// return 1 表示此次移动成功进行，
// return 0 表示此次移动未成功进行

// 向上移动
int move_up(int flag_x, int flag_y, int map[20][20])
{
    //如果玩家的上方是空地(0)或者目标位置(2)
    if (map[flag_x - 1][flag_y] == 0 || map[flag_x - 1][flag_y] == 2)
    {
        //玩家向上移动
        map[flag_x][flag_y] -= 4;
        map[flag_x - 1][flag_y] += 4;
        return 1;
    }
    // 如果玩家的上方是箱子(3)或者箱子与目标位置重合的位置(3 + 2 == 5)
    else if (map[flag_x - 1][flag_y] == 3 || map[flag_x - 1][flag_y] == 5)
        // 在数组不越界的情况下
        // 如果箱子的上方(flag_x - 2, flag_y)是空地(0)或者目标位置(2)
        if (flag_x - 2 >= 0 && (map[flag_x - 2][flag_y] == 0 || map[flag_x - 2][flag_y] == 2))
        {
            // 那么玩家向上移动
            map[flag_x][flag_y] -= 4;
            // 箱子向上移动 (+玩家(4)-箱子(3))
            map[flag_x - 1][flag_y] += 1;
            map[flag_x - 2][flag_y] += 3;
            return 1;
        }
    // 只有以上两种情况关卡方块的位置才会发生变动
    // 在其余情况下方块位置保持不变
    return 0;
}

// 向下移动
int move_down(int flag_x, int flag_y, int map[20][20])
{
    //如果玩家的下方是空地(0)或者目标位置(2)
    if (map[flag_x + 1][flag_y] == 0 || map[flag_x + 1][flag_y] == 2)
    {
        //玩家向下移动
        map[flag_x][flag_y] -= 4;
        map[flag_x + 1][flag_y] += 4;
        return 1;
    }
    // 如果玩家的下方是箱子(3)或者箱子与目标位置重合的位置(3 + 2 == 5)
    else if (map[flag_x + 1][flag_y] == 3 || map[flag_x + 1][flag_y] == 5)
        // 在数组不越界的情况下
        // 如果箱子的下方(flag_x + 2, flag_y)是空地(0)或者目标位置(2)
        if (flag_x + 2 < 20 && (map[flag_x + 2][flag_y] == 0 || map[flag_x + 2][flag_y] == 2))
        {
            // 那么玩家向上移动
            map[flag_x][flag_y] -= 4;
            // 箱子向下移动 (+玩家(4)-箱子(3))
            map[flag_x + 1][flag_y] += 1;
            map[flag_x + 2][flag_y] += 3;
            return 1;
        }
    // 只有以上两种情况关卡方块的位置才会发生变动
    // 在其余情况下方块位置保持不变
    return 0;
}

// 向左移动
int move_left(int flag_x, int flag_y, int map[20][20])
{
    //如果玩家的左方是空地(0)或者目标位置(2)
    if (map[flag_x][flag_y - 1] == 0 || map[flag_x][flag_y - 1] == 2)
    {
        //玩家向左移动
        map[flag_x][flag_y] -= 4;
        map[flag_x][flag_y - 1] += 4;
        return 1;
    }
    // 如果玩家的左方是箱子(3)或者箱子与目标位置重合的位置(3 + 2 == 5)
    else if (map[flag_x][flag_y - 1] == 3 || map[flag_x][flag_y - 1] == 5)
        // 在数组不越界的情况下
        // 如果箱子的左方(flag_x, flag_y - 2)是空地(0)或者目标位置(2)
        if (flag_y - 2 >= 0 && (map[flag_x][flag_y - 2] == 0 || map[flag_x][flag_y - 2] == 2))
        {
            // 那么玩家向左移动
            map[flag_x][flag_y] -= 4;
            // 箱子向左移动 (+玩家(4)-箱子(3))
            map[flag_x][flag_y - 1] += 1;
            map[flag_x][flag_y - 2] += 3;
            return 1;
        }
    // 只有以上两种情况关卡方块的位置才会发生变动
    // 在其余情况下方块位置保持不变
    return 0;
}

// 向右移动
int move_right(int flag_x, int flag_y, int map[20][20])
{
    //如果玩家的右方是空地(0)或者目标位置(2)
    if (map[flag_x][flag_y + 1] == 0 || map[flag_x][flag_y + 1] == 2)
    {
        //玩家向左移动
        map[flag_x][flag_y] -= 4;
        map[flag_x][flag_y + 1] += 4;
        return 1;
    }
    // 如果玩家的右方是箱子(3)或者箱子与目标位置重合的位置(3 + 2 == 5)
    else if (map[flag_x][flag_y + 1] == 3 || map[flag_x][flag_y + 1] == 5)
        // 在数组不越界的情况下
        // 如果箱子的右方(flag_x, flag_y + 2)是空地(0)或者目标位置(2)
        if (flag_y + 2 < 20 && (map[flag_x][flag_y + 2] == 0 || map[flag_x][flag_y + 2] == 2))
        {
            // 那么玩家向右移动
            map[flag_x][flag_y] -= 4;
            // 箱子向右移动 (+玩家(4)-箱子(3))
            map[flag_x][flag_y + 1] += 1;
            map[flag_x][flag_y + 2] += 3;
            return 1;
        }
    // 只有以上两种情况关卡方块的位置才会发生变动
    // 在其余情况下方块位置保持不变
    return 0;
}

// 玩家的移动
// 此处使用指针是为了绕过C语言中函数按值传递的特性
// 来更改记录玩家位置的整数值
void move(int *p_flag_x, int *p_flag_y, int map[20][20])
{
    // 从键盘获取指令
    // w是向上移动，s是向下移动，a是向左移动，d是向右移动
    int command = getch();
    // 向上移动
    if (command == 87 || command == 119)
        if (move_up(*p_flag_x, *p_flag_y, map))
            *p_flag_x = *p_flag_x - 1;
    // 向下移动
    if (command == 83 || command == 115)
        if (move_down(*p_flag_x, *p_flag_y, map))
            *p_flag_x = *p_flag_x + 1;
    // 向左移动
    if (command == 65 || command == 97)
        if (move_left(*p_flag_x, *p_flag_y, map))
            *p_flag_y = *p_flag_y - 1;
    // 向右移动
    if (command == 68 || command == 100)
        if (move_right(*p_flag_x, *p_flag_y, map))
            *p_flag_y = *p_flag_y + 1;
}

// 检查玩家是否获胜
// x数组存储目标位置的的x坐标，y数组存储目标位置的y坐标
// box_number是箱子的个数
int check_for_success(int x[], int y[], int box_number, int map[20][20])
{
    // 与目标位置重合的箱子的个数
    int count = 0;
    for (int i = 0; i < box_number; i++)
        if (map[x[i]][y[i]] == 5)
            count++;
    if (count == box_number)
        return 1;
    else
        return 0;
}

// 获得地图关卡中的基本信息
// 如玩家的初始位置、箱子的数目、目标位置的坐标
// 此处仍然使用指针作为参数，方便绕过C按值传递的特性
void get_map_info(int *p_flag_x, int *p_flag_y, int *p_box_number, int target_pos_x[], int target_pos_y[], int map[20][20])
{
    int count_x = 0;
    int count_y = 0;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
        {
            // 如果map[j][j]位置是玩家
            if (map[i][j] == 4)
            {
                // 记录下玩家初始位置
                *p_flag_x = i;
                *p_flag_y = j;
            }

            // 如果map[i][j]位置是目标位置或者目标位置与箱子重合的地方
            if (map[i][j] == 2 || map[i][j] == 5)
            {
                // 箱子数+1
                *p_box_number = *p_box_number + 1;
                // 记录下目标位置的坐标
                target_pos_x[count_x++] = i;
                target_pos_y[count_y++] = j;
            }
        }
}

void play_game(int *p_flag_x, int *p_flag_y, int *p_box_number, int target_pos_x[], int target_pos_y[], int map[20][20])
{
    // 重置p_box_number
    *p_box_number = 0;
    // 获取地图关卡信息
    get_map_info(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map);

    // 当玩家没有胜利的时候
    while (!check_for_success(target_pos_x, target_pos_y, *p_box_number, map))
    {
        draw_map(map);
        move(p_flag_x, p_flag_y, map);
        // 清屏
        system("cls");
    }
    // 最后再把地图画一下
    draw_map(map);
}