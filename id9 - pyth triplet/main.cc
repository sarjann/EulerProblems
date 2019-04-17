#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000 - i; j++) {
            for (int k = 1; k <= 1000 -i - j; k++) {
                if (((i*i + j*j) == k*k) and ((i + j + k) == 1000)) {
                    cout << i << endl;
                    cout << j << endl;
                    cout << k << endl;
                    cout << i*j*k <<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
