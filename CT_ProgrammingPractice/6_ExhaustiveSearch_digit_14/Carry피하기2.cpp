#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 20

int N, ans = -1;
int nums[MAX_N];

bool IsNotCarry(int a, int b, int c) {

	int f, s, t;
	while (true) {
		if (a == 0 && b == 0 && c == 0)
			break;

		// �� ������ ���� �ڸ����� ����
		f = a % 10;
		s = b % 10;
		t = c % 10;
		if (f + s + t >= 10)
			return false;

		a /= 10;
		b /= 10;
		c /= 10;
	}

	return true;
}

void Solution() {

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				int first = nums[i];
				int second = nums[j];
				int third = nums[k];
				
				// Carry�� �߻����� ������ ans ����
				if (IsNotCarry(first, second, third)) {
					int sum = first + second + third;
					ans = max(ans, sum);
				}
			}
		}
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	// 3�� ���� ����
	Solution();

	cout << ans;

	return 0;
}