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

	// �ϳ��� ���ڸ� ����
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		// ������ ���� �� �ϳ��� ����
		int sum = 0;
		for (int j = 0; j < N; ++j) {
			// �����ϰų� i�� ���� ���� ����
			if (i == j || abs(j - i) == 1) continue;

			sum = nums[i] + nums[j];
			// �ִ��� ����
			ans = max(ans, sum);
		}
	}

	cout << ans;

	return 0;
}