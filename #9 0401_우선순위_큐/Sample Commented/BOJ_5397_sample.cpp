/* 키로거 */

#include <iostream>
#include <deque>

using namespace std;

string dqToString(deque<char> &dq) {
    string ans = "";    // 결과값 저장할 위치
    while (!dq.empty()) {   // 힙이 비어있지 않을 때까지 반복
        ans += dq.front();  // 제일 앞의 원소를 ans에 추가
        dq.pop_front(); // 제일 앞의 원소 삭제
    }
    return ans;     // 결과값 반환
}

string findPass(string s) {
    deque<char> dq_left;  // 커서 이전 내용
    deque<char> dq_right; // 커서 이후 내용

    for (int i = 0; i < s.length(); i++) {  // 테스트케이스의 길이만큼 반복
        switch (s[i]) { // 테스크케이스의 각 문자마다 어느 case인지 확인
            case '-': //현재 커서 앞에 있는 글자를 지운다.
                if (!dq_left.empty()) {     // 커서 이전 내용이 있다면
                    dq_left.pop_back();     // 커서 이전 내용 중 제일 뒤의 원소 삭제
                }
                break;
            case '<': //커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
                if (!dq_left.empty()) {     // 커서 이전 내용이 있다면
                    dq_right.push_front(dq_left.back());    // 커서 이전 내용 중 제일 뒤의 원소를 커서 이후 내용의 제일 앞으로
                    dq_left.pop_back();     // 커서 이전 내용 중 제일 뒤의 원소 삭제
                }
                break;
            case '>': //커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
                if (!dq_right.empty()) {    // 커서 이후 내용이 있다면
                    dq_left.push_back(dq_right.front());    // 커서 이후 내용 중 제일 뒤의 원소를 커서 이전 내용의 제일 앞으로
                    dq_right.pop_front();   // 커서 이후 내용 중 제일 뒤의 원소 삭제
                }
                break;
            default: //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
                dq_left.push_back(s[i]);
                break;
        }
    }

    string pass = dqToString(dq_left);  // 커서 이전 내용을 string으로 변환해서 pass에 저장
    pass += dqToString(dq_right);   // 커서 이후 내용을 string으로 변환해서 pass에 추가 (뒤에 붙이기)
    return pass;    // pass, 비밀번호 반환
}

int main() {
    int t; // 테스트케이스의 개수 t
    string s;  // 테스트케이스 s

    cin >> t;   // 개수 입력받기
    while (t--) {   // 개수만큼 반복
        cin >> s;   // 테스트케이스 입력받기

        cout << findPass(s) << '\n';    // 비밀번호 연산 + 출력하기
    }
    return 0;
}