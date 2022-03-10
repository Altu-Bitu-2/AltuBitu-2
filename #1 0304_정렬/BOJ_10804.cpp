/* 카드 역배치 */

#include <bits/stdc++.h>
using namespace std;

int arr[21];

void arrange(int st, int ed)
{
    for (int j = 0; j < (ed - st + 1) / 2; j++)
    {
        if (st + j != ed - j)
        {
            swap(arr[st + j - 1], arr[ed - j - 1]);
        }
        else
        {
            continue;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x = 0, y = 0;

    for (int i = 0; i < 20; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        cin >> x >> y;

        arrange(x, y);
    }

    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}