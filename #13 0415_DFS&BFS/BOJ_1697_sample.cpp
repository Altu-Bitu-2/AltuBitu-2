#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5;

int bfs(int n, int k) {
    vector<int> check(SIZE + 1, 0);     // 체크
    queue<int> q; //큐에 좌표값 저장
    int ans = 0;    // 연산값 초기화

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n);  // n을 큐에 넣기
    while (!q.empty()) {    // 큐의 크기만큼 반복
        int x = q.front();  // 큐의 첫번째 원소를 x로
        q.pop();    // 첫번째 원소 pop

        if (x == k) {   // 동생이 있는 위치에 있으면...
            ans = check[x] - 1; // 연산값 업데이트
            break;  // 종료
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식 노드
        for (int i = 0; i < 3; i++) {   // 3번 반복
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) {    // 크기가 체크 값도 아니고, 0 이상이되 size를 넘지 않으면
                check[child[i]] = check[x] + 1; // 체크할 값 업데이트
                q.push(child[i]);   // 큐에 자식 노드 넣기
            }
        }
    }
    return ans; // 연산값 반환
}

int main() {
    int n, k;   // 수빈이가 있는 위치, 동생이 있는 위치

    //입력
    cin >> n >> k;  // 위치들 입력받기

    //연산 & 출력
    cout << bfs(n, k);  // 연산 후 수빈이가 동생을 찾는 가장 빠른 시간 출력
    return 0;
}