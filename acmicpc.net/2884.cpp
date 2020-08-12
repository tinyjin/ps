#include <iostream>

using namespace std;

int main() {
    int H;
    int M;

    cin >> H;
    cin >> M;

    M -= 45;

    if (M < 0) {
        M = 60 + M;
        H -= 1;
    }

    if (H < 0) {
        H = 23;
    }

    cout << H << " " << M << endl;

    return 0;
}
