#include <iostream>

using namespace std;


int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        cout << "Case #" << i + 1 << ": " << A + B << endl;
    }
}

// 메모
// `Case #` 접두사를 빼먹어 한번의 '틀렸습니다'를 맛보았다.
