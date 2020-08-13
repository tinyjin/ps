#include <iostream>

using namespace std;

int main() {
    int A, B;

    while(true) {
        cin >> A >> B;

        if (cin.eof()) {
            break;
        }

        cout << A + B << endl;
    }
}

// 메모
// cin.eof()로 입력값이 더 이상 없는지 판별할 수 있다.
// cin.eof()에 대한 break 조건을 출력 구문 이후 판별되도록 작성하여
// 한번의 '틀렸습니다'를 맛보았다.
// 입력 받자마자 cin.eof()에 대한 조건 검사를 하여, 문제를 해결함.
