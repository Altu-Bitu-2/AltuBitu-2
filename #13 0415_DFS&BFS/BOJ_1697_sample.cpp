#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5;

int bfs(int n, int k) {
    vector<int> check(SIZE + 1, 0);
    queue<int> q; //큐에 좌표값 저장
    int ans = 0;

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n);
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == k) {
            ans = check[x] - 1;
            break;
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식 노드
        for (int i = 0; i < 3; i++) {
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) {
                check[child[i]] = check[x] + 1;
                q.push(child[i]);
            }
        }
    }
    return ans;
}

int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << bfs(n, k);
    return 0;
}