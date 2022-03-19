/* 통계학 */

#include <bits/stdc++.h>

#define MAX(A, B) A > B ? A : B
#define MIN(A, B) A < B ? A : B

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0, num[500001], cnt[8001], max = 0, flag = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];
        cnt[num[i] + 4000]++;
    }

    sort(num, num + n);

    for (int i = 0; i < 8001; i++)
    {
        if (cnt[i] > max)
        {
            max = cnt[i];
            flag = i;
        }
    }

    for (int i = flag + 1; i < 8001; i++)
    {
        if (cnt[i] == max)
        {
            flag = i;
            break;
        }
    }

    cout << round(double(sum) / n) << '\n'
         << num[(n - 1) / 2] << '\n'
         << flag - 4000 << '\n'
         << num[n - 1] - num[0];

    return 0;
}
