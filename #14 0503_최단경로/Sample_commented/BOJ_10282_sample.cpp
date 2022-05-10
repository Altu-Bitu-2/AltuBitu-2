/* 해킹 : Sample */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; //최대 n-1개의 연결관계 있으므로 -> n * (가중치 최대값)

//다익스트라
ci dijkstra(int start, int v, vector<vector<ci>> &graph) {
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<int> dist(v + 1, INF);

    dist[start] = 0;
    pq.push({0, start});
    int cnt = 0, t = 0;
    while (!pq.empty()) {
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
    return {cnt, t};
}

int main() {
    int t, n, d, c, a, b, s;

    //입력
    cin >> t;
    while (t--) {
        cin >> n >> d >> c;
        vector<vector<ci>> graph(n + 1, vector<ci>(0)); //방향 그래프
        while (d--) {
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        //연산
        ci ans = dijkstra(c, n, graph);

        //출력
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}