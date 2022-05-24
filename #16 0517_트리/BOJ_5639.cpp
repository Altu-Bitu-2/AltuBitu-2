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
        node = new node_info(); //동적 할당
        node->data = data;
        node->left = node->right = NULL;
    } else if (node->data > data) {
        node->left = makeTree(node->left, data);
    } else if (node->data < data) {
        node->right = makeTree(node->right, data);
    }
    return node;
}

//후위 순회
void postorder(node_info *node) {
    if (node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << '\n';
}

int main() {
    int input;

    //입력 & 연산
    node_info *root = NULL;
    while (cin >> input) {
        root = makeTree(root, input);
    }

    //출럭
    postorder(root);
    return 0;
}