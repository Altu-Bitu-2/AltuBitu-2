/* 괄호의 값 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    stack<char> ch;
    int res = 0, tmp = 1;
    bool imp = false;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            tmp *= 2;
            ch.push('(');
        }
        else if (str[i] == '[')
        {
            tmp *= 3;
            ch.push('[');
        }
        else if (str[i] == ')')
        {
            if (ch.top() != '(' || (ch.empty() || ch.top() != '('))
            {
                imp = true;
                break;
            }
            else
            {
                if (str[i - 1] == '(')
                {
                    res += tmp;
                }
                tmp /= 2;
                ch.pop();
            }
        }
        else if (str[i] == ']')
        {
            if (ch.top() != '[' || (ch.empty() || ch.top() != '['))
            {
                imp = true;
                break;
            }
            else
            {
                if (str[i - 1] == '[')
                {
                    res += tmp;
                }
                tmp /= 3;
                ch.pop();
            }
        }
    }

    if (!ch.empty() || imp)
    {
        cout << 0;
    }
    else
    {
        cout << res;
    }

    return 0;
}
