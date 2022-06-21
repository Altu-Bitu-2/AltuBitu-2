#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 4;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//컨트롤로 이동하는 좌표를 리턴하는 함수
ci ctrl(int row, int col, int dir, vector<vector<int>> &tmp) {
    while (true) {
        row += dr[dir];
        col += dc[dir];
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) { //해당 방향에 카드가 하나도 없다면 그 방향의 가장 마지막 칸으로 이동
            return make_pair(row - dr[dir], col - dc[dir]);
        }
        if (tmp[row][col] != 0) { //누른 키 방향에 있는 가장 가까운 카드
            return make_pair(row, col);
        }
    }
}

//현재 커서에서 목표 카드로 이동하는 가장 적은 비용을 리턴하는 함수
int bfs(int r1, int c1, int r2, int c2, vector<vector<int>> &tmp) {
    vector<vector<int>> visited(SIZE, vector<int>(SIZE, 0));
    queue<ci> q;
    visited[r1][c1] = 1; //반드시 엔터를 누르게 될 것. 엔터를 미리 눌렀다 가정하고 1로 표시
    q.push({r1, c1});

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        int dist = visited[row][col];
        q.pop();

        if (row == r2 && col == c2) { //목표 카드에 도달했다면
            return dist;
        }
        for (int i = 0; i < 4; i++) { //컨트롤 입력 이동
            pair<int, int> np = ctrl(row, col, i, tmp);
            if (visited[np.first][np.second]) {
                continue;
            }
            visited[np.first][np.second] = dist + 1;
            q.push(np);
        }

        for (int i = 0; i < 4; i++) { //방향키 입력 이동
            int nr = row + dr[i], nc = col + dc[i];
            if (nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE || visited[nr][nc]) {
                continue;
            }
            visited[nr][nc] = dist + 1;
            q.push({nr, nc});
        }
    }
    return -1; //목표 카드에 도달하지 못함 (실제로는 일어나지 않는 일)
}

//조합에 대해 카드를 매칭하는 함수
int matchCard(int bit, int num, int r, int c, int answer, vector<int> &seq, vector<vector<ci>> &cards,
              vector<vector<int>> tmp) {
    int ans = 0;
    for (int i = 0; i < num; i++) {
        int cur = seq[i]; //이번에 매칭할 캐릭터
        int now = 0; //해당 캐릭터의 0번째 카드부터 선택한다고 가정
        if (bit & (1 << i)) { //만약 해당 위치의 비트가 1을 표시했다면 1번째 카드부터 선택
            now = 1;
        }
        for (int j = 0; j < 2; j++) {
            int nr = cards[cur][now].first, nc = cards[cur][now].second; //이번에 매칭할 카드 위치
            ans += bfs(r, c, nr, nc, tmp); //현재 커서에서 목표 카드까지 이동하는 비용
            //기존 최솟값보다 큰 경우 -> 더 이상의 탐색 불필요
            if (ans >= answer) {
                return answer;
            }
            //카드 삭제 + 커서 이동
            tmp[nr][nc] = 0;
            r = nr;
            c = nc;
            now = 1 - now; //다음에 매칭할 카드 인덱스
        }
    }
    return ans;
}

//존재하는 모든 카드의 위치를 리턴하는 함수
vector<vector<ci>> findCard(vector<vector<int>> &board) {
    vector<vector<ci>> card_pos(7, vector<ci>(0)); //최대 카드 수
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cnt = max(cnt, board[i][j]);
            if (board[i][j]) { //카드라면 위치 저장
                card_pos[board[i][j]].push_back({i, j});
            }
        }
    }
    card_pos.resize(cnt + 1); //실제 존재하는 카드의 수만큼 크기 조절
    return card_pos;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9;
    vector<vector<ci>> cards = findCard(board); //존재하는 모든 카드의 위치
    int card_cnt = cards.size() - 1; //카드의 개수

    vector<int> seq(card_cnt); //순열을 위한 배열
    for (int i = 0; i < card_cnt; i++) {
        seq[i] = i + 1;
    }
    do { //가능한 모든 카드 순서에 대해
        for (int bit = 0; bit < (1 << card_cnt); bit++) { //0, 1번째 카드 중 어떤 카드를 먼저 뒤집을지 결정
            answer = min(answer, matchCard(bit, card_cnt, r, c, answer, seq, cards, board));
        }
    } while (next_permutation(seq.begin(), seq.end()));
    return answer;
}

int main() {
    vector<vector<int>> board = {{1, 0, 0, 3},
                                 {2, 0, 0, 0},
                                 {0, 0, 0, 2},
                                 {3, 0, 1, 0}};
    cout << solution(board, 1, 0);
}