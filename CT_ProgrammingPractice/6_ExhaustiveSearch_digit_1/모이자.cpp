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

	// �ּ� �Ÿ� ���ϱ�
	int cnt = N;
	for (int i = 0; i < N; ++i) {	// i: ���̴� �� ��ȣ

		int sum = 0;
		int dist = 0;	// i�� ������ �Ÿ�
		int j = i;		// ���� ��
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