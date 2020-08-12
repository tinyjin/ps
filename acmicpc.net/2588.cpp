#include <iostream>

using namespace std;

int main() {
    int N;
    int M;
    int result;

    cin >> N;
    cin >> M;
    result = N * M;

    while(M > 0) {
        int n = M % 10;
        M /= 10;

        cout << n * N << endl;
    }

    cout << result << endl;

    return 0;
}
