#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 20

int N, ans;
int arr[MAX_N][MAX_N];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];
	}

	// 1 * 3 ũ���� ���ڿ��� ���� ������ ����
	for (int i = 0; i < N; ++i) {
		// 1 * 3 ũ���� ���ڿ��� 3���� ���� ����
		for (int j = 0; j < N - 2; ++j) {
			ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2]);
		}
	}

	cout << ans;

	return 0;
}