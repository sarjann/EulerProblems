#include <iostream>
#include <cmath>
#include <list>
#include <iterator>

using namespace std;

bool test_mult(int);

int main() {
    int min_num = 0;
    for (int i = 1; true ; i++) {
        if (test_mult(i)){
            min_num = i;
            break;
        }
    }
    cout << min_num <<endl;

}

bool test_mult(int n){
    if ((n%6==0) and (n%7==0) and (n%8==0) and (n%9==0) and (n%11==0) and (n%12==0) and (n%13==0)
    and (n%14==0) and (n%15==0) and (n%16==0) and (n%17==0) and (n%18==0) and (n%19==0) and (n%20==0)) {
        return true;
    }
    return false;
}
