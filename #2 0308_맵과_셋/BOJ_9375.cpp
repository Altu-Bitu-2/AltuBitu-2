/* 패션왕 신해빈 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    string name, type;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        map<string, int> m;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> name >> type;
            if (m.find(type) == m.end())
            {
                m.insert({type, 1});
            }
            else
                m[type]++;
        }

        int res = 1;
        for (auto i : m)
        {
            res *= (i.second + 1);
        }
        res -= 1;
        cout << res << '\n';
    }

    return 0;
}
