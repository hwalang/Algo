#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 1003

int room[MAX_N];
int N, min_dist = INT_MAX;


int main() {
	// input
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> room[i];

	// 시작 인덱스 정하기
	for (int sidx = 0; sidx < N; ++sidx) {

		// 시작 인덱스에서 이동시 총 거리
		int sum_dist = 0, dist = 0;
		int times = N, start_idx = sidx;
		while (times--) {
			start_idx = start_idx % N;
			sum_dist += (room[start_idx] * dist);
			dist++;
			start_idx++;
		}
		// 최소 이동 거리 갱신
		min_dist = min(min_dist, sum_dist);
	}

	cout << min_dist;

	
	return 0;
}