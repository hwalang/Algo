#include <iostream>
#include <string>
using namespace std;

#define MAX_N 99
#define MAX_D 4

int N, T, ans, dir, cur_x, cur_y;
string order;
int grid[MAX_N][MAX_N];
int dx[MAX_D] = { -1, 0, 1, 0 };	// 북동남서
int dy[MAX_D] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}

int main() {
	// Input
	cin >> N >> T;
	cin >> order;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> grid[i][j];
	}

	// Init
	int size = order.size();
	cur_x = N / 2; cur_y = N / 2;
	ans = grid[cur_x][cur_y];		// 시작 지점 포함

	// Simulation
	for (int t = 0; t < T; ++t) {
		if (order[t] == 'L')
			dir = (dir - 1 + 4) % 4;
		else if (order[t] == 'R')
			dir = (dir + 1) % 4;
		else {
			int nx = cur_x + dx[dir];
			int ny = cur_y + dy[dir];
			if (InRange(nx, ny) == false)	// 격자 범위 밖으로 가는 명령어는 넘긴다
				continue;
			ans += grid[nx][ny];
			cur_x = nx;
			cur_y = ny;
			
		}
	}

	cout << ans;

	return 0;
}