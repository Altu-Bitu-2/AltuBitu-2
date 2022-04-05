/* 2xn 타일링 2 */

#include <iostream>
#include <vector>

using namespace std;
const int MOD = 10007;

int fillTile(int n) {
    vector<int> dp(n + 1, 0);

    if (n == 1) {   // n이 1인 경우는...
        return 1;   // 방법이 1개 - 반환
    }

    dp[1] = 1;  // 너비가 1인 경우 1로 초기화
    dp[2] = 3;  // 너비가 2인 경우 3로 초기화
    for (int i = 3; i <= n; i++) {  // 3~n까지 반복
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        dp[i] %= MOD; // 모듈러 연산
    }
    return dp[n];   // 방법의 수 반환
}

int main() {
    int n;  // 2xn의 숫자 n

    cin >> n;   // n 입력받기

    cout << fillTile(n);    // 직사각형을 채우는 방법의 수 연산+출력
    return 0;
}