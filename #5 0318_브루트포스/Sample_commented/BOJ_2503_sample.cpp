/* 숫자 야구 : Sample*/

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

struct baseball
{
    string num;       //서로 다른 세 자리 수
    int strike, ball; //스트라이크 개수, 볼 개수
};

ci cntStrikeBall(string &s1, string &s2)
{
    int strike_cnt = 0; // s1과 s2사이의 strike 개수
    int ball_cnt = 0;   // s1과 s2사이의 ball 개수

    for (int i = 0; i < 3; i++) // 3자리니까 3번 반복
    {
        if (s1[i] == s2[i]) //위치 & 수 정확히 일치 -> 스트라이크
        {
            strike_cnt++; // strike 개수 증가
        }
        else if (s1.find(s2[i]) != s1.npos) // 위치 다른데 수가 존재 -> 볼
        {
            ball_cnt++; // ball 개수 증가
        }
    }

    return ci(strike_cnt, ball_cnt); // strike, ball 개수 반환
}

int game(int n, vector<baseball> &question)
{
    int ans = 0; //정답 개수

    for (int i = 123; i <= 987; i++) // 나올 수 있는 최소 숫자 조합부터, 최대 숫자 조합까지 반복
    {
        bool check = true;        // 참, 거짓 확인
        string s1 = to_string(i); //정답인지 확인할 수

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') // 0이 하나라도 있다면
        {
            continue; // 계속
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) //서로 같은 수가 하나라도 있다면
        {
            continue; // 계속
        }

        for (int j = 0; j < n; j++) // 입력받은 질문 개수만큼 반복
        {
            string s2 = question[j].num;                                           // 질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2);                                        // s1과 s2사이의 스트라이크와 볼 개수
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) //하나라도 다르면
            {
                check = false; // 거짓 : 틀림
                break;
            }
        }

        if (check) // 참 : 맞음 이면
        {
            ans++; // 가능성 있는 답의 개수 증가
        }
    }

    return ans; // 가능성 있는 답의 개수 반환
}

int main()
{
    int n; // 질문 개수

    cin >> n; // 질문 개수 입력받기

    vector<baseball> question(n); // 질문 답
    for (int i = 0; i < n; i++)   // 질문 개수만큼 반복
    {
        cin >> question[i].num >> question[i].strike >> question[i].ball; // 질문 답 입력받기
    }

    cout << game(n, question); // 영수가 생각하고 있을 가능성이 있는 답의 총 개수 출력

    return 0;
}