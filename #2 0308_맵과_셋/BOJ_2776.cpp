/* 암기왕 */

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int t, n, m, num;
    unordered_map<int, int> note;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        note.clear();

        while (n--)
        {
            scanf("%d", &num);
            note[num] = 1;
        }

        scanf("%d", &m);
        while (m--)
        {
            scanf("%d", &num);
            if (note[num] == 1)
                printf("1\n");

            else
                printf("0\n");
        }
    }
    return 0;
}