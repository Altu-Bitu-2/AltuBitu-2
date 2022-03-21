/* 괄호의 값 : Sample */

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int calc(string s)
{
    stack<char> st;          // 괄호 값 저장할 스택
    map<char, int> num;      //괄호 값
    map<char, char> bracket; //괄호 쌍

    //괄호 모양에 따른 쌍과 값 저장
    bracket[')'] = '(';
    bracket[']'] = '[';
    num['('] = 2;
    num['['] = 3;

    int ans = 0, temp = 1;
    for (int i = 0; i < s.length(); i++) // 괄호열의 길이만큼 반복
    {
        switch (s[i]) // 괄호열의 모양에 따라...
        {
        case '(':              // '('인 경우
        case '[':              // '['인 경우
            st.push(s[i]);     // 스택에 괄호 추가
            temp *= num[s[i]]; // 임시 연산 업데이트
            break;
        case ')':                                        // ')'인 경우
        case ']':                                        // ']'인 경우
            if (st.empty() || st.top() != bracket[s[i]]) // 올바른 스택 상태가 아닐 경우
            {
                return 0; // 0 반환
            }
            if (s[i - 1] == bracket[s[i]]) // 괄호열의 값에 따라...
            {
                ans += temp; // 연산 결과 업데이트
            }
            temp /= num[bracket[s[i]]]; //이미 값을 더한 경우는 나누기
            st.pop();                   // 스택 비우기
            break;
        }
    }
    if (st.empty()) // 괄호 스택이 비어있으면 바른 괄호
    {
        return ans; // 연산 결과 반환
    }
    return 0; // 0 반환
}

int main()
{
    string s; // 괄호열

    cin >> s;        // 괄호열 입력받기
    cout << calc(s); // 괄호열에 따른 연산
    return 0;
}