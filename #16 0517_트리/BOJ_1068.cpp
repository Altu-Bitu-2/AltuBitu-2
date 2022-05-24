/* 트리 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {
    if (node == erase_node) {
        return 0;
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        cnt += eraseLeafCnt(tree[node][i], erase_node);
    }
    return cnt;
}

int main() {
    int n, par, root, erase_node;

    //입력
    cin >> n;
    tree.assign(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        cin >> par;
        if (par == -1) {
            root = i;
            continue;
        }
        tree[par].push_back(i);
    }
    cin >> erase_node;

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node);
    return 0;
}