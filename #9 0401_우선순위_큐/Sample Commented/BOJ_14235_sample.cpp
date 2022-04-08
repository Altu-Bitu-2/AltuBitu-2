/* 크리스마스 선물 */

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, a, input;  // 순서대로 방문 횟수, 숫자 a
    priority_queue<int> pq; // 최대 힙 (선물..)

    cin >> n;   // 방문 횟수 입력받기
    while (n--) {   // 방문 횟수만큼 반복
        cin >> a;   // a입력받기
        if (!a) { // 아이들을 만난 경우 (a가 0이 아닌 경우)
            if (pq.empty()) {   // 최대 힙이 비어있다면 (선물 없음)
                cout << "-1\n"; // 줄 선물이 없음 = -1 출력
            } else {   // 최대 힙이 비어있지 않다면 (선물 있음)
                cout << pq.top() << '\n';   // 제일 앞의 선물 출력
                pq.pop();   // 준 선물 비우기
            }
        } else { //선물을 충전하는 경우
            while (a--) {   // a만큼 반복
                cin >> input;   // 충전 값 입력받기
                pq.push(input); // 충전된 선물 힙에 넣기
            }
        }
    }
    return 0;
}