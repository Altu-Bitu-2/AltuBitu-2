/* 양궁대회 */

#include <vector>
#include <iostream>

using namespace std;
const int SIZE = 10;

vector<int> answer = {-1}; // 라이언이 가장 큰 점수 차이로 우승하는 경우
int max_diff = 0; // 가장 큰 점수 차이

bool cmp(vector<int> &ryan) {   // 
    for (int i = SIZE; i >= 0; i--) {   // 10번 반복
        if (answer[i] > ryan[i]) {  // 라이언이 가장 큰 점수 차이로 우승하는 경우가 현재 과녁 정보보다 크면...?
            return false;   // 거짓 반환
        } else if (answer[i] < ryan[i]) {    // 라이언이 가장 큰 점수 차이로 우승하는 경우가 현재 과녁 정보보다 작으면...?
            return true;    // 참 반환
        }
    }
}

int calcDiff(vector<int> &ryan, vector<int> &apeach) {
    int score_r = 0, score_a = 0;   // 각자의 점수 0으로 초기화
    for (int i = 0; i <= SIZE; i++) {   // SIZE만큼 반복
        int score = SIZE - i;   // 반복마다 score에 저장되는 값이 1씩 감소
        if (ryan[i] > apeach[i]) {  // 라이언이 더 큰 점수면
            score_r += score;   // 라이언 점수 업데이트 (증가)
        } else if (ryan[i] < apeach[i]) {   // 어피치의 점수가 더 크면
            score_a += score;   // 어피치 점수 업데이트 (증가)
        }
    }
    return score_r - score_a;   // 라이언의 점수가 어피치의 점수보다 얼마나 큰지 반환
}

void backtracking(int cnt, int extra_arrows, vector<int> &ryan, vector<int> &apeach) {
    if (cnt == SIZE + 1 || extra_arrows == 0) { // (기저조건) 0점 과녁까지 탐색 or 남은 화살 없음
        ryan[SIZE] = extra_arrows; // 화살 남아있을 수 있으므로
        int curr_diff = calcDiff(ryan, apeach); // 현재 점수 차 (라이언이 얼마나 더 많이 획득?)
        if (max_diff < curr_diff) { // 가장 큰 점수 차이보다 현재 점수 차가 크다면
            max_diff = curr_diff;   // 가장 큰 점수 차이 업데이트
            answer = ryan;  // 결과를 현재 라이언의 과녁 정보로 업데이트
        } else if (curr_diff != 0 && max_diff == curr_diff && cmp(ryan)) {  // 현재 점수 차가 0이 아니고, 현재 점수 차와 최대 점수 차가 같고, CMP 결과가 참이면
            answer = ryan;  // 결과를 현재 라이언의 과녁 정보로 업데이트
        }
        return; // backtracking 종료
    }
    if (extra_arrows > apeach[cnt]) { // 남은 화살로 라이언이 점수를 얻을 수 있다면
        ryan[cnt] = apeach[cnt] + 1;    // 리아언의 과녁 정보 업데이트
        backtracking(cnt + 1, extra_arrows - apeach[cnt] - 1, ryan, apeach);    // 재귀
        ryan[cnt] = 0;  // 초기화
    }
    backtracking(cnt + 1, extra_arrows, ryan, apeach);  // 재귀
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(SIZE + 1, 0); // 라이언의 과녁 정보
    backtracking(0, n, ryan, info); // 연산
    return answer;  // 라이언이 가장 큰 점수 차이로 이기기 위해서 n발의 화살을 어떤 과녁 점수에 맞쳐야 하는지 정수 배열 반환
}


// int main() {
//     int n = 5;
//     vector<int> info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
//     vector<int> result = solution(n, info);
//     for (int i = 0; i < result.size(); i++) {
//         cout << result[i] << ' ';
//     }
//     return 0;
// }