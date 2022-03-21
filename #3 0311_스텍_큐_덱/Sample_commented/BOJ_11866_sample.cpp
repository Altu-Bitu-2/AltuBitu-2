/* 요세푸스 문제 0 : Sample */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> simulation(int k, queue<int> &q)
{
    vector<int> result; //요세푸스 순열
    int cnt = 0;        //카운트

    while (!q.empty()) // 큐가 비어있지 않다면...
    {
        int x = q.front(); // x에 큐의 첫번째 원소 저장
        q.pop();           // 큐 비우기
        cnt++;             // 카운트 증가
        if (cnt == k)      // 카운트가 k번째까지 증가했다면
        {
            result.push_back(x); // 연산 결과에 저장해둔 x 넣기
            cnt = 0;             // 카운트 초기화
            continue;            //계속
        }
        q.push(x); // pop한 원소 다시 push
    }
    return result; // 연산 결과 출력
}

int main()
{
    int n, k;     // 양의 정수 n, k번째
    queue<int> q; // 저장해둘 큐

    cin >> n >> k;               // n ,k 입력받기
    for (int i = 1; i <= n; i++) // n만큼 반복
    {
        q.push(i); //큐 초기화 (1~n)
    }

    vector<int> result = simulation(k, q); //연산

    cout << '<';                                // 괄호
    for (int i = 0; i < result.size() - 1; i++) // 연산 결과 길이만큼 반복
    {
        cout << result[i] << ", "; // 결과값 출력
    }
    cout << result[result.size() - 1] << '>'; // 괄호
    return 0;
}
