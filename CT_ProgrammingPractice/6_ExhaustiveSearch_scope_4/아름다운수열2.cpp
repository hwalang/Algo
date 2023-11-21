#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define MAX_M 100

int N, M, ans;
int A[MAX_N], B[MAX_M], temp[MAX_N];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < M; ++i)
		cin >> B[i];

	// ������ ���� ������ ���Ѵ�.
	sort(B, B + M);
	for (int i = 0; i <= N - M; ++i) {
		// A�� 
		for (int j = 0; j < M; ++j)
			temp[j] = A[i + j];
		sort(temp, temp + M);

		bool flag = true;
		for (int j = 0; j < M; ++j) {
			if (temp[j] != B[j]) {
				flag = false;
				break;
			}
		}

		if (flag)
			ans++;
	}

	cout << ans;

	return 0;
}