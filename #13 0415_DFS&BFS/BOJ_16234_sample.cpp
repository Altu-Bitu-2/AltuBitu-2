#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board, visited;
queue<ci> countries;


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci> &union_cord) {
    for (int i = 0; i < union_cord.size(); i++) {   // union_cord만큼 반복
        int row = union_cord[i].first, col = union_cord[i].second;  // row, column 업데이트
        board[row][col] = population;
        countries.push({row, col}); // 인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({cr, cc}); // 연합 저장
    queue<ci> q;
    q.push({cr, cc});   // 큐에 cr, cc 값 넣기
    int sum = board[cr][cc], cnt = 1;   // 합 초기화, 횟수 초기화
    while (!q.empty()) {    // 큐의 크기만큼 반복
        cr = q.front().first;   // cr 업데이트
        cc = q.front().second;  // cc 업데이트
        q.pop();    // q 원소 pop

        for (int i = 0; i < 4; i++) {   // 4번 반복 (4방향)
            int nr = cr + dr[i];    // nr (row)
            int nc = cc + dc[i];    // nc (column)
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) {     // 
                continue;   // 계속
            }
            int diff = abs(board[nr][nc] - board[cr][cc]);  // 차이 업데이트
            if (diff >= l && diff <= r) { //국경선 열림
                q.push({nr, nc});   // q 업데이트
                visited[nr][nc] = day;  // 방문내역 업데이트
                union_cord.push_back({nr, nc}); // 연합에 추가
                sum += board[nr][nc];   // 합 더하기
                cnt++;  // 횟수 증가
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        return true;    // 참 반환
    }
    return false;   // 거짓 반환
}

int simulation(int n, int l, int r) {
    int day = 0; //방문 체크로도 사용
    while (true) {      // 무한 반복
        day++;      // 날짜 증가
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        while (size--) {   // size만큼 반복
            int row = countries.front().first;  // row 저장
            int col = countries.front().second; // column 저장
            countries.pop();    // 가장 첫번째 countries 원소 pop
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                continue;   // 계속
            }
            visited[row][col] = day;    // 방문 내역 업데이트
            if (bfs(n, l, r, row, col, day)) {  // bfs 연산 결과가 참이면   
                is_move = true;     // is_move는 참
            }
        }
        if (!is_move) {     // is_move가 참이면
            return day - 1; // day-1 반환
        }
    }
}

int main() {
    int n, l, r;  // 크기에서의 n, 최소 l 명, 최대 r 명

    //입력
    cin >> n >> l >> r;     // n, 1, r 입력받기
    board.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {   // n*n만큼 반복
            cin >> board[i][j];     // 각 나라의 인구 수 입력받기
            countries.push({i, j}); // 인구 수 저장하기
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r);    // 인구 이동이 며칠 동안 발생하는지 연산 + 출력
    return 0;
}