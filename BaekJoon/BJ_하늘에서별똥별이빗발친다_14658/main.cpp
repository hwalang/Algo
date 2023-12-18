#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, M, L, K, max_cnt;	// max_cnt: 튕겨낸 별똥별의 최대 개수
vector<pair<int, int>> v;

void Input() {
	cin >> N >> M >> L >> K;
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
}

void Solution() {
	for (int i = 0; i < K; ++i) {
		// 좌상단 좌표
		int x = v[i].first;
		int y = v[i].second;
		
		// 좌상단 좌표를 기준으로 L크기를 탐색 ---> 기준을 어케하지
		int cnt = 0;
		for (int j = 0; j < K; ++j) {
			int check_x = v[j].first;
			int check_y = v[j].second;

			if (check_x <= x + L && check_y <= y + L && check_x >= x && check_y >= y)
				++cnt;
		}
		max_cnt = max(max_cnt, cnt);
	}
}

int main() {

	Input();

	// 튕겨낸 별똥별의 최대 개수 구하기
	Solution();

	cout << K - max_cnt;	// 지구에 떨어진 별똥별의 최소 개수

	return 0;
}