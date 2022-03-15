/* 서로 다른 부분 문자열의 개수 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str, res;
    set<string> s;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i; j < str.size(); j++)
        {
            res += str[j];
            s.insert(res);
        }
        res.clear();
    }

    cout << s.size();

    return 0;
}
