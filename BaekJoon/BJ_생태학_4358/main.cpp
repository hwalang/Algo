#include <iostream>
#include <string>
#include <map>
using namespace std;

int totalCnt;
map<string, int> wordCount;

int main() {
	string input;
	while (getline(cin, input)) {
		wordCount[input]++;
		totalCnt++;
	}

	cout << fixed; cout.precision(4);
	double ratio;
	for (auto it = wordCount.begin(); it != wordCount.end(); ++it) {
		ratio = it->second / (double)totalCnt * 100;
		cout << it->first << " " << ratio << "\n";
	}
		

	return 0;
}