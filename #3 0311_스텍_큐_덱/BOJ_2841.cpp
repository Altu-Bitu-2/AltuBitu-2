/* 외계인의 기타 연주 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, ln, pn, cnt = 0;
    vector<stack<int>> v(7);

    cin >> n >> p;

    for (int i = 0; i < n; i++)
    {
        cin >> ln >> pn;

        if (v[ln].top() > pn && !v[ln].empty())
        {
            while (v[ln].top() > pn && !v[ln].empty())
            {
                v[ln].pop();
                cnt++;
            }
        }

        if (v[ln].top() < pn || v[ln].empty())
        {
            v[ln].push(pn);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
