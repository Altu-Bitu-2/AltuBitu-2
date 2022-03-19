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

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            tmp *= 2;
            ch.push('(');
        }
        else if (str[i] == ')')
        {
            if (ch.top() != '(' || ch.empty())
            {
                res = 0;
                break;
            }

            if (str[i - 1] == '(')
            {
                res += tmp;
                tmp /= 2;
                ch.pop();
            }
            else if (ch.top() == '(')
            {
                tmp /= 2;
                ch.pop();
            }
            else
            {
                res = 0;
                break;
            }
        }

        else if (str[i] == '[')
        {
            tmp *= 3;
            ch.push('[');
        }
        else if (str[i] == ']')
        {
            if (ch.top() != '[' || ch.empty())
            {
                res = 0;
                break;
            }

            if (str[i - 1] == '[')
            {
                res += tmp;
                tmp /= 3;
                ch.pop();
            }
            else if (ch.top() == '[')
            {
                tmp /= 3;
                ch.pop();
            }
            else
            {
                res = 0;
                break;
            }
        }
    }

    if (ch.empty())
    {
        cout << res;
    }
    else
    {
        cout << "0";
    }

    return 0;
}
