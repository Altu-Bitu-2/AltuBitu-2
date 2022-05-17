/* 로봇 청소기 : Sample */

#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) {
    //상, 우, 하, 좌
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int step = 0, ans = 0;
    while (true) {
        if (board[r][c] == 0) {
            board[r][c] = 2;
            ans++;
        }

        if (step == 4) {
            if (board[r - dr[d]][c - dc[d]] == 1) {
                return ans;
            }
            r -= dr[d];
            c -= dc[d];
            step = 0;
        } else {
            d = (d + 3) % 4;
            if (board[r + dr[d]][c + dc[d]]) {
                step++;
                continue;
            }
            r += dr[d];
            c += dc[d];
            step = 0;
        }
    }
}

int main() {
    int n, m, r, c, d;

    //입력
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;
}