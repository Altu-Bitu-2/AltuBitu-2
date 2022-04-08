/* Yonsei TOTO */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//가장 마일리지가 적게드는 과목부터 수강
int maxClass(int m, priority_queue<int, vector<int>, greater<>> &pq) {
    int result = 0;     // 들을 수 있는 과목 개수
    while (!pq.empty() && pq.top() <= m) { //더이상 들을 과목이 없거나, 마일리지가 모자를 때까지 반복
        m -= pq.top();  // 주어진 마일리지에서 pq 가장 위의 원소만큼 빼기
        pq.pop();   // pq 원소 pop
        result++;   // 과목 수 증가
    }
    return result;  // 과목 개수 반환
}

int main() {
    int n, m, p, l;     // 순서대로 과목 수, 마일리지, 신청한 사람 수, 수강인원
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙

    cin >> n >> m;  // 과목 수와 주어진 마일리지 입력받기
    while (n--) {   // 과목 수만큼 반복
        cin >> p >> l;  // 신청한 사람 수와 수강인원 입력받기
        vector<int> arr(p); // 각 사람이 넣은 마일리지 저장할 위치
        for (int i = 0; i < p; i++) {   // 신청한 사람 수 만큼 반복
            cin >> arr[i];  // 각 사람이 넣은 마일리지 입력받기
        }

        if (p < l) { // 수강인원이 미달이라면
            pq.push(1);  // 마일리지를 1만 넣어도 수강 가능
            continue;
        }
        sort(arr.begin(), arr.end(), greater<>()); // 각 사람이 넣은 마일리지 내림차순 정렬
        pq.push(arr[l - 1]); // 첫번째로 마일리지를 많이 넣은 사람과 같은 양의 마일리지를 넣어야 수강 가능
    }

    cout << maxClass(m, pq);    // 주어진 마일리지로 최대로 들을 수 있는 과목 개수 출력
}