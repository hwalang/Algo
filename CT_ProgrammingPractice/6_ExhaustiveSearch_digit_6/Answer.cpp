#include <iostream>
#include <climits>

namespace Ans {

	using namespace std;

	int Answer() {
		// ���� ���� �� �Է�
		string binary;
		cin >> binary;

		// �� i��° �ڸ����� �ٲپ��� ���� ������ ���� �����ݴϴ�.
		int ans = INT_MIN;
		for (int i = 0; i < (int)binary.size(); i++) {
			// i��° �ڸ����� �ٲߴϴ�.
			binary[i] = '0' + '1' - binary[i];
			// �������� ��ȯ�մϴ�.
			int num = 0;
			for (int j = 0; j < (int)binary.size(); j++)
				num = num * 2 + (binary[j] - '0');

			// ������ ������ �� �� �ִ��� �����ݴϴ�.
			ans = max(ans, num);

			// i��° �ڸ����� ������� ���������ϴ�.
			binary[i] = '0' + '1' - binary[i];
		}

		// ���
		cout << ans;

		return 0;
	}
}