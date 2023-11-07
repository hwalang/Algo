#include <iostream>
using namespace std;

#define MAX_S 15

int R, C, cnt;
char arr[MAX_S][MAX_S];

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j)
			cin >> arr[i][j];
	}

	// 시작점 끝점을 세팅
	int startx = 0; int starty = 0;
	int endx = R - 1; int endy = C - 1;
	char start_color = arr[0][0];
	char end_color = arr[endx][endy];

	// 첫 번째 점프 지점, 무조건 아래 오른쪽으로 가야하기 때문에 범위 - 1
	for (int i = startx + 1; i < R - 1; ++i) {
		for (int j = starty + 1; j < C - 1; ++j) {
			char first_color = start_color;
			// 색깔이 달라야 한다.
			if (first_color == arr[i][j]) continue;
			first_color = arr[i][j];

			// 두 번째 점프 지점
			for (int k = i + 1; k < R - 1; ++k) {
				for (int l = j + 1; l < C - 1; ++l) {
					char second_color = first_color;
					if (second_color == arr[k][l]) continue;
					second_color = arr[k][l];
					if (second_color == end_color) continue;

					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}