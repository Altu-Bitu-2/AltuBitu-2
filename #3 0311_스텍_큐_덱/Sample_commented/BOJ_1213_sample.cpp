/* 팰린드롬 만들기 : Sample */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 26; // 'A~Z'까지 알파벳 26개

vector<int> countAlphabet(string text) // 문자열 속 알파벳 빈도 확인 함수
{
    vector<int> count(SIZE, 0);           // 'A~Z'까지 알파벳 빈도를 저장할 위치
    for (int i = 0; i < text.size(); i++) // 입력된 이름의 길이만큼 반복
    {
        count[text[i] - 'A']++; // 문자를 숫자(인덱스)로 바꿔 기록하기 위해 'A'의 인덱스 빼기
    }
    return count; // 알파벳 빈도 반환
}

string makePalindrome(vector<int> &count) // 팰린드롬 만드는 함수
{
    string part1 = "", part2 = "", part3 = ""; // 팰린드롬을 세 파트로 나눠 만든 후 저장할 위치

    for (int i = 0; i < SIZE; i++) // 알파벳 26개 모두 확인
    {
        if (count[i] % 2 == 1) // 알파벳의 빈도 수가 홀수일 경우
        {
            if (part2.size() == 1) // 저장된 part2(가운데 글자)가 이미 존재하는 경우
            {
                return "I'm Sorry Hansoo";
            }
            part2 = (char)(i + 'A'); // 저장된 part2가 없는 경우 알파벳 할당
        }
        for (int j = 0; j < count[i] / 2; j++) // 남은 빈도 수의 절반만큼 반복
        {
            part1 += (char)(i + 'A');        // part1(팰린드롬 전반부)에 저장
            part3 = (char)(i + 'A') + part3; // part3(팰린드롬 후반부)에 저장
        }
    }

    return part1 + part2 + part3; // 팰린드롬 세파트 붙여서 반환
}

int main()
{
    string input; // 임한수의 영어이름 저장할 위치
    cin >> input; // 임한수의 영어이름 입력받기

    vector<int> count = countAlphabet(input); // 알파벳 빈도 확인
    cout << makePalindrome(count);            // 팰린드롬 출력

    return 0;
}