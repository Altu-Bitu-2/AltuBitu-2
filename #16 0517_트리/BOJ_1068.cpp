/* 트리 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {
    if (node == erase_node) {   // 지울 노드가 루트라면
        return 0;   // 리프 노드의 개수는 0 반환
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1;   // 리프 노드의 개수는 1 반환
    }
    int cnt = 0;
    for (int i = 0; i < tree[node].size(); i++) {   // 트리의 노드만큼...
        cnt += eraseLeafCnt(tree[node][i], erase_node);     // 재귀
    }
    return cnt; // 리프 노드의 개수 반환
}

int main() {
    int n, par, root, erase_node;   // 노드의 개수, 노드의 부모, 루트, 지울 노드 번호

    cin >> n;   // 노드의 개수 입력하기
    tree.assign(n, vector<int>(0)); // 트리 생성
    for (int i = 0; i < n; i++) {   // 노드의 개수만큼 반복
        cin >> par; // 부모 노드 입력하기
        if (par == -1) {    // 부모 노드가 없다면
            root = i;   // 루트 노드 업데이트
            continue;
        }
        tree[par].push_back(i); // 트리에 정보 업데이트
    }
    cin >> erase_node;  // 지울 노드 입력

    cout << eraseLeafCnt(root, erase_node); // 입력으로 주어진 노드를 지웠을 때 리프 노드의 개수 연산 & 출력
    return 0;
}