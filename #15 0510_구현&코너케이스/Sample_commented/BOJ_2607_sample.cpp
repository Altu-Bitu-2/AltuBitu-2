/* 비슷한 단어 : Sample */

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;

// 알파벳별 등장횟수 저장
vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0);    // 알파벳 등장 횟수
    for (int i = 0; i < str.size(); i++) {  // 비교할 단어 길이만큼
        result[str[i] - 'A']++; // 등장 횟수 업데이트
    }
    return result;  // 등장 횟수 반환
}

int main() {
    int n, ans = 0; // 단어의 개수 n, 비슷한 단어의 개수 ans(0으로 초기화)
    string source, target;  // 첫번째 단어, 나머지 단어

    //입력
    cin >> n >> source; // 단어 개수 & 첫번째 단어 입력받기

    //연산
    vector<int> source_alpha = alphaMap(source);
    while (--n) {    // 단어 개수만큼 반복
        cin >> target;  // 비교할 나머지 단어 중 하나 입력받기

        int diff = 0;   // 단어의 차이
        vector<int> target_alpha = alphaMap(target);    // 비교할 단어에 어느 알파벳이 몇개...
        for (int i = 0; i < SIZE; i++) { // 알파벳 26개만큼 반복
            diff += abs(source_alpha[i] - target_alpha[i]); // 두 단어의 차이
        }
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) { // 문자를 더하거나, 빼거나, 바꾸거나... 차이가 비슷한 단어 기준에 맞으면
            ans++;  // 비슷한 단어 개수 증가
        }
    }

    //출력
    cout << ans;    // 첫번째 단어와 비슷한 단어의 개수 출력
    return 0;
}