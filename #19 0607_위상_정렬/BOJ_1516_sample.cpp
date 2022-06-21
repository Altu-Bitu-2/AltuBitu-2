#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬 + DP
vector<int> topologicalSort(int n, vector<int> &t, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = t[i];
        if (!indegree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            dp[next_node] = max(dp[next_node], dp[node] + t[next_node]);

            indegree[next_node]--;
            if (!indegree[next_node]) {
                q.push(next_node);
            }
        }
    }
    return dp;
}

int main() {
    int n, input;

    //입력
    cin >> n;
    vector<int> t(n + 1, 0); //건물을 짓는데 걸리는 시간
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        while (cin >> input) {
            if (input == -1) {
                break;
            }
            graph[input].push_back(i);
            indegree[i]++;
        }
    }

    //연산
    vector<int> ans = topologicalSort(n, t, indegree, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}