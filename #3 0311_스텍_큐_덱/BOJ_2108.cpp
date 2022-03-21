/* 통계학 */

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0, num[500001], cnt[8001], max = 0, flag = 0;

    cin >> n;

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

    if (round((double)sum / n) == -0)
        cout << "0\n";
    else
        cout << round((double)sum / n) << '\n';

    cout << num[(n - 1) / 2] << '\n'
         << flag - 4000 << '\n'
         << num[n - 1] - num[0];

    return 0;
}