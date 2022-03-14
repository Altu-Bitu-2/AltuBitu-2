/* 암기왕 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, num;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        map<int, int> note;

        for (int j = 0; j < n; j++)
        {
            cin >> num;
            note[num] = 1;
        }

        cin >> m;
        for (int k = 0; k < m; k++)
        {
            cin >> num;
            if (note[num] == 1)
                cout << "1"
                     << "\n";
            else
                cout << "0"
                     << "\n";
        }
    }
    return 0;
}