#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>

namespace Ans {
#define MAX_N 100

    using namespace std;

    int n;
    int a[MAX_N];

    int Answer() {
        // �Է�
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // �������� ���� ��� ���� �� ��ƺ��ϴ�.
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            // �ڿ������� �ߺ��Ǵ� �� ���� �����Ѵ�.
            for (int j = i + 2; j < n; j++)
                if (ans < a[i] + a[j])
                    ans = a[i] + a[j];

        cout << ans;

        return 0;
    }
}
