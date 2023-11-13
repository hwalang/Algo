#include <iostream>
#include <climits>

namespace Ans {
    using namespace std;

#define MAX_N 100

    int n, s;
    int arr[MAX_N];
    int array_sum;
    int ans = INT_MAX;

    int Answer() {
        // �Է�
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // �迭�� ������ ������ �̸� ���صӴϴ�.
        for (int i = 0; i < n; i++)
            array_sum += arr[i];

        // ��� ���� �� ��ƺ��ϴ�.
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                // i���� j�� ���� ������ ��� ���� ���ڵ��� ������ ������ �����ϴ�.
                int new_sum = array_sum - arr[i] - arr[j];

                int diff = abs(new_sum - s);
                ans = min(ans, diff);
            }

        // ������ ����մϴ�.
        cout << ans;
        return 0;
    }
}
