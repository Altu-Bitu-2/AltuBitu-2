/* 트리와 쿼리 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt;

int treeDp(int cur, vector<vector<int>> &graph) {
    if (subtree_cnt[cur] != -1) { // 이미 탐색했던 상태
        return subtree_cnt[cur];    //  연산 결과 반환
    }

    subtree_cnt[cur] = 0;
    int node = 1;
    for (int i = 0; i < graph[cur].size(); i++) {   // 서브트리에 속한 정점의 수 세기
        node += treeDp(graph[cur][i], graph);   // 정점의 수 업데이트
    }
    return subtree_cnt[cur] = node; // 연산 결과 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input;   // 트리의 정점, 루트의 번호, 쿼리의 수, 간선 정보...

    //입력
    cin >> n >> r >> q; // 트리의 정점, 루트의 번호, 쿼리의 수 입력받기
    vector<vector<int>> graph(n + 1, vector<int>(0));   // 그래프 벡터
    subtree_cnt.assign(n + 1, -1);  // 할당

    while (--n) { //무방향 그래프
        cin >> u >> v;  // 간선 정보 입력
        graph[u].push_back(v);  // 정보 저장
        graph[v].push_back(u);  // 정보 저장
    }

    treeDp(r, graph);   // 연산

    while (q--) {   // 쿼리의 수만큼 반복
        cin >> input;   // 정점 u 입력받기
        cout << subtree_cnt[input] << '\n'; // 쿼리의 답 출력
    }
    return 0;
}