/* 양궁대회 */

#include <vector>
#include <iostream>

using namespace std;
const int SIZE = 10;

vector<int> answer = {-1}; //라이언이 가장 큰 점수 차이로 우승하는 경우
int max_diff = 0; //가장 큰 점수 차이

bool cmp(vector<int> &ryan) {
    for (int i = SIZE; i >= 0; i--) {
        if (answer[i] > ryan[i]) {
            return false;
        } else if (answer[i] < ryan[i]) {
            return true;
        }
    }
}

int calcDiff(vector<int> &ryan, vector<int> &apeach) {
    int score_r = 0, score_a = 0;
    for (int i = 0; i <= SIZE; i++) {
        int score = SIZE - i;
        if (ryan[i] > apeach[i]) {
            score_r += score;
        } else if (ryan[i] < apeach[i]) {
            score_a += score;
        }
    }
    return score_r - score_a;
}

void backtracking(int cnt, int extra_arrows, vector<int> &ryan, vector<int> &apeach) {
    if (cnt == SIZE + 1 || extra_arrows == 0) { //(기저조건) 0점 과녁까지 탐색 or 남은 화살 없음
        ryan[SIZE] = extra_arrows; //화살 남아있을 수 있으므로
        int curr_diff = calcDiff(ryan, apeach);
        if (max_diff < curr_diff) {
            max_diff = curr_diff;
            answer = ryan;
        } else if (curr_diff != 0 && max_diff == curr_diff && cmp(ryan)) {
            answer = ryan;
        }
        return;
    }
    if (extra_arrows > apeach[cnt]) { //남은 화살로 라이언이 점수를 얻을 수 있다면
        ryan[cnt] = apeach[cnt] + 1;
        backtracking(cnt + 1, extra_arrows - apeach[cnt] - 1, ryan, apeach);
        ryan[cnt] = 0;
    }
    backtracking(cnt + 1, extra_arrows, ryan, apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(SIZE + 1, 0); //라이언의 과녁 정보
    backtracking(0, n, ryan, info); //연산
    return answer;
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