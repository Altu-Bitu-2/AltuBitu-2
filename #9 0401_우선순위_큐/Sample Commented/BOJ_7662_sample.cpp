/* 이중 우선순위 큐 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<bool> is_valid;

void deleteMax(priority_queue<ci> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) { // 힙이 비어있지 않고, is_valid하지 않을 때까지 반복
        heap.pop(); // 힙 pop
    }
}

void deleteMin(priority_queue<ci, vector<ci>, greater<>> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) { // 힙이 비어있지 않고, is_valid하지 않을 때까지 반복
        heap.pop(); // 힙 pop
    }
}

int main() {
    int t, k, n;    // 순서대로 : 테스트데이터 개수, 적용할 연산의 개수, 정수 n
    char cmd;   // 연산을 나타내는 문자

    cin >> t;   // 테스트 데이터 개수 입력받기
    while (t--) {
        priority_queue<ci> max_heap; // 최대 힙
        priority_queue<ci, vector<ci>, greater<>> min_heap; // 최소 힙
        cin >> k;   // 적용할 연산의 개수 입력받기
        int idx = 0; // I 연산으로 입력된 숫자의 인덱스
        while (k--) {   // 연산의 개수만큼 반복
            cin >> cmd >> n;    // 연산을 나타내는 문자와 정수 n 입력받기

            switch (cmd) {  // 입력된 연산 문자에 따라 연산
                case 'I': // 두가지 힙 모두에 값을 넣은 뒤, is_valid 벡터에도 추가
                    max_heap.push(ci(n, idx));  // 최대 힙에 값 넣기
                    min_heap.push(ci(n, idx));  // 최소 힙에 값 넣기
                    is_valid.push_back(true);   // 벡터에도 추가
                    idx++;  // 인덱스 증가
                    break;
                case 'D': // n에 따라 최대 힙 또는 최소 힙에서 데이터 삭제
                    if (n == 1) {   // n이 1이면
                        deleteMax(max_heap); // D연산 전처리
                        if (!max_heap.empty()) { // D연산
                            is_valid[max_heap.top().second] = false;    // 벡터값 false로
                            max_heap.pop(); // 최대 힙 값 삭제
                        }
                    }
                    if (n == -1) {  // n이 -1이면
                        deleteMin(min_heap); // D연산 전처리
                        if (!min_heap.empty()) { // D연산
                            is_valid[min_heap.top().second] = false;    // 벡터값 false로
                            min_heap.pop(); // 최대 힙 값 삭제
                        }
                    }
                    break;
            }
        }
        //마지막으로 각 힙의 top이 valid 하도록 처리
        deleteMax(max_heap);    // 최대 힙에서 top 데이터가 is_valid 할 때까지 pop
        deleteMin(min_heap);    // 최소 힙에서 top 데이터가 is_valid 할 때까지 pop

        if (max_heap.empty()) { // 힙이 비어있다면...
            cout << "EMPTY\n";  // empty 출력
        }
        else {  // 힙이 비어있지 않다면...
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';    // 남아있는 최대값과 최솟값 출력
        }
        is_valid.clear(); // 새로운 테스트 케이스 전 is_valid 벡터 초기화
    }
}