#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 100

int N, H, T;
int heights[MAX_N];
int min_cost = INT_MAX;

int main() {

	cin >> N >> H >> T;
	for (int i = 0; i < N; ++i)
		cin >> heights[i];

	// �ּ� T ũ�⸦ ������ ���� [i, j]
	for (int i = 0; i < N; ++i) {
		for (int j = i + T - 1; j < N; ++j) {
			// [i, j] ���� ������ �ּ� ����� ����
			int cost = 0;
			for (int k = i; k <= j; ++k) {
				if (heights[k] != H) {
					cost += abs(heights[k] - H);
				}
			}
			min_cost = min(min_cost, cost);
		}
	}

	cout << min_cost;

	return 0;
}