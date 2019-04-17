#include <iostream>
#include <cmath>

using namespace std;

bool check_prime(int);

int main() {
    long sum_prime = 0;
    for (int i = 2; i < 2000000; i++){
        if (check_prime(i)){
            sum_prime += i;
        }
    }
    cout << sum_prime;
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
