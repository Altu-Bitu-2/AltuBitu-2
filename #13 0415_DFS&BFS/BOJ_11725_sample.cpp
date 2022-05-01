#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> parent;

void dfs_recursion(int prev, int curr) {
    if (parent[curr]) { // 현재가 부모 노드이면
        return;     // 돌아가기
    }
    parent[curr] = prev;    // 이전으로 업데이트
    for (int i = 0; i < adj_list[curr].size(); i++) { 
        dfs_recursion(curr, adj_list[curr][i]);     // 재귀
    }
}

int main() {
    int n, a, b;    // 노드의 개수, 정점 a와 b

    //입력
    cin >> n;   // 노드의 개수 입력받기
    adj_list.assign(n + 1, vector<int>(0));     // adj_list 할당
    parent.assign(n + 1, 0);                    // 부모 노드
    for (int i = 1; i < n; i++) {   // 노드의 개수만큼 반복
        cin >> a >> b;  // 정점 입력받기
        adj_list[a].push_back(b);   // 리스트에 업데이트
        adj_list[b].push_back(a);   // 리스트에 업데이트
    }

    //연산
    dfs_recursion(1, 1); //1번 노드는 루트노드이므로, 부모를 자기 자신으로 설정

    //출력
    for (int i = 2; i <= n; i++) {  // n-1만큼 반복
        cout << parent[i] << '\n';      // 부모 노드의 번호 출력
    }
    return 0;
}