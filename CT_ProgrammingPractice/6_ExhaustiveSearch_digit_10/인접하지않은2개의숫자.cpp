#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 100

int N;
int nums[MAX_N];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	// 하나의 숫자를 선택
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		// 나머지 숫자 중 하나를 선택
		int sum = 0;
		for (int j = 0; j < N; ++j) {
			// 인접하거나 i와 같은 경우는 제외
			if (i == j || abs(j - i) == 1) continue;

			sum = nums[i] + nums[j];
			// 최대합 갱신
			ans = max(ans, sum);
		}
	}

	cout << ans;

	return 0;
}