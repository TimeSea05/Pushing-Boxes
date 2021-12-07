#include "game_functions.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
/**
 * ���ƹؿ�
 * ǽ����
 * ��Ҫ���λ��(Ŀ��λ��)����
 * ���ӣ���
 * ��ң���
 *
 * ������Щ�������Ԫ��֮�⣬���ǻ���Ҫ���ǵ���������
 * �����ӡ���Ŀ��λ�á��غϵ�ʱ��ͼ��ҲӦ�÷����仯
 * Ŀ��λ��+���ӣ���
 * Ŀ��λ��+��ң���
 **/
void draw_map(int map[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
            if (map[i][j] == 0)
                printf("  "); // �˴���Ҫע�⣬���������ַ���ȫ�ǵģ�������Ҫ�����ո�
            else if (map[i][j] == 1)
                printf("��");
            else if (map[i][j] == 2)
                printf("��");
            else if (map[i][j] == 3)
                printf("��");
            else if (map[i][j] == 4)
                printf("��");
            else if (map[i][j] == 5) // 5 == 2 + 3 ����Ŀ��λ�ú������غ�
                printf("��");
            else if (map[i][j] == 6) //5 == 2 + 4 ����Ŀ��λ�ú�����غ�
                printf("��");
        printf("\n");
    }
}

// 4���ƶ�����
// flag_x����ǰ���λ�õĺ����꣬flag_y����ǰ��ҵ�������
// return 1 ��ʾ�˴��ƶ��ɹ����У�
// return 0 ��ʾ�˴��ƶ�δ�ɹ�����

// �����ƶ�
int move_up(int flag_x, int flag_y, int map[20][20])
{
    //�����ҵ��Ϸ��ǿյ�(0)����Ŀ��λ��(2)
    if (map[flag_x - 1][flag_y] == 0 || map[flag_x - 1][flag_y] == 2)
    {
        //��������ƶ�
        map[flag_x][flag_y] -= 4;
        map[flag_x - 1][flag_y] += 4;
        return 1;
    }
    // �����ҵ��Ϸ�������(3)����������Ŀ��λ���غϵ�λ��(3 + 2 == 5)
    else if (map[flag_x - 1][flag_y] == 3 || map[flag_x - 1][flag_y] == 5)
        // �����鲻Խ��������
        // ������ӵ��Ϸ�(flag_x - 2, flag_y)�ǿյ�(0)����Ŀ��λ��(2)
        if (flag_x - 2 >= 0 && (map[flag_x - 2][flag_y] == 0 || map[flag_x - 2][flag_y] == 2))
        {
            // ��ô��������ƶ�
            map[flag_x][flag_y] -= 4;
            // ���������ƶ� (+���(4)-����(3))
            map[flag_x - 1][flag_y] += 1;
            map[flag_x - 2][flag_y] += 3;
            return 1;
        }
    // ֻ��������������ؿ������λ�òŻᷢ���䶯
    // ����������·���λ�ñ��ֲ���
    return 0;
}

// �����ƶ�
int move_down(int flag_x, int flag_y, int map[20][20])
{
    //�����ҵ��·��ǿյ�(0)����Ŀ��λ��(2)
    if (map[flag_x + 1][flag_y] == 0 || map[flag_x + 1][flag_y] == 2)
    {
        //��������ƶ�
        map[flag_x][flag_y] -= 4;
        map[flag_x + 1][flag_y] += 4;
        return 1;
    }
    // �����ҵ��·�������(3)����������Ŀ��λ���غϵ�λ��(3 + 2 == 5)
    else if (map[flag_x + 1][flag_y] == 3 || map[flag_x + 1][flag_y] == 5)
        // �����鲻Խ��������
        // ������ӵ��·�(flag_x + 2, flag_y)�ǿյ�(0)����Ŀ��λ��(2)
        if (flag_x + 2 < 20 && (map[flag_x + 2][flag_y] == 0 || map[flag_x + 2][flag_y] == 2))
        {
            // ��ô��������ƶ�
            map[flag_x][flag_y] -= 4;
            // ���������ƶ� (+���(4)-����(3))
            map[flag_x + 1][flag_y] += 1;
            map[flag_x + 2][flag_y] += 3;
            return 1;
        }
    // ֻ��������������ؿ������λ�òŻᷢ���䶯
    // ����������·���λ�ñ��ֲ���
    return 0;
}

// �����ƶ�
int move_left(int flag_x, int flag_y, int map[20][20])
{
    //�����ҵ����ǿյ�(0)����Ŀ��λ��(2)
    if (map[flag_x][flag_y - 1] == 0 || map[flag_x][flag_y - 1] == 2)
    {
        //��������ƶ�
        map[flag_x][flag_y] -= 4;
        map[flag_x][flag_y - 1] += 4;
        return 1;
    }
    // �����ҵ���������(3)����������Ŀ��λ���غϵ�λ��(3 + 2 == 5)
    else if (map[flag_x][flag_y - 1] == 3 || map[flag_x][flag_y - 1] == 5)
        // �����鲻Խ��������
        // ������ӵ���(flag_x, flag_y - 2)�ǿյ�(0)����Ŀ��λ��(2)
        if (flag_y - 2 >= 0 && (map[flag_x][flag_y - 2] == 0 || map[flag_x][flag_y - 2] == 2))
        {
            // ��ô��������ƶ�
            map[flag_x][flag_y] -= 4;
            // ���������ƶ� (+���(4)-����(3))
            map[flag_x][flag_y - 1] += 1;
            map[flag_x][flag_y - 2] += 3;
            return 1;
        }
    // ֻ��������������ؿ������λ�òŻᷢ���䶯
    // ����������·���λ�ñ��ֲ���
    return 0;
}

// �����ƶ�
int move_right(int flag_x, int flag_y, int map[20][20])
{
    //�����ҵ��ҷ��ǿյ�(0)����Ŀ��λ��(2)
    if (map[flag_x][flag_y + 1] == 0 || map[flag_x][flag_y + 1] == 2)
    {
        //��������ƶ�
        map[flag_x][flag_y] -= 4;
        map[flag_x][flag_y + 1] += 4;
        return 1;
    }
    // �����ҵ��ҷ�������(3)����������Ŀ��λ���غϵ�λ��(3 + 2 == 5)
    else if (map[flag_x][flag_y + 1] == 3 || map[flag_x][flag_y + 1] == 5)
        // �����鲻Խ��������
        // ������ӵ��ҷ�(flag_x, flag_y + 2)�ǿյ�(0)����Ŀ��λ��(2)
        if (flag_y + 2 < 20 && (map[flag_x][flag_y + 2] == 0 || map[flag_x][flag_y + 2] == 2))
        {
            // ��ô��������ƶ�
            map[flag_x][flag_y] -= 4;
            // ���������ƶ� (+���(4)-����(3))
            map[flag_x][flag_y + 1] += 1;
            map[flag_x][flag_y + 2] += 3;
            return 1;
        }
    // ֻ��������������ؿ������λ�òŻᷢ���䶯
    // ����������·���λ�ñ��ֲ���
    return 0;
}

// ��ҵ��ƶ�
// �˴�ʹ��ָ����Ϊ���ƹ�C�����к�����ֵ���ݵ�����
// �����ļ�¼���λ�õ�����ֵ
void move(int *p_flag_x, int *p_flag_y, int map[20][20])
{
    // �Ӽ��̻�ȡָ��
    // w�������ƶ���s�������ƶ���a�������ƶ���d�������ƶ�
    int command = getch();
    // �����ƶ�
    if (command == 87 || command == 119)
        if (move_up(*p_flag_x, *p_flag_y, map))
            *p_flag_x = *p_flag_x - 1;
    // �����ƶ�
    if (command == 83 || command == 115)
        if (move_down(*p_flag_x, *p_flag_y, map))
            *p_flag_x = *p_flag_x + 1;
    // �����ƶ�
    if (command == 65 || command == 97)
        if (move_left(*p_flag_x, *p_flag_y, map))
            *p_flag_y = *p_flag_y - 1;
    // �����ƶ�
    if (command == 68 || command == 100)
        if (move_right(*p_flag_x, *p_flag_y, map))
            *p_flag_y = *p_flag_y + 1;
}

// �������Ƿ��ʤ
// x����洢Ŀ��λ�õĵ�x���꣬y����洢Ŀ��λ�õ�y����
// box_number�����ӵĸ���
int check_for_success(int x[], int y[], int box_number, int map[20][20])
{
    // ��Ŀ��λ���غϵ����ӵĸ���
    int count = 0;
    for (int i = 0; i < box_number; i++)
        if (map[x[i]][y[i]] == 5)
            count++;
    if (count == box_number)
        return 1;
    else
        return 0;
}

// ��õ�ͼ�ؿ��еĻ�����Ϣ
// ����ҵĳ�ʼλ�á����ӵ���Ŀ��Ŀ��λ�õ�����
// �˴���Ȼʹ��ָ����Ϊ�����������ƹ�C��ֵ���ݵ�����
void get_map_info(int *p_flag_x, int *p_flag_y, int *p_box_number, int target_pos_x[], int target_pos_y[], int map[20][20])
{
    int count_x = 0;
    int count_y = 0;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
        {
            // ���map[j][j]λ�������
            if (map[i][j] == 4)
            {
                // ��¼����ҳ�ʼλ��
                *p_flag_x = i;
                *p_flag_y = j;
            }

            // ���map[i][j]λ����Ŀ��λ�û���Ŀ��λ���������غϵĵط�
            if (map[i][j] == 2 || map[i][j] == 5)
            {
                // ������+1
                *p_box_number = *p_box_number + 1;
                // ��¼��Ŀ��λ�õ�����
                target_pos_x[count_x++] = i;
                target_pos_y[count_y++] = j;
            }
        }
}

void play_game(int *p_flag_x, int *p_flag_y, int *p_box_number, int target_pos_x[], int target_pos_y[], int map[20][20])
{
    // ����p_box_number
    *p_box_number = 0;
    // ��ȡ��ͼ�ؿ���Ϣ
    get_map_info(p_flag_x, p_flag_y, p_box_number, target_pos_x, target_pos_y, map);

    // �����û��ʤ����ʱ��
    while (!check_for_success(target_pos_x, target_pos_y, *p_box_number, map))
    {
        draw_map(map);
        move(p_flag_x, p_flag_y, map);
        // ����
        system("cls");
    }
    // ����ٰѵ�ͼ��һ��
    draw_map(map);
}