/* 그룹 단어 체커 */

#include <bits/stdc++.h>
using namespace std;

bool grpCheck(string str){
    bool ch[26] = {false};

    for(int i=0; i<str.length(); i++){
        if(ch[str[i]-'a']){
            return false;
        }
        else {

            char tmp = str[i];
        
            ch[str[i]-'a'] = true;

            while(true){
                if(tmp != str[i++]){
                    i--;
                    break;
                }
            }
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, res=0;
    string word;

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> word;

        if (grpCheck(word)){
            res++;
        }
    }

    cout << res;

    return 0;
}