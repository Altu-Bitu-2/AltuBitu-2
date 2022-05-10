/* 회전 초밥 */

#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int> &belt) {
    vector<int> sushi(d + 1, 0); //초밥 먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;  // 초기화
    sushi[c]++; // 쿠폰 번호 증가

    //윈도우 초기화
    for (int i = 0; i < k; i++) {   // 먹는 접시의 수만큼 반복
        if (!sushi[belt[i]]) {  // 초밥 먹은 개수가 0일 경우
            section_sushi++;    // 증가
        }
        sushi[belt[i]]++;   // 다음으로
    }

    int ans = section_sushi;    // 먹을 수 있는 개수 업데이트
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        sushi[belt[i - k]]--;   // 연속해서 먹는 접시의 수 반영
        if (!sushi[belt[i - k]]) {  // 0인 경우
            section_sushi--;    // 감소
        }
        if (!sushi[belt[i % n]]) {  
            section_sushi++;    // 증가
        }
        sushi[belt[i % n]]++;   
        ans = max(ans, section_sushi);  // 최대 개수 업데이트
    }
    return ans;     // 최대 개수 반환
}

int main() {
    int n, d, k, c;     // 회전 초밥 벨트에 놓인 접시 수, 초밥의 가짓수, 연속해서 먹는 접시 수, 쿠폰 번호

    //입력
    cin >> n >> d >> k >> c;    // n, d, k, c 입력받기
    vector<int> belt(n, 0);     // 초밥의 종류 입력받기
    for (int i = 0; i < n; i++) {   // 벨트에 놓인 접시 수만큼 반복
        cin >> belt[i];     // 초밥의 종류 입력받기
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);  // 먹을 수 있는 초밥의 가짓수의 최대값 연산 + 출력
    return 0;
}