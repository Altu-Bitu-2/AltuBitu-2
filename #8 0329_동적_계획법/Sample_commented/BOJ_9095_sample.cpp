/* 1, 2, 3 더하기 */

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10;

//bottom-up 방식 dp 배열 채우기
vector<int> numberOfAllCases() {
    vector<int> dp(MAX + 1, 0);     // 초기화

    dp[0] = dp[1] = 1;  // dp 1, 2를 1로 초기화 (방법의 수 1)
    dp[2] = 2;  // dp 2 2로 초기화 (방법의 수 2)
    for (int i = 3; i <= MAX; i++) {    // 3~10만큼 반복
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];  // dp 방법의 수 더하기
    }
    return dp;  // 방법의 수 반환
}

int main() {
    int t, n;   // 테스트케이스의 개수 t, 정수 n (11보다 작은 양수)

    vector<int> dp = numberOfAllCases();      //미리 dp 채우기

    cin >> t;   // t 입력받기
    while (t--) {   // t만큼 반복
        cin >> n;   // n 입력받기

        //출력
        cout << dp[n] << '\n';  // 테스트케이스 별 방법의 수 출력
    }
    return 0;
}