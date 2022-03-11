/* 창용이의 시계 */

#include <bits/stdc++.h>
using namespace std;

#define DAY 86400

void print_t(int sum)
{
    int ph, pm, ps;

    if (sum < 0)
    {
        sum += DAY;
    }

    ph = sum / 3600;
    pm = sum % 3600 / 60;
    ps = sum % 60;

    cout << ph << ' ' << pm << ' ' << ps << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, m, s, q, sum, t, c;

    cin >> h >> m >> s;
    cin >> q;

    sum = 3600 * h + 60 * m + s;

    for (int i = 0; i < q; i++)
    {
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> c;
            sum += c;
            break;
        case 2:
            cin >> c;
            sum -= c;
            break;
        case 3:
            sum %= DAY;
            print_t(sum);
            break;
        }
    }

    return 0;
}