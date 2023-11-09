#include <iostream>
using namespace std;

int N;
string input;

int main() {
	cin >> N;
	cin >> input;

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (input[i] != 'C') continue;
		for (int j = i + 1; j < N; ++j) {
			if (input[j] != 'O') continue;
			for (int k = j + 1; k < N; ++k) {
				if (input[k] != 'W') continue;
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}