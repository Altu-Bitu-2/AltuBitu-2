/* 기숙사 바닥 : Sample */

#include <iostream>

using namespace std;

//기숙사 바닥의 l(높이), w(넓이) 구해서 리턴하는 함수
pair<int, int> length(int r, int b)
{
    int area = r + b;              // 타일 수 합
    for (int i = area; i > 0; i--) // i = l(높이) 의 값
    {
        if (area % i != 0) // w 가 정수가 아니라면 넘어감
        {
            continue; // 계속
        }
        int w = area / i;           // w 계산 : 타일 수 합 나누기 높이
        if (r == ((i + w) * 2 - 4)) // 빨간 타일의 개수가 테두리가 될 수 있다면
        {
            return make_pair(i, w); // l, w pair로 반환
        }
    }
}

int main()
{
    int r, b; // r: 빨간 타일 개수, b: 갈색 타일 개수

    cin >> r >> b; // r, b 입력받기

    pair<int, int> result = length(r, b); // 방 크기 연산

    cout << result.first << ' ' << result.second << '\n'; // 연산 값 l 과 w로 나눠서 출력
    return 0;
}