/* 좋다 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {
    while (left < right) {  // 주어진 범위 만큼 반복
        if (left == idx) {  // 왼쪽 첫번째 숫자가 인덱스와 같을 경우
            left++;         // 오른쪽으로 한 칸 이동
            continue;       // 계속
        }
        if (right == idx) { // 오른쪽 첫번째 숫자가 인덱스와 같을 경우
            right--;        // 왼쪽으로 한 칸 이동
            continue;       // 계속
        }

        if (num[left] + num[right] == num[idx]) {   // 두 숫자의 합이 범위 안의 다른 수라면
            return true;    // 참 반환
        }
        if (num[left] + num[right] > num[idx]) {    // 두 숫자의 합이 범위 안의 다른 수보다 클 경우
            right--;    // 왼쪽으로 한 칸 이동
        } else {
            left++; // 오른쪽으로 한 칸 이동
        }
    }
    return false;   // 거짓 반환
}

int main() {
    int n, ans = 0;     // 수의 개수 n, 좋은 수의 개수 ans

    //입력
    cin >> n;           // 수의 개수 입력받기
    vector<int> num(n, 0);  // 수의 개수만큼 주어지는 숫자 저장할 위치
    for (int i = 0; i < n; i++) {   // n만큼 반복
        cin >> num[i];  // 숫자 입력받기
    }

    //연산
    sort(num.begin(), num.end());   // 입력받은 숫자 오름차순으로 정렬
    for (int i = 0; i < n; i++) {   // n만큼 반복
        if (isGood(num, 0, n - 1, i)) { // 좋은 숫자인지 연산
            ans++;  // 좋은 숫자이면 좋은 수의 개수 ans 증가
        }
    }

    //출력
    cout << ans;    // 좋은 수의 개수 출력
    return 0;
}