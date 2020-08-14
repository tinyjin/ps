#include <iostream>

using namespace std;

long memo[100] = {};

long fibo(int n) {
    if (n <= 1) return n;
    if (memo[n] > 0) return memo[n];

    long result = fibo(n - 1) + fibo(n - 2);
    memo[n] = result;

    return result;
}

int main() {
    int n;
    cin >> n;

    cout << fibo(n) << endl;
}

// 메모
// 입력값의 최대수가 90이다
// 90일 떄의 피보나치 수는 '2880067194370816120'이다.
// int 타입은 해당 범위의 숫자를 담을 수 없다.
// long으로 선언해야했었는데, int로 선언하여 한번의 '틀렸습니다'를 맛보았다.
