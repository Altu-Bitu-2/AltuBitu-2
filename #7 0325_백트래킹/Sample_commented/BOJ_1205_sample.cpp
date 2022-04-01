/* 등수 구하기 */

#include <iostream>
#include <vector>

using namespace std;

int findRanking(int n, int new_score, int p, vector<int> &ranking) {
    int idx = 1;    // 인덱스
    int ans = 1;    // 랭킹리스트에서 순위
    //새로운 점수를 어느 위치에 넣을지 탐색
    while (idx <= n) {  // 인덱스 1~n까지 반복
        if (new_score > ranking[idx]) {     // 새로운 점수가 랭킹의 점수보다 크면
            break;  // 반복문 종료
        }
        if (new_score < ranking[idx]) {     // 새로운 점수가 랭킹의 점수보다 크면
            ans = idx + 1;   // 랭킹리스트에서 순위는 인덱스+1
        }
        idx++;  // 인덱스 증가
    }
    if (idx == p + 1) { //랭킹 리스트에 들어가지 못하는 경우 : 인덱스가 p+1과 같을 경우
        return -1;  // -1 반환
    }
    return ans; // 랭킹리스트에서 등수 반환
}

int main() {
    int n, new_score, p;    // n:점수 개수, new_score:태수의 새로운 점수, p

    cin >> n >> new_score >> p;     // 입력 받기
    vector<int> ranking(p + 1, 0);  // 링킹리스트에 있는 점수
    for (int i = 1; i <= n; i++) {  // 점수의 개수만큼 반복
        cin >> ranking[i];  // 랭킹리스트에 있는 점수 입력받기
    }

    cout << findRanking(n, new_score, p, ranking);  // 새로운 점수의 랭킹리스트 순위 연산 -> 출력
    return 0;
}