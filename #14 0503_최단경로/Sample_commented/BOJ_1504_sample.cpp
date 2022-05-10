/* 특정한 최단 경로 : Sample */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

//다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    vector<int> dist(v + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) {
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int main() {
    int n, e, a, b, c, v1, v2;  // 정점의 개수, 간선의 개수, 정수 abc, 반드시 거쳐야하는 정점 번호 v1 v2

    cin >> n >> e;  // 정점의 개수와 간선의 개수 입력받기

    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    vector<vector<int>> dist(3, vector<int>(n + 1, 0));
    while (e--) { // 간선의 개수만큼 반복
        cin >> a >> b >> c;     // 정수 abc 입력받기
        graph[a].emplace_back(b, c);    // 그래프 저장
        graph[b].emplace_back(a, c);    // 그래프 저장
    }
    cin >> v1 >> v2;    // 반드시 거쳐야하는 정점 입력받기

    vector<int> start_nodes = {1, v1, v2};  // 시작노드 저장
    for (int i = 0; i < 3; i++) { // 3번 반복
        dist[i] = dijkstra(start_nodes[i], n, graph);   // 1, v1, v2에서 시작한 다익스트라 결과 저장
    }

    //1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
    //무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    cout << ((ans >= INF) ? -1 : ans);  // 두 개의 정점을 지나는 최단 경로의 길이 출력
    return 0;
}