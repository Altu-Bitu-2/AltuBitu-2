/* 통계학 */

#include <bits/stdc++.h>

using namespace std;

int num[500001], cnt[8002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, max = 0, tmp = 0, tc = 0;
    long long sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];
        cnt[num[i] + 4000]++;

        if (cnt[num[i] + 4000] > max)
        {
            max = cnt[num[i] + 4000];
            tmp = 0;
        }
        else if (cnt[num[i] + 4000] == max)
        {
            tmp++;
        }
    }

    cout << round((double)sum / n) << '\n';

    sort(num, num + n);
    cout << num[n / 2] << '\n';

    for (int i = 0; i <= 8000; i++)
    {
        if (max == cnt[i])
        {
            tc++;
            if (!tmp)
            {
                cout << i - 4000 << "\n";
                break;
            }
            if (tc == 2)
            {
                cout << i - 4000 << "\n";
                break;
            }
        }
    }

    cout << num[n - 1] - num[0];

    return 0;
}
