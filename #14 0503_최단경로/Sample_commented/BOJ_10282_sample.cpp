/* 해킹 : Sample */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; // 최대 n-1개의 연결관계 있으므로 -> n * (가중치 최대값)

// 다익스트라
ci dijkstra(int start, int v, vector<vector<ci>> &graph) {
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<int> dist(v + 1, INF);

    dist[start] = 0;
    pq.push({0, start});
    int cnt = 0, t = 0;     // 총 감염 컴퓨터수, 모두 감염되기까지 걸리는 시간
    while (!pq.empty()) {   // 해킹당한 컴퓨터 개수만큼 반복
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) {
            continue;
        }
        cnt++;
        t = weight;
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return {cnt, t};    // 연산 결과 반환
}

int main() {
    int t, n, d, c, a, b, s;    // 테스트케이스 개수, 컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터의 번호, 의존성을 나타내는 정수 a b s

    cin >> t;   // 테스트케이스 개수 입력
    while (t--) {   // 테스트케이스 개수만큼 반복
        cin >> n >> d >> c; // 컴퓨터, 의존성, 해킹당한 컴퓨터의 개수 입력받기
        vector<vector<ci>> graph(n + 1, vector<ci>(0)); // 방향 그래프
        while (d--) {   // 의존성 개수만큼 반복
            cin >> a >> b >> s; // 의존성을 나타내는 정수들 입력받기
            graph[b].push_back({a, s}); // 방향 그래프에 반영
        }

        ci ans = dijkstra(c, n, graph); // 총 감염 컴퓨터수와 모두 감염되기까지 걸리는 시간 연산

        cout << ans.first << ' ' << ans.second << '\n'; // 연산 결과 출력
    }
    return 0;
}