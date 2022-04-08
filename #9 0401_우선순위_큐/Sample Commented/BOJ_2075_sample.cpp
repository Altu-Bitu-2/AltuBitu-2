/* N번째 큰 수 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;  // 표의 칸 수 n, 표에 채워진 숫자들 input
    priority_queue<int, vector<int>, greater<>> pq; // 최소 힙, 정렬이랑 반대

    cin >> n;   // n 입력받기
    int size = n * n;   // n*n 계산해서 size에 저장
    while (size--) {    // size만큼 반복
        cin >> input;   // 표에 채워진 숫자 입력받기

        pq.push(input);     // 숫자 힙에 넣기
        if (pq.size() > n) { // 최소 힙의 크기가 n 이상이라면...
            pq.pop();   // 가장 작은 값 삭제
        }
    }

    cout << pq.top();   // n번째 큰 수 출력
    return 0;
}