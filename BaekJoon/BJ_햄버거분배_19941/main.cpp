#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
�ݷ�
8 3
PPHHHHPP

for ( i-K ~ i+K ) 
	1. ������ �� �ͺ��� Ž��
	2. �������� ���� ����� �ͺ��� Ž��
*/

int N, K, ans;
int dir[2];			// ����, �������� ���켭 �ܹ������� �Ǵ�
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

int IsEat(int idx) {	// ���� �� �ֳ� - (0: ������)

	int ret_idx = 0;

	for (int i = 0; i < 2; ++i) {
		int tgt_idx = idx + dir[i];		// ���� ��ġ���� ���� �� ��ġ(cur +- K)���� �ܹ��Ÿ� �Ǵ�
		int cnt = K;
		while (cnt >= 1) {
			if (tgt_idx < 0 || tgt_idx >= N || tgt_idx == idx) break;
			if (loc[tgt_idx] >= 1) {
				--loc[tgt_idx];			// �� ��!
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
		if (loc[i] != -1) continue;	// ����� �ƴϸ� ��ŵ
		if (IsEat(i) != 0)			// �Ծ����� ++ans
			++ans;
	}
}

int main() {

	Input();

	Solution();

	cout << ans;

	return 0;
}