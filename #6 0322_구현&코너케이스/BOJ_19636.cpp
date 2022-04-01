/* 요요 시뮬레이션 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int weight, basic, t, d, eat, work;
    cin >> weight >> basic >> t;
    cin >> d >> eat >> work;

    int p_weight = weight, pt_weight = weight, pt_basic = basic;

    for (int i = 0; i < d; i++)
    {
        p_weight = p_weight + eat - (basic + work);
        pt_weight = pt_weight + eat - (pt_basic + work);

        if (abs(eat - (pt_basic + work)) > t)
            pt_basic = pt_basic + floor((eat - (pt_basic + work)) / 2.0);
    }

    if (p_weight <= 0)
    {
        cout << "Danger Diet"
             << "\n";
    }
    else
    {
        cout << p_weight << ' ' << basic << "\n";
    }

    if (pt_weight <= 0 || pt_basic <= 0)
    {
        cout << "Danger Diet"
             << "\n";
    }
    else
    {
        cout << pt_weight << ' ' << pt_basic << ' ';

        if (basic - pt_basic > 0)
        {
            cout << "YOYO";
        }
        else
        {
            cout << "NO";
        }

        return 0;
    }
}