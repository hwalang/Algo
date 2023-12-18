#include <iostream>

using namespace std;

const int SIZE = 100'000;
int N;
int nums[SIZE + 1];
long ans;

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];


	cout << ans;

	return 0;
}