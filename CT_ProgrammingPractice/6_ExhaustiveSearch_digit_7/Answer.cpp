#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>

namespace Ans {
	using namespace std;
	#define MAX_N 100

	int n;
	int x[MAX_N], y[MAX_N];

	int Answer() {
		// 변수 선언 및 입력
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];

		// 각 i번째 체크포인트를 건너 뛰었을 때의 거리를 구해줍니다.
		int ans = INT_MAX;
		for (int i = 1; i < n - 1; i++) {
			// 거리를 구합니다.
			int dist = 0;
			int prev_idx = 0;
			for (int j = 1; j < n; j++) {
				if (j == i) continue;
				dist += abs(x[prev_idx] - x[j]) + abs(y[prev_idx] - y[j]);
				prev_idx = j;
			}

			// 가능한 거리 중 최솟값을 구해줍니다.
			ans = min(ans, dist);
		}

		// 출력
		cout << ans;

		return 0;
	}
}