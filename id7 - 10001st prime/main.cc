#include <iostream>
#include <cmath>
#include <list>
#include <iterator>

using namespace std;

bool check_prime(int);

int main() {
        int prime_count;
        for (int i = 2; true; i++){
        if (check_prime(i)){
            prime_count += 1;
//            cout << "Current number of primes: ";
//            cout << prime_count <<endl;
            if (prime_count == 10001){
                cout << i <<endl;
                break;
            }
        }
        }
}

bool check_prime(int n){
    if (n==2){
        return true;
    }
    int to_check = sqrt(n) + 1;
//    cout <<n <<endl;
    for (int j = 2; j <= to_check; j++ ){
        if (n%j==0){
            return false;
        }
    }
    return true;
}
