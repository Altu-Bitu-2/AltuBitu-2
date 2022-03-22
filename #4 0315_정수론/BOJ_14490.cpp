/* 백대열 */

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

    int n, m, res;

    scanf("%d:%d", &n, &m);

    res = gcdIter(n, m);

    printf("%d:%d", n / res, m / res);

    return 0;
}
