#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>

namespace Ans {
#define MAX_N 1003

    using namespace std;

    int n;
    int a[MAX_N];

    int Answer() {
        // 입력
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // i번째 방에서 출발했을 경우의 결과를 구해줍니다.
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum_dist = 0;
            for (int j = 0; j < n; j++) {
                int dist = (j + n - i) % n;
                sum_dist += dist * a[j];
            }

            // 가능한 거리의 합 중 최솟값을 구해줍니다.
            ans = min(ans, sum_dist);
        }

        cout << ans;
        return 0;
    }
}