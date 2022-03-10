/* 알바생 강호 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0;

    cin >> n;

    vector<int> tip(n);

    for (int i = 0; i < n; i++)
    {
        cin >> tip[i];
    }

    sort(tip.rbegin(), tip.rend());

    for (int i = 0; i < n; i++)
    {
        if (tip[i] - i > 0)
        {
            sum += tip[i] - i;
        }
    }

    cout << sum;

    return 0;
}