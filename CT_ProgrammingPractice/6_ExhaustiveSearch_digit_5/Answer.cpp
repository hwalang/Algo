#include <iostream>
using namespace std;

namespace Ans {
#define MAX_S 15

	int R, C, cnt;
	char arr[MAX_S][MAX_S];

	int Answer() {
		cin >> R >> C;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j)
				cin >> arr[i][j];
		}

		// 첫 번째 점프 지점
		for (int i = 1; i < R; ++i) {
			for (int j = 1; j < C; ++j) {

				// 두 번째 점프 지점
				for (int k = i + 1; k < R - 1; ++k) {
					for (int l = j + 1; l < C - 1; ++l) {
						if (arr[0][0] != arr[i][j] &&
							arr[i][j] != arr[k][l] &&
							arr[k][l] != arr[R - 1][C - 1])
							cnt++;
					}
				}
			}
		}

		cout << cnt;

		return 0;
	}
}
