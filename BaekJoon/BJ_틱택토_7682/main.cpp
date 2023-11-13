#include <iostream>
#include <string>
using namespace std;

#define MAX_B 3

string input;
char board[MAX_B][MAX_B];


bool IsFull() {

	// 빈칸이 존재하면 false
	// 빈칸이 존재하지 않으면 X는 5개 O는 4개.
	int cnt_x = 0;
	int cnt_o = 0;
	for (int i = 0; i < MAX_B; ++i) {
		for (int j = 0; j < MAX_B; ++j) {
			if (board[i][j] == '.')
				return false;
			else if (board[i][j] == 'X')
				cnt_x++;
			else if (board[i][j] == 'O')
				cnt_o++;
		}
	}

	if (cnt_x == 5 && cnt_o == 4)
		return true;
	return false;
}

bool WinO() {
	
	// O는 3개가 존재하지만, X는 3개가 존재하면 안 된다.
	
	// 가로 판단

	// 세로 판단

	// 대각선 2개 판단

	return false;
}

bool IsValid() {

	if (IsFull())
		return true;
	else if (WinO())
		return true;
	//else if (WinX())
	//	return true;


	return false;
}

int main() {
	while (true) {
		cin >> input;
		if (input == "end") break;

		// board 세팅
		int size = input.size();
		int input_idx = 0;
		for (int i = 0; i < MAX_B; ++i) {
			for (int j = 0; j < MAX_B; ++j)
				board[i][j] = input[input_idx++];
		}

		if (IsValid())
			cout << "valid" << "\n";
		else 
			cout << "invalid" << "\n";
	}

	return 0;
}