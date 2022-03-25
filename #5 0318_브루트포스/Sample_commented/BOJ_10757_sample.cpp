/* 큰 수 A+B : Sample */

#include <iostream>
#include <stack>

using namespace std;

stack<int> calcPlus(string &a, string &b) // 더하기 (&를 적는 것이 중요....? 아마...?)
{
    stack<int> st;           // 결과값 저장할 스택 선언
    int p1 = a.length() - 1; // a의 일의 자릿수 인덱스
    int p2 = b.length() - 1; // b의 일의 자릿수 인덱스
    bool carry = false;      // 연산 결과가 10보다 클 경우, 올림 체크 변수

    while (p1 >= 0 && p2 >= 0) // a나 b 중 한 숫자의 연산이 끝날 때까지 반복
    {
        int num = (a[p1--] - '0') + (b[p2--] - '0'); // a와 b의 각 자릿수 값 더하기
        num += carry;                                // 올림 체크 변수 num에 더하기
        carry = num / 10;                            // 자릿수 더한 값이 10을 넘으면 올림변수 체크
        st.push(num % 10);                           // 올림값 제외한 값만 스택에 저장
    }
    while (p1 >= 0) // 더 큰 수인 a에서 남은 자릿수...
    {
        int num = (a[p1--] - '0'); // a의 해당 자릿수 값
        num += carry;              // 올림 체크 변수 num에 더하기
        carry = num / 10;          // 자릿수가 10을 넘으면 올림변수 체크
        st.push(num % 10);         // 올림값 제외한 값만 스택에 저장
    }
    if (carry) // 올림 체크 변수가 있을 때까지 (마지막 올림 확인)
    {
        st.push(1); // 스택에 1 저장
    }

    return st; // 결과값 스택 반환
}

int main()
{
    string a, b;   // a, b 입력받을 위치
    stack<int> st; // 연산 결과값 저장 위치

    cin >> a >> b; // a, b 입력받기

    if (a.length() < b.length()) // b의 자릿수가 더 많으면
    {
        swap(a, b); // a, b 저장 데이터 바꾸기 (더 큰 수를 a로)
    }
    st = calcPlus(a, b); // a + b 연산 (더하기 함수 호출)

    while (!st.empty()) // 연산 결과값 저장 스택이 빌 때까지 반복
    {
        cout << st.top(); // 가장 위의 원소 출력
        st.pop();         // 출력한 가장 위의 원소 pop
    }
    cout << '\n'; // 줄 바꾸기

    return 0;
}