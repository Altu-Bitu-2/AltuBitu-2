/* Puyo Puyo : Sample */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
//행과 열을 바꿔줄 것이므로 ROW를 6으로 설정
const int ROW = 6;
const int COL = 12;

bool bfs(int r, int c, vector<vector<char>> &board) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q;
    queue<ci> puyo; //포함된 좌표 저장할 큐
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));    // 확인한 좌표..

    //시작 초기화
    q.push({r, c});
    puyo.push({r, c});
    visited[r][c] = true;
    int cnt = 1; //모여있는 뿌요의 개수
    while (!q.empty()) {    // 큐의 크기만큼 반복
        int cr = q.front().first;   // cr 업데이트
        int cc = q.front().second;  // cc 업데이트
        q.pop();    // q 원소 pop

        for (int i = 0; i < 4; i++) {    // 4번 반복 (4방향)
            int nr = cr + dr[i];        // nr (row)
            int nc = cc + dc[i];        // nc (column)
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
                continue;   // 계속
            }
            if (board[nr][nc] == board[cr][cc]) {   // 필드를 비교했을 떄 같으면
                q.push({nr, nc});   // q 업데이트
                puyo.push({nr, nc});    // 좌표 저장
                visited[nr][nc] = true; // 확인한 위치로 표시
                cnt++;  // 모여있는 뿌요 개수 증가
            }
        }
    }
    if (cnt < 4) { //뿌요 안터짐
        return false;   // 거짓 반환
    }
    while (!puyo.empty()) { // 저장된 좌표가 있으면
        int cr = puyo.front().first;    // cr 업데이트
        int cc = puyo.front().second;   // cc 업데이트
        puyo.pop(); // 업데이트한 내용 pop

        board[cr][cc] = '.';    // 필드를 빈공간으로...
    }
    return true;    // 참 반환
}

// 뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
vector<vector<char>> makeNewBoard(vector<vector<char>> &board) {
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.'));    // 새 필드...
    for (int i = 0; i < ROW; i++) { // 12줄만큼 반복
        queue<char> temp; //남아있는 뿌요 모으는 큐
        for (int j = 0; j < COL; j++) { // 6개의 문자 수만큼 반복
            if (board[i][j] != '.') {   // 문자의 위치에 .(빈공간)이 입력되지 않았다면...
                temp.push(board[i][j]); // 남아있는 뿌오 모으는 큐에 해당 위치의 색상 저장
            }
        }
        int index = 0;  // 인덱스 선언&초기화
        while (!temp.empty()) { // 남아있는 뿌요가 존재한다면
            new_board[i][index++] = temp.front();   // 새 필드에 남아있는 뿌요 저장
            temp.pop(); // 저장된 남아있는 뿌요 비우기
        }
    }
    return new_board;   // 새 필드 반환
}

int simulation(vector<vector<char>> &board) {
    int answer = 0; // 연산 결과 변수 선언&초기화
    while (true) {  // 무한 반복
        bool flag = false; //뿌요가 터졌는지 확인
        for (int i = 0; i < ROW; i++) {     // 12줄만큼 반복
            for (int j = 0; j < COL; j++) { // 6개의 문자 수만큼 반복
                if (board[i][j] == '.') {   // 문자의 위치에 .(빈공간)이 입력되었다면...
                    continue;               // 계속
                }
                if (bfs(i, j, board)) { // 한 번이라도 뿌요 터졌다면
                    flag = true;    // 뿌요가 터졌다는 것 확인
                }
            }
        }
        if (!flag) {    // 뿌요가 터졌다는 것이 확인되지 않았다면
            break;      // 종료
        }
        board = makeNewBoard(board);    // 뿌요를 터뜨린 이후의 새 필드를 작성하는 함수 호출
        answer++;   // 연산 결과(연쇄 숫자) 증가
    }
    return answer;  // 연산 결과 반환
}

int main() {
    char input;     // 색깔 입력받을...
    vector<vector<char>> board(ROW, vector<char>(COL)); // 입력받은 색깔 위치에 따라 저장할 곳
    for (int i = 0; i < COL; i++) {     // 12줄만큼 반복
        for (int j = 0; j < ROW; j++) { // 6개의 문자 수만큼 반복
            cin >> input;   // 색깔 입력받기
            board[j][COL - i - 1] = input;  // 입력받을 위치 알맞은 위치에 저장
        }
    }

    cout << simulation(board);  // 몇 연쇄가 되는지 연산&출력
    return 0;
}