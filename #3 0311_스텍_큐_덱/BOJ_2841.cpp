/* 외계인의 기타 연주 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, ln, pn, cnt = 0;
    stack<int> st[7];

    cin >> n >> p;

    for (int i = 0; i < n; i++)
    {
        cin >> ln >> pn;

        while (!st[ln].empty())
        {
            if (st[ln].top() == pn)
                break;
            else if (st[ln].top() > pn)
            {
                st[ln].pop();
                cnt++;
            }
            else
            {
                st[ln].push(pn);
                cnt++;
            }
        }
        if (st[ln].empty())
        {
            cnt++;
            st[ln].push(pn);
        }
    }

    cout << cnt;

    return 0;
}
