#include <iostream>

using namespace std;

int fac(int n) {
    // n이 0일 때 예외처리
    if (n <= 1) return 1;

    return n * fac(n - 1);
}

int main() {
    int N;

    cin >> N;
    cout << fac(N);

    return 0;
}

// 재귀 함수
// 메모
// N이 0일 때 예외처리를 하지 않아 시간 초과가 떴었다.
// N이 0일 때 함수 결과를 0으로 리턴하여 틀렸습니다.가 떴었다.
