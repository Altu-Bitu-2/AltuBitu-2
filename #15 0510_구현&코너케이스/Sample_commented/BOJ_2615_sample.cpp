/* 오목 : Sample */

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

bool promising(int r, int c, int stone, vector<vector<int>> &board) {
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == stone;    // 범위와 돌의 종류가 유효한지 확인
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>> &board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = {0, 1, 1, -1};
    int dc[4] = {1, 0, 1, 1};

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    if (promising(r - dr[d], c - dc[d], stone, board)) {
        return false;   // valid하지 않음
    }
    int cnt = 0;    // 횟수 초기화
    while (cnt < 6 && promising(r, c, stone, board)) { // (r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++;  // 획수 증가
        r += dr[d]; // 위치 row 업데이트
        c += dc[d]; // 위치 column 업데이트
    }
    return cnt == 5;    // 다섯번이면 -> 오목이니까 참 거짓 반환
}

bool isEnd(int r, int c, vector<vector<int>> &board) {
    for (int i = 0; i < 4; i++) { // 가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) {    
            return true;    // 오목이다...
        }
    }
    return false;   // 오목 아님
}

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));  // 바둑판

    //입력
    for (int i = 0; i < SIZE; i++) {    // 바둑반 크기...
        for (int j = 0; j < SIZE; j++) {    // 바둑판 크기... 반복
            cin >> board[i][j]; // 바둑판 상태 입력
        }
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {    // 바둑반 크기...
        for (int j = 0; j < SIZE; j++) {    // 바둑판 크기... 반복
            if (!board[i][j]) { // 돌이 없음
                continue;
            }
            if (isEnd(i, j, board)) { // 누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;   // 결과 출력
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}