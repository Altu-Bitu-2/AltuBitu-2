#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;
typedef tuple<double, int, int> tp;
typedef pair<double, double> ci;

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

double kruskal(int v, vector<tp> &edge) {
    double sum = 0;
    int cnt = 0;

    for (int i = 0; i < edge.size(); i++) {
        double cost = get<0>(edge[i]);
        int x = get<1>(edge[i]);
        int y = get<2>(edge[i]);

        if (!unionNodes(x, y)) {
            continue;
        }
        sum += cost;
        cnt++;
        if (cnt == v - 1) {
            return sum;
        }
    }
    return 0;
}

int main() {
    int n, m, a, b, v = 0;
    double x, y;

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1);
    vector<tp> edge;
    vector<ci> star(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        for (int j = 1; j < i; j++) {
            //임의의 두 별에 대한 거리(간선) 모두 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            edge.push_back({sqrt(dx * dx + dy * dy), i, j});
        }
        star[i] = {x, y};
    }

    //연산
    while (m--) {
        cin >> a >> b;
        if (unionNodes(a, b)) { //이미 연결된 통로
            v++;
        }
    }
    sort(edge.begin(), edge.end());

    //연산 & 출력
    cout << fixed;
    cout.precision(2);
    cout << kruskal(n - v, edge);
    return 0;
}