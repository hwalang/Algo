#include <iostream>
using namespace std;

#define MAX_N 100

int N, ans;
int CowHeight[MAX_N];


int main() {

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> CowHeight[i];

	// i, j, k 지정
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				// 키 비교
				int Ai = CowHeight[i];
				int Aj = CowHeight[j];
				int Ak = CowHeight[k];

				if (Ai <= Aj && Aj <= Ak)
					ans++;
			}
		}
	}

	cout << ans;

	return 0;
}