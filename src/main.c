#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "game_functions.h"

int main()
{
    // ��map.c�ļ��е�������ؿ��ĵ�ͼ
    extern int map_1[20][20];
    extern int map_2[20][20];
    extern int map_3[20][20];
    extern int map_4[20][20];
    extern int map_5[20][20];

    // ��ҵ�λ��
    int flag_x, flag_y;
    int *p_flag_x = &flag_x;
    int *p_flag_y = &flag_y;

    // ���ӵĸ���
    int box_number;
    int *p_box_number = &box_number;

    // Ŀ��λ�õ�x������y����
    int target_pos_x[10];
    int target_pos_y[10];

    printf("���ڿ�ʼ��Ϸ������\n");
    printf("��W/A/S/D�ֱ�������/��/��/���ƶ�\n");
    printf("�������ң�������ǽ�����������\n");
    printf("�����������Ҫ���λ��(Ŀ��λ��)�������Ŀ��λ��+���ӣ������Ŀ��λ��+���\n");
    printf("���������ʼ��Ϸ������\n\n\n");

    // ��һ��
    {
        printf("���ǵ�һ�أ�\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_1);
        printf("��ϲͨ����һ��\n������������ڶ���\n");
        system("pause");
        system("cls");
    }

    // �ڶ���
    {
        printf("���ǵڶ��أ�\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_2);
        printf("��ϲͨ���ڶ���\n�����������������\n");
        system("pause");
        system("cls");
    }

    // ������
    {
        printf("���ǵ����أ�\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_3);
        printf("��ϲͨ��������\n��������������Ĺ�\n");
        system("pause");
        system("cls");
    }

    // ���Ĺ�
    {
        printf("���ǵ��Ĺأ�\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_4);
        printf("��ϲͨ�����Ĺ�\n����������������\n");
        system("pause");
        system("cls");
    }

    // �����
    {
        printf("���ǵ���أ�\n\n");
        play_game(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map_5);
        printf("��ϲͨ�������\n\n");
        system("cls");
    }

    printf("��ϲ����Ӯ��!\n\n");
    printf("���˸�������ô��ô����ţ��\n\n");
    printf("�������������\n\n");
    system("pause");
    return 0;
}