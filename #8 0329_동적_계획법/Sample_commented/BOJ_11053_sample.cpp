/* 가장 긴 증가하는 부분 수열 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(int n, vector<int> &arr) {
    vector<int> dp(n, 1);
    int ans = 1;    // 결과 저장 변수 초기화

    for (int i = 1; i < n; i++) {   // n만큼 반복
        for (int j = 0; j < i; j++) {   //i만큼 반복 (1*1, 2*2, 3*3...)
            if (arr[i] > arr[j]) { //증가하는 관계라면
                dp[i] = max(dp[i], dp[j] + 1);  // dp 업데이트
            }
        }
        ans = max(ans, dp[i]); //최장 길이 갱신
    }
    return ans;
}

int main() {
    int n;  // 수열의 길이 n

    cin >> n;  // n 입력받기
    vector<int> arr(n, 0);  // 수열 A
    for (int i = 0; i < n; i++) {   // n만큼 반복
        cin >> arr[i];   // 수열 입력받기
    }

    cout << lis(n, arr);    // 수열의 길이 연산+출력
    return 0;
}