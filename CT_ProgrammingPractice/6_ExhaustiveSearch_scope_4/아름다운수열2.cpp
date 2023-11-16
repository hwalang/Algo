#include <iostream>
using namespace std;

#define MAX_N 100
#define MAX_M 100

int N, M;
int A[MAX_N], B[MAX_M];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < M; ++i)
		cin >> B[i];

	// B가 만들 수 있는 경우의 수를 기준
	for (int i = 0; i < M; ++i) {
		// for (int j = i + 1; )
	}



	return 0;
}