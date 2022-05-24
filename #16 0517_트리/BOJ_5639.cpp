/* 이진 검색 트리 */

#include <iostream>

using namespace std;

struct node_info {
    int data;
    node_info *left;
    node_info *right;
};

node_info *makeTree(node_info *node, int data) {
    if (node == NULL) { //이번 노드가 들어가게될 위치
        node = new node_info(); // 동적 할당
        node->data = data;  // 정보 업데이트    
        node->left = node->right = NULL;    
    } else if (node->data > data) { // node에 저장되어있는 data가 더 크면
        node->left = makeTree(node->left, data);    // 왼쪽
    } else if (node->data < data) { // node에 저장되어있는 data가 더 작으면
        node->right = makeTree(node->right, data);  // 오른쪽
    }
    return node;    // 만든 결과 반환
}

//후위 순회
void postorder(node_info *node) {
    if (node == NULL) { // 노드가 비어있다면
        return;
    }
    postorder(node->left);  // 재귀 : 왼쪽
    postorder(node->right); // 재귀 : 오른쪽
    cout << node->data << '\n'; // 결과 출력
}

int main() {
    int input;  // 키의 값

    node_info *root = NULL; 
    while (cin >> input) {  // 노드에 들어있는 키의 값 입력
        root = makeTree(root, input);   // 루트 노드 업데이트 (이진 검색 트리 만들기)
    }

    postorder(root);    // 후위 순위한 결과 연산 & 출력
    return 0;
}