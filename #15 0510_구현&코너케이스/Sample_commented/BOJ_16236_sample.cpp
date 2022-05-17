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
    vector<ci> list; // 상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1;    // 초기화
    q.push(shark);
    while (!q.empty()) {    // 다음 방문할 위치가 없을 때까지 반복
        int row = q.front().first;  // row 업데이트 
        int col = q.front().second; // column 업데이트
        q.pop();    // 업데이트에 반영된 q 비우기

        if (dist[row][col] >= min_dist) { // 최단거리 이상은 탐색할 필요 없음
            continue;
        }
        for (int i = 0; i < 4; i++) {   // 모든 위치 확인
            int nr = row + dr[i];   // 다음 row 업데이트
            int nc = col + dc[i];   // 다음 column 업데이트
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) {
                continue;
            }

            dist[nr][nc] = dist[row][col] + 1;  // dist 업데이트
            if (board[nr][nc] && board[nr][nc] < shark_size) { // 먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc);  // 물고기 위치 업데이트
                min_dist = dist[nr][nc];    // 최단거리 업데이트
                continue;
            }
            q.push({nr, nc});   // q 업데이트
        }
    }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}};    // 결과 반환
    }

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { // 정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) { // 같지 않다면
            return p1.first < p2.first;
        }
        return p1.second < p2.second; // 같다면  
    });
    return {min_dist - 1, list[0]};     
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0; // 초기화...
    while (true) {  // 무한 빈복
        pair<int, ci> result = nextPos(n, size, shark, board);  // 이동 결과 업데이트
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;
        }
        ans += result.first;    // 물고기를 잡아먹을 수 있는 시간 업데이트
        cnt++;  // 횟수 증가
        if (cnt == size) { //상어 크기 증가
            cnt = 0;    // 횟수 초기화
            size++; // 크기 증가
        }

        //상어 이동
        board[shark.first][shark.second] = 0;   // 원래 있던 위치 빈칸으로 업데이트
        shark = result.second;  // 이동 업데이트
    }
    return ans; // 시간 반환
}

int main() {
    int n;  // 공간의 크기를 결정하는 n
    pair<int, int> shark_pos;   // 상어 위치

    //입력
    cin >> n;   // n 입력받기
    vector<vector<int>> board(n, vector<int>(n));   // 공간의 상태
    for (int i = 0; i < n; i++) {   // n만큼 반복
        for (int j = 0; j < n; j++) {   // n만큼 반복 (n*n)
            cin >> board[i][j]; // 공간의 상태 입력받기
            if (board[i][j] == 9) { //상어의 초기 위치
                shark_pos = make_pair(i, j);    // 위치 업데이트
            }
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
    return 0;
}