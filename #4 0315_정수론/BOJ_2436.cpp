/* 공약수 */

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int gcdIter(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, div, x;

    scanf("%d %d", &a, &b);

    div = b / a;

    for (int i = 1; i * i <= div; i++)
    {
        if (div % i == 0 && gcdIter(i, div / i) == 1)
        {
            x = i;
        }
    }

    cout << a * x << ' ' << a * (div / x);

    return 0;
}