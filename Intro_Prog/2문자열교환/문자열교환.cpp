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
		int aCnt = a_len;	// 'a'를 몰아넣는 갯수
		int bCnt = 0;		// 교환할 'b' 갯수
		for (int j = i; j < i + s.size(); ++j)
		{
			// a가 한 곳으로 몰렸기 때문에 종료
			if (aCnt == 0) break;
			if (s[j % s.size()] == 'b')	// a와 b의 swap
			{
				++bCnt;
				--aCnt;
			}
			else  // 현 위치의 문자가 a
				--aCnt;
		}
		ans = std::min(ans, bCnt);
	}

	std::cout << ans;

	return 0;
}