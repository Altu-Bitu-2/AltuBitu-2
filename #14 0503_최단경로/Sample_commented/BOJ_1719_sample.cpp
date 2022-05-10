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
    int n, m, s, d, c;  // 집하장의 개수, 집하장간 경로의 개수, 집하장의 번호 s d, 두 집하장을 오가는데 걸리는 시간

    cin >> n >> m;  // 집하장의 개수와 집하장간 경로의 개수 입력받기
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));  // 집하장 그래프
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));    // 경로표
    for (int i = 1; i <= n; i++) {  // 집하장 개수만큼 반복
        graph[i][i] = 0;    // 그래프 초기화
    }

    while (m--) { // 경로의 개수만큼 반복
        cin >> s >> d >> c; // 집하장의 번호와 둘을 오가는 시간 입력받기
        graph[s][d] = graph[d][s] = c;    //간선 정보

        table[s][d] = d;    // 테이블에 경로 정보 저장
        table[d][s] = s;    // 테이블에 경로 정보 저장
    }

    floydWarshall(n, graph, table);     // 플로이드 연산

    for (int i = 1; i <= n; i++) {      // 집하장 개수만큼 반복
        for (int j = 1; j <= n; j++) {  // 집하장 개수만큼 반복
            if (i == j) {   // 집하장 개수 텀(?) 마다
                cout << "- ";
            } else {
                cout << table[i][j] << ' '; // 테이블 저장 내용 출력
            }
        }
        cout << '\n';
    }
    return 0;
}