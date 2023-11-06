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

        // �� i��° ������ ���� ���� ���� �����ݴϴ�.
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int sum_dist = 0;
            for (int j = 0; j < n; ++j)
                sum_dist += abs(j - i) * a[j];

            // ������ �Ÿ��� �� �� �ּڰ��� �����ݴϴ�.
            ans = min(ans, sum_dist);
        }

        cout << ans;
        return 0;
    }
}