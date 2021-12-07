#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "game_functions.h"

int main()
{
    // 从map.c文件中导入各个关卡的地图
    extern int map_1[20][20];
    extern int map_2[20][20];
    extern int map_3[20][20];
    extern int map_4[20][20];
    extern int map_5[20][20];

    // 玩家的位置
    int flag_x, flag_y;
    int *p_flag_x = &flag_x;
    int *p_flag_y = &flag_y;

    // 箱子的个数
    int box_number;
    int *p_box_number = &box_number;

    // 目标位置的x坐标与y坐标
    int target_pos_x[10];
    int target_pos_y[10];

    printf("现在开始游戏！！！\n");
    printf("按W/A/S/D分别是向上/下/左/右移动\n");
    printf("♀代表玩家，■代表墙，☆代表箱子\n");
    printf("◎代表箱子需要填补的位置(目标位置)，★代表目标位置+箱子，♂代表目标位置+玩家\n");
    printf("按任意键开始游戏！！！\n\n\n");

    // 第一关
    {
        printf("这是第一关！\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_1);
        printf("恭喜通过第一关\n按任意键继续第二关\n");
        system("pause");
        system("cls");
    }

    // 第二关
    {
        printf("这是第二关！\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_2);
        printf("恭喜通过第二关\n按任意键继续第三关\n");
        system("pause");
        system("cls");
    }

    // 第三关
    {
        printf("这是第三关！\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_3);
        printf("恭喜通过第三关\n按任意键继续第四关\n");
        system("pause");
        system("cls");
    }

    // 第四关
    {
        printf("这是第四关！\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_4);
        printf("恭喜通过第四关\n按任意键继续第五关\n");
        system("pause");
        system("cls");
    }

    // 第五关
    {
        printf("这是第五关！\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_5);
        printf("恭喜通过第五关\n\n");
        system("cls");
    }

    printf("恭喜！你赢了!\n\n");
    printf("卧了个槽你怎么这么几把牛！\n\n");
    printf("完结撒花！！！\n\n");
    system("pause");
    return 0;
}