#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string binary;
int ans;

void Change(string& newBinary, int idx) {
	if (newBinary[idx] == '1')
		newBinary[idx] = '0';
	else
		newBinary[idx] = '1';
}

int BinaryToDecimal(string& newBinary, int size) {
	int num = 0;
	for (int i = 0; i < size; ++i)
		num = num * 2 + (newBinary[i] - '0');

	return num;
}

int main() {
	cin >> binary;
	int b_size = binary.size();

	for (int i = 0; i < b_size; ++i) {
		// 이진수에서 한 자리를 바꾼다.
		string newBinary = binary;
		Change(newBinary, i);

		// 10진수로 표현한다.
		int decimal = BinaryToDecimal(newBinary, b_size);

		// max 갱신
		ans = max(ans, decimal);
	}

	cout << ans;

	return 0;
}