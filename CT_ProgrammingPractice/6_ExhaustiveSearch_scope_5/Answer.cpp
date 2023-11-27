#include <iostream>
#include <algorithm>


namespace Ans {
#define MAX_NUM 100

    using namespace std;

    int n, k;
    int arr[MAX_NUM + 1];

    int Answer() {
        // �Է�
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int x, a;
            cin >> a >> x;

            arr[x] += a;
        }

        // ��� ������ �������� ��ƺ��ϴ�.
        int max_sum = 0;
        for (int i = 0; i <= MAX_NUM; i++) {
            // �ش� ���� �� ������ ���� ���մϴ�.
            int sum = 0;
            for (int j = i - k; j <= i + k; j++)
                if (j >= 0 && j <= MAX_NUM)
                    sum += arr[j];

            // �ִ��� ���մϴ�.
            max_sum = max(max_sum, sum);
        }

        cout << max_sum;
        return 0;
    }
}