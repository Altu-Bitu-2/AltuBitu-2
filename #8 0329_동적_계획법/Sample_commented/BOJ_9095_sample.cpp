/* 1,2,3 더하기 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(int n, vector<int> &arr) {
    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) { //증가하는 관계라면
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]); //최장 길이 갱신
    }
    return ans;
}

int lisAdv(int n, vector<int> &arr) {
    vector<int> dp(n + 1, 0); //dp[1]을 갱신하기 위해 dp[0] = 0으로 설정
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = idx; j >= 0; j--) {
            if (arr[i] > dp[j]) { //증가하는 관계라면
                dp[j + 1] = arr[i];
                if (j == idx) { //최장 길이 갱신
                    idx++;
                }
                break;
            }
        }
    }
    return idx;
}

int lisFinal(int n, vector<int> &arr) {
    vector<int> dp;

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); //arr[i] 이상의 값이 처음 나오는 위치
        if (pos == dp.size()) { //arr[i]가 가장 크다면 pos 값이 dp.size()와 같음 -> 최장 길이 갱신
            dp.push_back(arr[i]);
        }
        dp[pos] = arr[i]; //dp[pos]의 값이 arr[i]이상이므로 더 작은 arr[i]로 덮어 씌우기
    }
    return dp.size();
}

int main() {
    int n;  // 정수 n

    cin >> n;  // n 입력받기
    vector<int> arr(n, 0);  // 테스트케이스
    for (int i = 0; i < n; i++) {   // n만큼 반복
        cin >> arr[i];   // 테스트케이스 입력받기
    }

    cout << lis(n, arr);    // 방법의 수 연산+출력
    return 0;
}