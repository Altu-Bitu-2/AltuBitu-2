#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<int> bfs(int n, vector<vector<ci>> &graph) {
    queue<int> q;
    vector<int> cnt(n + 1, 0); //큐에 있는 부품 번호에 따른 개수 저장 + 방문체크
    vector<int> ans(n + 1, 0); //기본 부품 개수 저장

    //시작 정점 초기화
    q.push(n);
    cnt[n] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        //리프노드(기본부품)인 경우
        if (graph[x].empty()) {
            ans[x] += cnt[x];
        }
        //중간부품인 경우
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i].first;
            int k = graph[x][i].second;
            if (!cnt[y]) {
                q.push(y);
            }
            cnt[y] += k * cnt[x];
        }
        cnt[x] = 0; //처리가 끝나면 0으로 리셋
    }
    return ans;
}

int main() {
    int n, m, x, y, k;

    //입력
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    while (m--) {
        cin >> x >> y >> k;
        graph[x].push_back({y, k});
    }

    //연산
    vector<int> result = bfs(n, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        if (result[i]) {
            cout << i << ' ' << result[i] << '\n';
        }
    }
    return 0;
}