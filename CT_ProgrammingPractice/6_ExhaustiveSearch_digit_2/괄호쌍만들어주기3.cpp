#include <iostream>
#include <string>
using namespace std;

string input;
int ans;

int main() {

	cin >> input;

	// �ϳ��� ���� ��ȣ�� ���� �̷�� �ݴ� ��ȣ�� ��� ã�´�.
	// �ߺ��� ����.
	int size = input.size();
	for (int i = 0; i < size; ++i) {
		// ���� ��ȣ�� ã�´�.
		if (input[i] != '(') continue;

		// �ݴ� ��ȣ�� ã�´�.
		for (int j = i + 1; j < size; ++j) {
			if (input[j] == ')') {
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}