/* 분산처리 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, cp=1;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a >> b;

        for(int j=0; j<b; j++){
            cp = cp*a%10;
        }

        if(cp == 0){
            cout << 10 << '\n';
        }
        else {
            cout << cp << '\n';
        }

        cp = 1;
    }

    return 0;
}