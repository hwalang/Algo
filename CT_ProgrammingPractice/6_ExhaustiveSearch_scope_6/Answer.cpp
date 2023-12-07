#include <iostream>
#include <algorithm>

/*
[i, j] ������ �����Ѵ�.
�ش� ���� ������ ������ �����ϸ� max_len�� �����Ѵ�.
*/

namespace Ans {
#define MAX_NUM 100

	using namespace std;

	int n, k;
	int arr[MAX_NUM + 1];

	int Answer() {
		// �Է�
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x; char c;
			cin >> x >> c;

			if (c == 'G')
				arr[x] = 1;
			else
				arr[x] = 2;
		}

		// ��� ������ �������� ��ƺ��ϴ�.
		int max_len = 0;
		for (int i = 0; i <= MAX_NUM; i++) {
			for (int j = i + 1; j <= MAX_NUM; j++) {
				// i�� j ��ġ�� ����� �ִ��� Ȯ���մϴ�.
				if (arr[i] == 0 || arr[j] == 0)
					continue;

				// �ش� ���� �� g�� h�� ������ ���մϴ�.
				int cnt_g = 0;
				int cnt_h = 0;

				for (int k = i; k <= j; k++) {
					if (arr[k] == 1)
						cnt_g++;
					if (arr[k] == 2)
						cnt_h++;
				}

				// ������ ������ �� ������ ���̸� ���� �ִ񰪰� ���մϴ�.
				if (cnt_g == 0 || cnt_h == 0 || cnt_g == cnt_h) {
					int len = j - i;
					max_len = max(max_len, len);
				}
			}
		}

		cout << max_len;

		return 0;
	}
}