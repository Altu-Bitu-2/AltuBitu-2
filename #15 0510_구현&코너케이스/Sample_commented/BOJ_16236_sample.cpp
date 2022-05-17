/* 아기 상어 : Sample */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int min_dist = INF;
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> dist(n, vector<int>(n, 0)); //상어의 방문 여부 + 거리
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1;
    q.push(shark);
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (dist[row][col] >= min_dist) { //최단거리 이상은 탐색할 필요 없음
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) {
                continue;
            }

            dist[nr][nc] = dist[row][col] + 1;
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc);
                min_dist = dist[nr][nc];
                continue;
            }
            q.push({nr, nc});
        }
    }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}};
    }

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    });
    return {min_dist - 1, list[0]};
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0;
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board);
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;
        }
        ans += result.first;
        cnt++;
        if (cnt == size) { //상어 크기 증가
            cnt = 0;
            size++;
        }

        //상어 이동
        board[shark.first][shark.second] = 0;
        shark = result.second;
    }
    return ans;
}

int main() {
    int n;
    pair<int, int> shark_pos;

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) { //상어의 초기 위치
                shark_pos = make_pair(i, j);
            }
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
    return 0;
}