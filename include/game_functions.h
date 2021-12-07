#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

// ���ƹؿ�
void draw_map(int map[20][20]);

// 4���ƶ�����
// flag_x����ǰ���λ�õĺ����꣬flag_y����ǰ��ҵ�������

// �����ƶ�
int move_up(int flag_x, int flag_y, int map[20][20]);
// �����ƶ�
int move_down(int flag_x, int flag_y, int map[20][20]);
// �����ƶ�
int move_left(int flag_x, int flag_y, int map[20][20]);
// �����ƶ�
int move_right(int flag_x, int flag_y, int map[20][20]);

// ��ҵ��ƶ�
// �˴�ʹ��ָ����Ϊ���ƹ�C�����к�����ֵ���ݵ�����
// �����ļ�¼���λ�õ�����ֵ
void move(int *p_flag_x, int *p_flag_y, int map[20][20]);

// �������Ƿ��ʤ
// x����洢Ŀ��λ�õĵ�x���꣬y����洢Ŀ��λ�õ�y����
// box_number�����ӵĸ���
int check_for_success(int x[], int y[], int box_number, int map[20][20]);

// ��õ�ͼ�ؿ��еĻ�����Ϣ
// ����ҵĳ�ʼλ�á����ӵ���Ŀ��Ŀ��λ�õ�����
// �˴���Ȼʹ��ָ����Ϊ�����������ƹ�C��ֵ���ݵ�����
void get_map_info(int *p_flag_x, int *p_flag_y, int *p_box_number, int target_pos_x[], int target_pos_y[], int map[20][20]);

// ִ����Ϸ
// ��ִ����Ϸ����Ҫ�ı��൱��Ĳ���
// ��˴˴���Ȼʹ��ָ����Ϊ�������ƹ�C��ֵ���ݵ�����
void play_game(int *p_flag_x, int *p_flag_y, int *p_box_number, int target_pos_x[], int target_pos_y[], int map[20][20]);

#endif