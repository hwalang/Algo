#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100

int N, K, ans;				// K: ���� ũ��
int barket[MAX_N + 1];	// �ٱ��� ��ġ: 0 ~ 100

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		// �ٱ��� ��ġ�� ���� ������ �Է� �޴´�.
		int cnt, loc;
		cin >> cnt >> loc;
		barket[loc] += cnt;	// ���� ��ġ�� ���� ���� �ٱ��ϰ� ���� �� �ִ�.
	}
	
	// �߽����� ��´�.
	for (int i = 0; i <= MAX_N; ++i) {
		// i���� �������� + - K ��ŭ Ž���ϸ鼭 ���� ���� ����. 
		// i�� 0�̸� k���� �� �� �ִ�.
		int candyCnt = barket[i];
		for (int k = i + 1; k <= i + K; ++k) {
			if (k > MAX_N) break;
			candyCnt += barket[k];
		}

		for (int k = i - 1; k >= i - K; --k) {
			if (k < 0) break;
			candyCnt += barket[k];
		}

		ans = max(ans, candyCnt);
	}
	
	cout << ans;

	return 0;
}