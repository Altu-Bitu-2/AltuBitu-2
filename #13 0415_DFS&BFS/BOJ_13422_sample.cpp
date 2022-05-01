#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {
    //윈도우 초기화
    int money = 0;  // 돈 초기화
    for (int i = 0; i < m; i++) {   // 도둑이 돈을 훔칠 연속된 집의 개수만큼 반복
        money += house[i];  // 집에 보관 중인 돈 money에 더하기
    }
    int ans = money < k; // 훔쳐야 하는 집 초기화

    if (n == m) { // 훔칠 수 있는 경우 딱 1개인 경우
        return ans; // 가짓수 반환
    }
    for (int i = m; i < n + m - 1; i++) {   // n+m-1만큼 반복
        money -= house[i - m];  // 훔친 돈 감소
        money += house[i % n];  // 훔친 돈 증가
        if (money < k) {    // 방범 장치 작동하지 않으면
            ans++;  // 가짓수 증가
        }
    }
    return ans; // 가짓수 반환
}

int main() {
    int t, n, m, k;     // 테스트 데이터 개수, 집의 개수, 도둑이 돈을 훔칠 집의 개수, 돈의 양

    cin >> t;   // 테스트 데이터 개수 입력
    while (t--) {   // 테스트 데이터 개수만큼 반복
        //입력
        cin >> n >> m >> k; // n, m, k 입력받기
        vector<int> house(n, 0);    // 각 집 보관 돈
        for (int i = 0; i < n; i++) {   // 집의 개수만큼 반복
            cin >> house[i];    // 보관 중인 돈의 양 입력
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';  // 도둑이 돈을 훔치는 방법의 가짓수
    }
    return 0;
}