#include <iostream>
using namespace std;

#define MAX_N 19
#define MAX_D 4

int board[MAX_N][MAX_N];
int ans, middle_x, middle_y;
int dx[MAX_D] = { 1, 1 };	// ������ �Ʒ� �밢��, ���� �Ʒ� �밢��
int dy[MAX_D] = { 1, -1 };

bool InRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < MAX_N && y < MAX_N);
}

bool IsFiveRightDiagonal(int num) {

	int dir = 0;
	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j < MAX_N; ++j) {
			if (board[i][j] != num) continue;	// num�� �ƴ� ���

			// cnt = 1���� ����
			int cnt = 1;
			int nx = i;
			int ny = j;
			for (; cnt < 5; ++cnt) {		// ���ӵ� 5���� ã�´�.
				nx += dx[dir];
				ny += dy[dir];
				if (!InRange(nx, ny) || board[ny][ny] != num) break;	// ���� �� �Ǵ� num�� �ƴ� ���
			}

			if (cnt == 5) {		// 5���� ���
				ans = num;
				middle_x = (i + 1) + 2;
				middle_y = (j + 1) + 2;
				return true;
			}
		}
	}

	return false;
}

bool IsFiveLeftDiagonal(int num) {

	int dir = 1;
	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j < MAX_N; ++j) {
			if (board[i][j] != num) continue;	// num�� �ƴ� ���

			// cnt = 1���� ����
			int cnt = 1;
			int nx = i;
			int ny = j;
			for (; cnt < 5; ++cnt) {		// ���ӵ� 5���� ã�´�.
				nx += dx[dir];
				ny += dy[dir];
				if (!InRange(nx, ny) || board[nx][ny] != num) 
					break;	// ���� �� �Ǵ� num�� �ƴ� ���
			}

			if (cnt == 5) {		// 5���� ���
				ans = num;
				middle_x = (i + 1) + 2;
				middle_y = (j + 1) - 2;
				return true;
			}
		}
	}

	return false;
}

bool IsFiveHeight(int num) {

	for (int i = 0; i < MAX_N; ++i) {
		int cnt = 0;		// ���� �ٲ� ������ cnt�� �ʱ�ȭ
		for (int j = 0; j < MAX_N; ++j) {
			if (board[j][i] != num) {	// �̾����� �ʴ� ���
				cnt = 0;
				continue;
			}

			if (board[j][i] == num)		// num �� ���
				cnt++;

			if (cnt == 5) {				// 5���� �����ϴ� ���
				ans = num;
				middle_x = (j + 1) - 2;		// 1������ ����
				middle_y = (i + 1);
				return true;
			}
		}
	}

	return false;
}

bool IsFiveWidth(int num) {
	
	for (int i = 0; i < MAX_N; ++i) {
		int cnt = 0;		// ���� �ٲ� ������ cnt�� �ʱ�ȭ
		for (int j = 0; j < MAX_N; ++j) {
			if (board[i][j] != num) {	// �̾����� �ʴ� ���
				cnt = 0;
				continue;
			}

			if (board[i][j] == num)		// num �� ���
				cnt++;

			if (cnt == 5) {				// 5���� �����ϴ� ���
				ans = num;
				middle_x = (i + 1);		// 1������ ����
				middle_y = (j + 1) - 2;		
				return true;
			}
		}
	}

	return false;
}

bool WinWhite() {

	int white = 2;
	if (IsFiveWidth(white)) {	// 5�� �Ǵ�: ����
		return true;
	}
	else if (IsFiveHeight(white)) {	// 5�� �Ǵ�: ����
		return true;
	}
	else if (IsFiveLeftDiagonal(white)) {	// 5�� �Ǵ�: ���� �Ʒ� �밢��
		return true;
	}
	else if (IsFiveRightDiagonal(white)) {	// 5�� �Ǵ�: ������ �Ʒ� �밢��
		return true;
	}

	return false;
}

bool WinBlack() {

	int black = 1;
	if (IsFiveWidth(black)) {	// 5�� �Ǵ�: ����
		return true;
	}
	else if (IsFiveHeight(black)) {	// 5�� �Ǵ�: ����
		return true;
	}
	else if (IsFiveLeftDiagonal(black)) {	// 5�� �Ǵ�: ���� �Ʒ� �밢��
		return true;
	}
	else if (IsFiveRightDiagonal(black)) {	// 5�� �Ǵ�: ������ �Ʒ� �밢��
		return true;
	}

	return false;
}

void Solution() {

	if (WinWhite()) {	// 1���� �̱� ���
		cout << ans << endl;
		cout << middle_x << " " << middle_y << endl;
		return;
	}
	else if (WinBlack()) {	// 2���� �̱� ���
		cout << ans << endl;
		cout << middle_x << " " << middle_y << endl;
		return;
	}
	
	// �ºΰ� ���� ���� ���
	cout << ans;
}

int main() {

	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j < MAX_N; ++j)
			cin >> board[i][j];
	}

	Solution();

	return 0;
}