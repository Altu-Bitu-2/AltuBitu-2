#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

//Union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) {
        return false;
    }
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py];
        parent[py] = px;
    } else { //새로운 루트 py
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

int kruskal(int n, int idx, vector<tp> &edge) {
    int cnt = 0, sum = 0;
    for (int i = idx; i < edge.size(); i++) {
        int dist = get<0>(edge[i]);
        int x = get<1>(edge[i]);
        int y = get<2>(edge[i]);
        if (!unionNodes(x, y)) {
            continue;
        }
        sum += dist;
        cnt++;
        if (cnt == n - 1) {
            return sum;
        }
    }
    return 0; //mst를 만들 수 없음
}

int main() {
    int n, m, k, x, y;

    cin >> n >> m >> k;
    vector<tp> edge;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        edge.push_back({i, x, y});
    }

    bool flag = false;
    for (int i = 0; i < k; i++) {
        if (flag) { //더이상 mst를 만들 수 없음
            cout << 0 << ' ';
            continue;
        }
        parent.assign(n + 1, -1); //초기화
        int ans = kruskal(n, i, edge);
        if (ans == 0) {
            flag = true;
        }
        cout << ans << ' ';
    }
    return 0;
}