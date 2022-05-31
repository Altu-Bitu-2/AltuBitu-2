/* 후보 추천하기 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

bool cmp(const pair<int, ci> &c1, const pair<int, ci> &c2) {    // 오름차순 정렬
    if (c1.second.first != c2.second.first) {   // 둘이 같지 않다면
        return c1.second.first < c2.second.first;   // 크기 비교 결과 반환
    }
    return c1.second.second < c2.second.second; // 크기 비교 결과 반환
}

int main() {
    int n, m, input;    // 사진 개수, 추천 횟수, 학생 번호

    cin >> n >> m;  // 사진 개수, 추천 횟수, 학생 번호 반환
    map<int, ci> candidate; // first: 후보 학생, second: {추천 횟수, 게시 시간}
    for (int i = 0; i < m; i++) {   // 추천 횟수만큼 반복
        cin >> input;   // 추천한 학생 번호 입력받기

        if (candidate.size() == n && candidate.find(input) == candidate.end()) {     // 비어있는 사진틀이 없는 경우
            candidate.erase(min_element(candidate.begin(), candidate.end(), cmp));  // 추천 횟수가 가장 적은 학생의 사진 삭제
        }
        if (candidate.find(input) == candidate.end()) { //첫 게시라면
            candidate[input].second = i;    // 추천 횟수 업데이트
        }
        candidate[input].first++; // 추천 횟수 증가
    }

    for (auto iter = candidate.begin(); iter != candidate.end(); iter++) {  // 증가하는 순서대로...
        cout << iter->first << ' '; // 최종 후보의 학생 번호 출력
    }
    return 0;
} 