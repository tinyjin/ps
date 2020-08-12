#include <iostream>

using namespace std;

int main() {
    int X;
    int Y;

    cin >> X;
    cin >> Y;

    if (X > 0 && Y > 0) cout << 1;
    if (X < 0 && Y > 0) cout << 2;
    if (X < 0 && Y < 0) cout << 3;
    if (X > 0 && Y < 0) cout << 4;


    return 0;
}
