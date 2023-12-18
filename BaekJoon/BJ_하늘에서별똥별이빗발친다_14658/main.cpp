#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, M, L, K, max_cnt;	// max_cnt: ƨ�ܳ� ���˺��� �ִ� ����
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
		// �»�� ��ǥ
		int x = v[i].first;
		int y = v[i].second;
		
		// �»�� ��ǥ�� �������� Lũ�⸦ Ž�� ---> ������ ��������
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

	// ƨ�ܳ� ���˺��� �ִ� ���� ���ϱ�
	Solution();

	cout << K - max_cnt;	// ������ ������ ���˺��� �ּ� ����

	return 0;
}