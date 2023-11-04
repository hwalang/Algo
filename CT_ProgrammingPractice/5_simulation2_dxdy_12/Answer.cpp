#include <iostream>

#define DIR_NUM 4
#define MAX_N 100
using namespace std;

// ���� ���� ����:
int n;

int curr_x, curr_y;
int move_dir, move_num;

int grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// �� ĭ �����Դϴ�.
void Move() {
    // �������� ���ϴ� ���� ������� 
    // ������ �� ���� �Ʒ� ������ �ǵ��� �����մϴ�.
    int dx[DIR_NUM] = { 0, -1, 0, 1 };
    int dy[DIR_NUM] = { 1, 0, -1, 0 };

    curr_x += dx[move_dir]; curr_y += dy[move_dir];
}

bool End() {
    return !InRange(curr_x, curr_y);
}

int Answer() {
    // �Է�:
    cin >> n;

    // ���� ��ġ�� ����, 
    // �ش� �������� �̵��� Ƚ���� �����մϴ�. 
    curr_x = n / 2; curr_y = n / 2;
    move_dir = 0; move_num = 1;

    int cnt = 1;

    while (!End()) {
        // move_num ��ŭ �̵��մϴ�.
        for (int i = 0; i < move_num; i++) {
            grid[curr_x][curr_y] = cnt++;
            Move();

            // �̵��ϴ� ���� ���ڸ� ����� �Ǹ�,
            // �����̴� ���� �����մϴ�.
            if (End())
                break;
        }

        // ������ �ٲߴϴ�.
        move_dir = (move_dir + 1) % 4;
        // ���� ���� ������ ���� Ȥ�� �������� �� ��쿡��
        // Ư�� �������� �������� �� Ƚ���� 1 ������ŵ�ϴ�.
        if (move_dir == 0 || move_dir == 2)
            move_num++;
    }

    // ���:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}