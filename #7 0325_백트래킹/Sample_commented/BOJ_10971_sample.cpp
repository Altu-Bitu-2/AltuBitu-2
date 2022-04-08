/* 외판원 순회2 */

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; // 방문 검사 배열
vector<vector<int>> matrix; // 비용 행렬
int n, ans = INF; // 최소 비용 저장 위해 미리 최댓값으로 초기화; n:도시의 수, ans:순회 최소 비용

void backtracking(int cnt, int cur_city, int cost) {
    if (cost >= ans) { // 최소 비용이 0이나 음수가 되면 끝
        return;  // 반환
    }
    if (cnt == n) { // n개의 도시를 순회하면...
        if (matrix[cur_city][0] != 0) {     // 출발한 도시로 다시 돌아올 수 있다면...
            ans = min(ans, cost + matrix[cur_city][0]); // 최소 비용 업데이트
        }
        return; // 반환
    }
    for (int i = 0; i < n; i++) { // n만큼 반복
        if (matrix[cur_city][i] && !visited[i]) { // 길이 있고, 아직 방문하지 않은 도시라면...
            visited[i] = true;  // 방문 true
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);   // 재귀함수
            visited[i] = false; // 방문 false
        }
    }
}

int main() {
    
    cin >> n;   // 도시의 수 입력받기
    visited.assign(n, false);   // visited 배열에 넣기
    matrix.assign(n, vector<int>(n, 0)); // matrix 행렬에 넣기
    for (int i = 0; i < n; i++) {   // 도시의 수만큼 반복
        for (int j = 0; j < n; j++) {   // 도시의 수만큼 반복 : 결과적으로 n*n만큼 반복
            cin >> matrix[i][j];    // maxtrix 행렬에 비용 입력받기
        }
    }

    visited[0] = true;  // true로 초기화
    backtracking(1, 0, 0);  // 최소 비용 연산

    cout << ans;    // 연산 결과 출력
    return 0;
}