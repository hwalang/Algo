#include <iostream>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 100

int N;
pair<int, int> checkPoint[MAX_N];
int min_dist = INT_MAX;


int main() {
	cin >> N;
	int x, y;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		checkPoint[i] = { x, y };
		// cout << "x: " << checkPoint[i].first << " y: " << checkPoint[i].second << endl;
	}

	// 시작점과 끝점을 제외한 나머지를 하나씩 건너뛰어서 계산
	int tgt_idx = 1;
	for (int i = 1; i < N - 1; ++i) {	// 횟수

		// 건너뛰는 지점을 제외한 checkPoint
		int origin_idx = 0;
		int ncp_size = N - 1;
		pair<int, int> newCheckPoint[MAX_N];
		for (int x = 0; x < ncp_size; ++x) {
			if (x == tgt_idx) origin_idx++;
			newCheckPoint[x] = checkPoint[origin_idx++];
			// cout << "newCheckPoint: " << newCheckPoint[x].first << " " << newCheckPoint[x].second << endl;
		}

		// 총 거리 계산
		int dist = 0;
		for (int j = 0; j < ncp_size - 1; ++j) {
			pair<int, int> cur_point = newCheckPoint[j];
			pair<int, int> next_point = newCheckPoint[j + 1];

			int x_dist = abs(cur_point.first - next_point.first);
			int y_dist = abs(cur_point.second - next_point.second);

			// cout << "cur_point: " << cur_point.first << " " << cur_point.second << endl;
			// cout << "next_point: " << next_point.first << " " << next_point.second << endl;

			dist += (x_dist + y_dist);
		}
		// cout << "dist: " << dist << endl;

		// min_dist 갱신
		min_dist = min(min_dist, dist);

		tgt_idx++;
	}
	
	cout << min_dist;

	return 0;
}