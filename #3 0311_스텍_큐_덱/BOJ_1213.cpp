/* 팰린드롬 만들기 */

#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string name, palin, rev;
    char oddChar = 'z';
    int cnt = 0;

    cin >> name;

    for (int i = 0; i < name.size(); i++)
    {
        arr[name[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2 != 0)
        {
            cnt++;
        }
    }

    if (cnt > 1)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr[i])
            {
                for (int j = 0; j < arr[i] / 2; j++)
                {
                    palin += i + 'A';
                }
            }

            if (arr[i] % 2 == 1)
                oddChar = i + 'A';
        }
    }

    cout << palin;

    if (oddChar != 'z')
    {
        cout << oddChar;
    }

    reverse(palin.begin(), palin.end());

    cout << palin;

    return 0;
}
