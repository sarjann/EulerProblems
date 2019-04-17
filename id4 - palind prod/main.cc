#include <iostream>
#include <cmath>
using namespace std;

bool ispalandrome(int);

int main(){
    int max_num = 0;
    for(int i=100; i<1000; i++){
        for(int j=100; j<1000; j++){
            int n = i*j;
            if (n > max_num){
                if (ispalandrome(n)){
                    max_num = n;
                }
            }
        }
    }
    cout << max_num;
}


bool ispalandrome(int n){
    int m = n;
    int reverse = 0;
    while(m){
        reverse *= 10;
        reverse += m%10;
        m /= 10;
    }
    if(n == reverse) {
        return true;
    }
    return false;
}