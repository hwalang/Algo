#include <iostream>
#include <string>
using namespace std;

string input;
int ans;

int main() {

	cin >> input;

	// 하나의 여는 괄호와 쌍을 이루는 닫는 괄호를 모두 찾는다.
	// 중복은 없다.
	int size = input.size();
	for (int i = 0; i < size; ++i) {
		// 여는 괄호를 찾는다.
		if (input[i] != '(') continue;

		// 닫는 괄호를 찾는다.
		for (int j = i + 1; j < size; ++j) {
			if (input[j] == ')') {
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}