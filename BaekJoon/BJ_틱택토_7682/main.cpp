#include <iostream>
#include <string>
using namespace std;

#define MAX_B 3

string input;
char board[MAX_B][MAX_B];


bool IsFull() {

	// ��ĭ�� �����ϸ� false
	// ��ĭ�� �������� ������ X�� 5�� O�� 4��.
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
	
	// O�� 3���� ����������, X�� 3���� �����ϸ� �� �ȴ�.
	
	// ���� �Ǵ�

	// ���� �Ǵ�

	// �밢�� 2�� �Ǵ�

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

		// board ����
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