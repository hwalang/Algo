#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define MAX_N 100

int S, N, ans = INT_MAX;
int nums[MAX_N];

int main() {

	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	for (int i = 0; i < N; ++i) {	// �ϳ��� ���� ����
		for (int j = i + 1; j < N; ++j) {	// �� ��° ���� ����
			// ������ �� ���� ������ ������ ������ ���� ����
			int sum = 0;
			for (int k = 0; k < N; ++k) {
				if (k == i || k == j) continue;
				sum += nums[k];
			}
			
			ans = min(ans, abs(S - sum));
		}
	}

	cout << ans;

	return 0;
}