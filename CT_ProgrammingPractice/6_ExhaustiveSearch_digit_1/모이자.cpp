#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100

int N;
int house[MAX_N];
int min_dist = INT_MAX;

int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> house[i];

	// 최소 거리 구하기
	int cnt = N;
	for (int i = 0; i < N; ++i) {	// i: 모이는 집 번호

		int sum = 0;
		int dist = 0;	// i번 집과의 거리
		int j = i;		// 현재 집
		bool flag = false;
		while (cnt--) {
			if (j >= N) {
				j = j % N;
				dist = i;
				flag = true;
			}
				
			// std::cout << "J: " << j << " dist: " << dist << " house[j]: " << house[j] << "\n";
			sum += (house[j] * dist);
			if (flag)
				dist--;
			else
				dist++;
			j++;
			
		}

		// std::cout << "sum: " << sum << "\n";

		min_dist = std::min(min_dist, sum);
		cnt = N;
	}

	std::cout << min_dist;

	return 0;
}