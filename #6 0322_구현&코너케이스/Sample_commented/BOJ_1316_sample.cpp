/* 그룹 단어 체커 */

#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string str) {
    char cur = NULL;    // 현재의 문자
    vector<bool> alphabet(26, false); // 각 알파벳의 등장 여부를 체크 : 알파벳 26개

    for (int i = 0; i < str.size(); i++) {  // 입력받은 단어의 길이만큼 반복
        if (str[i] == cur) { // 연속해서 나타난 문자
            continue;   // 계속하기
        }
        if (alphabet[str[i] - 'a']) {  // 이전의 문자와 다른 문자가 나타났을 때
            return false;   // 그룹 단어 아님
        }
        cur = str[i];   // 현재의 문자 저장
        alphabet[str[i] - 'a'] = true;  //  등장 여부 TRUE로
    }
    return true;   // 그룹 단어 맞음
}

int main() {
    int n, result = 0;  // 단어의 개수 n, 그룹 단어의 개수 result 

    cin >> n;   // n 입력받기
    while (n--) {   // n번 반복
        string word;    // 입력받을 단어 word
        cin >> word;    // word 입력받기

        if (isGroup(word)) { // 그룹 단어인지 확인
            result++;   // 그룹 단어의 개수 증가
        }
    }

    cout << result;     // 그룹 단어 개수 출력
    return 0;
}