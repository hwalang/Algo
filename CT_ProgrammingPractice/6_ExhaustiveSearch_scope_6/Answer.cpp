#include <iostream>
#include <algorithm>

/*
[i, j] 구간을 지정한다.
해당 구간 내에서 조건을 만족하면 max_len을 갱신한다.
*/

namespace Ans {
#define MAX_NUM 100

	using namespace std;

	int n, k;
	int arr[MAX_NUM + 1];

	int Answer() {
		// 입력
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x; char c;
			cin >> x >> c;

			if (c == 'G')
				arr[x] = 1;
			else
				arr[x] = 2;
		}

		// 모든 구간의 시작점을 잡아봅니다.
		int max_len = 0;
		for (int i = 0; i <= MAX_NUM; i++) {
			for (int j = i + 1; j <= MAX_NUM; j++) {
				// i와 j 위치에 사람이 있는지 확인합니다.
				if (arr[i] == 0 || arr[j] == 0)
					continue;

				// 해당 구간 내 g와 h의 개수를 구합니다.
				int cnt_g = 0;
				int cnt_h = 0;

				for (int k = i; k <= j; k++) {
					if (arr[k] == 1)
						cnt_g++;
					if (arr[k] == 2)
						cnt_h++;
				}

				// 조건을 만족할 때 구간의 길이를 구해 최댓값과 비교합니다.
				if (cnt_g == 0 || cnt_h == 0 || cnt_g == cnt_h) {
					int len = j - i;
					max_len = max(max_len, len);
				}
			}
		}

		cout << max_len;

		return 0;
	}
}