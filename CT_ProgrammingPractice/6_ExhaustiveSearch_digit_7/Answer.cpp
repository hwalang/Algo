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
		// ���� ���� �� �Է�
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];

		// �� i��° üũ����Ʈ�� �ǳ� �پ��� ���� �Ÿ��� �����ݴϴ�.
		int ans = INT_MAX;
		for (int i = 1; i < n - 1; i++) {
			// �Ÿ��� ���մϴ�.
			int dist = 0;
			int prev_idx = 0;
			for (int j = 1; j < n; j++) {
				if (j == i) continue;
				dist += abs(x[prev_idx] - x[j]) + abs(y[prev_idx] - y[j]);
				prev_idx = j;
			}

			// ������ �Ÿ� �� �ּڰ��� �����ݴϴ�.
			ans = min(ans, dist);
		}

		// ���
		cout << ans;

		return 0;
	}
}