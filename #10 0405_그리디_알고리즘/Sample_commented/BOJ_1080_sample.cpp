#include <iostream>
#include <vector>

using namespace std;

// 부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) {   // 행렬 크기...n...
        for (int j = col; j < col + 3; j++) {   // 행렬 크기...m...
            if (matrix_a[i][j] == '1') {    // 원소가 1인 경우
                matrix_a[i][j] = '0';   // 1 -> 0
            }
            else {  // 원소가 1이 아닌 경우 (0)
                matrix_a[i][j] = '1';   // 0 -> 1
            }
        }
    }
}

// 마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) {   // 행렬 크기...n...
        for (int j = 0; j < m; j++) {   // 행렬 크기...m...
            if (matrix_a[i][j] != matrix_b[i][j]) {     // (i, j)원소가 서로 다르다면
                return false;   // false 반환
            }
        }
    }
    return true;    // true 반환
}

int main() {
    int n, m;   // 행렬의 크기 (50보다 작거나 같음)

    cin >> n >> m; // 행렬의 크기 입력받기
    vector<string> matrix_a(n); //
    vector<string> matrix_b(n);
    for (int i = 0; i < n; i++) {   // n열만큼 반복
        cin >> matrix_a[i]; //  행렬A 입력받기
    }

    for (int i = 0; i < n; i++) {   // n열만큼 반복
        cin >> matrix_b[i]; //  행렬B 입력받기
    }

    int ans = 0;    // 정답 저장할 위치
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) { // (i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a); // 원소 뒤집기
                ans++;  // 연산 횟수 증가
            }
        }
    }

    if (!isPossible(n, m, matrix_a, matrix_b)) {    // 행렬A가 행렬B로 바꿔졌는지 확인
        ans = -1;   // 바꾸지 못했으면 -1
    }
    cout << ans;    // 연산 결과 출력
    return 0;
}