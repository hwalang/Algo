#include <iostream>

#define MAX_N 100
#define MAX_D 4

int N;
int arr[MAX_N][MAX_N];

int dx[MAX_D] = { 0, -1, 0, 1 };	// LURD
int dy[MAX_D] = { -1, 0, 1, 0 };
int dir;

bool InRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}

void Simulation() {
	// init
	int cnt = N * N;	
	int cur_x = N - 1, cur_y = N - 1;	// 마지막에서 시작
	int nx = -1, ny = -1;
	arr[cur_x][cur_y] = cnt--;

	while (cnt) {
		nx = cur_x + dx[dir];
		ny = cur_y + dy[dir];

		if (InRange(nx, ny) && arr[nx][ny] == 0) {	// 만족하면 이동 후 기록
			arr[nx][ny] = cnt;
			cnt--;
			cur_x = nx;
			cur_y = ny;
		}
		else {										// 방향 전환
			dir = (dir + 1) % 4;
		}
	}
}

int main() {

	std::cin >> N;

	Simulation();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}


	return 0;
}