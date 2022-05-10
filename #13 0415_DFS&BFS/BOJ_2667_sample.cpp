#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

int n;
vector<vector<bool>> board;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};


//단지 내 집 개수 탐색하는 dfs
int dfs_recursion(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) { //인덱스 에러 방지
        return 0;   // 0 반환
    }
    if (!board[r][c]) { //집이 있는지 (이미 방문 했는지) 확인
        return 0;   // 0 반환
    }
    int cnt = 1;    // 횟수 1로 초기화
    board[r][c] = false;    // board 초기화

    for (int i = 0; i < 4; i++) {   // 4번 반복
        cnt += dfs_recursion(r + dr[i], c + dc[i]); // 집 개수 업데이트
    }
    return cnt; // 개수 반환
}

//단지 수와 단지 내 집 개수 구하는 함수
vector<int> cntComplex(int n, vector<vector<bool>> &board) {
    vector<int> complex;
    for (int i = 0; i < n; i++) {   // 단지 수만큼 반복
        for (int j = 0; j < n; j++) {   // 단지 수만큼 반복
            if (board[i][j]) {  // 자료가 1이면
                int cnt = dfs_recursion(i, j);  // 집의 개수 연산
                complex.push_back(cnt); // 연산값 업데이트
            }
        }
    }
    return complex; // 연산 값 반환
}

int main() {
    string s;   // 자료 저장할 위치

    //입력
    cin >> n;   // 단지 수 입력받기
    board.assign(n, vector<bool>(n, false));    // 자료 데이터
    for (int i = 0; i < n; i++) {   // 단지 수만큼 반복
        cin >> s;   // 자료 입력받기
        for (int j = 0; j < n; j++) {   // 단지 수만큼 반복
            board[i][j] = s[j] - '0';   // 숫자로 저장
        }
    }

    //연산
    vector<int> ans = cntComplex(n, board); // 단지수와 단지 내 집의 개수 구하기
    sort(ans.begin(), ans.end());   // 정답 오름차순으로 정렬

    //출력
    cout << ans.size() << '\n'; // 총 단지 수 출력
    for (int i = 0; i < ans.size(); i++) {  // 단지 수만큼 반복
        cout << ans[i] << '\n';     // 집의 수 출력
    }
    return 0;
}