#include <iostream>
#include <string>
using namespace std;

#define MAX_S 50
#define MAX_D 8

int N, M, ans;
string input;
char arr[MAX_S][MAX_S];
int dx[MAX_D] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // �� ������ ����
int dy[MAX_D] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool InRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		for (int j = 0; j < M; ++j)
			arr[i][j] = input[j];
	}

	// �ϳ��� ĭ�� ����
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] != 'L') continue;

			// 'L' ���ڸ� ã�� ���
			int cur_x = i;
			int cur_y = j;
			// 8 ������ ���캸�鼭 'EE'�� �����ϴ��� ã�´�.
			for (int d = 0; d < MAX_D; ++d) {
				int nx = cur_x + dx[d];
				int ny = cur_y + dy[d];

				// �� �������� �̵��ϸ鼭 Ž���Ѵ�.
				int k = 0;
				for (; k < 2; ++k) {
					// ���� �� �Ǵ� 'E'�� �ƴ� ��� ���� �������� �ѱ��.
					if (!InRange(nx, ny) || arr[nx][ny] != 'E') break;
					nx += dx[d];
					ny += dy[d];
				}

				// 'EE'�� ã�� ���
				if (k == 2)
					ans++;
			}
		}
	}

	cout << ans;

	return 0;
}