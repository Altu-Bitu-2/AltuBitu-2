/* 택배 : Sample */

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int new_dist = graph[i][k] + graph[k][j];
                if (new_dist < graph[i][j]) {
                    graph[i][j] = new_dist;
                    table[i][j] = table[i][k];
                }
            }
        }
    }
}

int main() {
    int n, m, s, d, c;

    //입력
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    while (m--) { //무방향 그래프
        cin >> s >> d >> c;
        //간선 정보
        graph[s][d] = graph[d][s] = c;

        //경로 정보
        table[s][d] = d;
        table[d][s] = s;
    }

    //연산
    floydWarshall(n, graph, table);

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << "- ";
            } else {
                cout << table[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}