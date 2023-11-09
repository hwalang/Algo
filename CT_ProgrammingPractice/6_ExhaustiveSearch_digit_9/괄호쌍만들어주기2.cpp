#include <iostream>
#include <string>
using namespace std;

string input;

int main() {
	cin >> input;

	int size = input.size();
	int ans = 0;
	for (int i = 0; i < size - 3; ++i) {
		if (input[i] != '(' || input[i + 1] != '(') continue;
		for (int j = i + 2; j < size - 1; ++j) {
			if (input[j] != ')' || input[j + 1] != ')') continue;
			ans++;
		}
	}

	cout << ans;

	return 0;
}