#include <iostream>
using namespace std;

#define MAX_N 100

int N, ans;
int nums[MAX_N];

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	ans = N;	// �ϳ��� ������ ��հ� ���� ���� ����.

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			// ��� ���ϱ�
			int sum = 0;
			double avg = 0;
			for (int k = i; k <= j; ++k)
				sum += nums[k];
			avg = (double)sum / (j - i + 1);

			// ���� ���� ��հ� ��ġ�ϴ� ���� ã��
			for (int k = i; k <= j; ++k) {
				if (avg == nums[k]) {
					ans++;
					break;
				}
			}
		} 
	}

	cout << ans;

	return 0;
}