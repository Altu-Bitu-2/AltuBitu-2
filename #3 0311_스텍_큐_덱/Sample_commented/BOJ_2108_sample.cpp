/* 통계학 : Sample */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 4000; // 정수의 절댓값 최대치

int findMode(vector<int> &frequency)
{
    int max_value = 0;                  // 최빈값의 빈도수
    for (int i = 0; i <= SIZE * 2; i++) // 음수 양수를 모두 포함한만큼 반복
    {
        if (frequency[i] > max_value) // 빈도수가 max_value보다 클 때
            max_value = frequency[i]; // max_value를 해당 빈도수로 변경
    }

    int cnt = 0;                        // 최빈값 개수
    int mode = 0;                       // 최빈값
    for (int i = 0; i <= SIZE * 2; i++) // 음수 양수를 모두 포함한만큼 반복
    {
        if (frequency[i] == max_value) // 빈도수가 max_value와 같을 때
        {
            mode = i - SIZE; // 실제 값을 저장 (더해두었던 SIZE 빼기)
            cnt++;           // 개수 증가
            if (cnt == 2)    //두 번째로 작은 최빈값
                break;
        }
    }

    return mode; // 최빈값 반환
}

int main()
{
    int n; // 홀수인 n

    cin >> n; // 입력받기

    vector<int> num(n);                     // 숫자들 저장 위치
    vector<int> frequency(SIZE * 2 + 1, 0); //인덱스는 입력 수 + 4000의 값. 따라서 0 ~ 8000. 각 인덱스에 해당 수가 얼마나 나왔는지 저장

    int sum = 0;                // 합 저장하는 위치
    for (int i = 0; i < n; i++) // n만큼 반복
    {
        cin >> num[i];              // 입력 받기
        sum += num[i];              // 합에 추가
        frequency[num[i] + SIZE]++; // 빈도 증가
    }

    sort(num.begin(), num.end()); // 정렬

    //산술평균
    if (round((double)sum / n) == -0) // -0이 나오는 경우에는 이렇게 대처
        cout << "0\n";
    else
        cout << round((double)sum / n) << '\n'; // 일반 결과값에는 그냥 출력
    cout << num[n / 2] << '\n';                 //중앙값
    cout << findMode(frequency) << '\n';        //최빈값
    cout << num[n - 1] - num[0] << '\n';        //범위

    return 0;
}