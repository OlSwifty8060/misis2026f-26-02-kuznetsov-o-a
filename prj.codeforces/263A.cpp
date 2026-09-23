#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    int row = 0, col = 0, x;

    for (int i = 0; i < 25; i = i + 1) {
        cin >> x;
        if (x = 1) {
            row = i / 5 + 1;
            col = i % 5 + 1;
        }
    }
     cout << abs(row - 3 ) + abs(col - 3 ) << endl;
     return 0;
}