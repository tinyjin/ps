#include <iostream>

using namespace std;

int main() {
    int idx;
    int max = -1;

    for (int i = 0; i < 9; i++) {
        int count;
        cin >> count;

        if (count > max) {
            max = count;
            idx = i;
        }
    }

    cout << max << endl;
    cout << idx + 1 << endl;
}
