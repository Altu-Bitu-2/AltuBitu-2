/* 요세푸스 문제 0 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    queue<int> que;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        que.push(i + 1);
    }

    cout << "<";

    while (!que.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            que.push(que.front());
            que.pop();
        }

        cout << que.front();
        que.pop();

        if (!que.empty())
        {
            cout << ", ";
        }
    }

    cout << ">";

    return 0;
}
