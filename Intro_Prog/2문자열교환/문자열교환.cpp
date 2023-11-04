#include <iostream>
#include <cmath>

int main()
{
	std::string s;
	std::cin >> s;

	int a_len = 0;
	int ans = s.size();
	for (int i = 0; i < ans; ++i)
		if (s[i] == 'a') ++a_len;

	for (int i = 0; i < s.size(); ++i) 
	{
		int aCnt = a_len;	// 'a'�� ���Ƴִ� ����
		int bCnt = 0;		// ��ȯ�� 'b' ����
		for (int j = i; j < i + s.size(); ++j)
		{
			// a�� �� ������ ���ȱ� ������ ����
			if (aCnt == 0) break;
			if (s[j % s.size()] == 'b')	// a�� b�� swap
			{
				++bCnt;
				--aCnt;
			}
			else  // �� ��ġ�� ���ڰ� a
				--aCnt;
		}
		ans = std::min(ans, bCnt);
	}

	std::cout << ans;

	return 0;
}