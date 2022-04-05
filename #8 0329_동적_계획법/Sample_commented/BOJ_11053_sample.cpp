/* 가장 긴 증가하는 부분 수열 */

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10;

//bottom-up 방식 dp 배열 채우기
vector<int> numberOfAllCases() {
    vector<int> dp(MAX + 1, 0);

    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= MAX; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp;
}

int main() {
    int t, n;   // 수열의 크기 t, 

    //미리 dp 채우기
    vector<int> dp = numberOfAllCases();

    cin >> t;
    while (t--) {
        cin >> n;

        //출력
        cout << dp[n] << '\n';
    }
    return 0;
}