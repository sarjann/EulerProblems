#include <iostream>
#include <cmath>
#include <list>
#include <iterator>

using namespace std;

int main() {
    int sum_nat = 100 * 101 / 2;
    int square_nats = sum_nat * sum_nat;
    int sum_squares = 0;
    for (int i = 1; i <= 100; i++) {
        sum_squares += i * i;
    }
    int diff = square_nats - sum_squares;
    cout << diff;
}
