#include <iostream>
#include <algorithm>

namespace Ans {
#define MAX_NUM 10000

    using namespace std;

    int n, k;
    int arr[MAX_NUM + 1];

    int Answer() {
        // �Է�
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int x; char c;
            cin >> x >> c;

            if (c == 'G')
                arr[x] = 1;
            else
                arr[x] = 2;
        }

        // ��� ������ �������� ��ƺ��ϴ�.
        int max_sum = 0;
        for (int i = 0; i <= MAX_NUM - k; i++) {
            // �ش� ���� �� ������ ���� ���մϴ�.
            int sum = 0;
            for (int j = i; j <= i + k; j++)    //  i + k���� ����
                sum += arr[j];

            // �ִ��� ���մϴ�.
            max_sum = max(max_sum, sum);
        }

        cout << max_sum;
        return 0;
    }
}
