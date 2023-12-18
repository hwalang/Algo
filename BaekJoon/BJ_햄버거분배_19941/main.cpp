#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
반례
8 3
PPHHHHPP

for ( i-K ~ i+K ) 
	1. 왼쪽은 먼 것부터 탐색
	2. 오른쪽은 가장 가까운 것부터 탐색
*/

int N, K, ans;
int dir[2];			// 왼쪽, 오른쪽을 살펴서 햄버거인지 판단
vector<int> loc;

void Input() {
	cin >> N >> K;
	string input;
	cin >> input;
	for (int i = 0; i < N; ++i) {
		if (input[i] == 'H')
			loc.push_back(1);
		else
			loc.push_back(-1);
	}
	dir[0] = -K;
	dir[1] = K;
}

int IsEat(int idx) {	// 먹을 수 있나 - (0: 못먹음)

	int ret_idx = 0;

	for (int i = 0; i < 2; ++i) {
		int tgt_idx = idx + dir[i];		// 현재 위치에서 가장 먼 위치(cur +- K)부터 햄버거를 판단
		int cnt = K;
		while (cnt >= 1) {
			if (tgt_idx < 0 || tgt_idx >= N || tgt_idx == idx) break;
			if (loc[tgt_idx] >= 1) {
				--loc[tgt_idx];			// 한 입!
				ret_idx = dir[i];
				return ret_idx;
			}
			--cnt;
			--tgt_idx;
		}
		
	}

	return ret_idx;
}

void Solution() {
	for (int i = 0; i < N; ++i) {
		if (loc[i] != -1) continue;	// 사람이 아니면 스킵
		if (IsEat(i) != 0)			// 먹었으면 ++ans
			++ans;
	}
}

int main() {

	Input();

	Solution();

	cout << ans;

	return 0;
}