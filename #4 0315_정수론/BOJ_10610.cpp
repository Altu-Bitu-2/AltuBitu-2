/* 30 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string num, res = "";
    vector<int> v;
    int sum = 0;

    cin >> num;

    for (int i = 0; i < num.length(); i++)
    {
        v.push_back(num[i]);
        sum += num[i] - '0';
    }

    sort(v.begin(), v.end());

    if (v.front() != '0' || sum % 3 != 0)
    {
        cout << -1;
    }
    else
    {
        for (int i = v.size(); i > 0; i--)
        {
            res += v[i - 1];
        }
        cout << res;
    }

    return 0;
}