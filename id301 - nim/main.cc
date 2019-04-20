#include <iostream>
#include <unistd.h>
#include <vector>
#include <ctime>
#include <cmath>

#define NUM_LEVELS pow(2,30)
using namespace std;

int main(){
    long count = 0;
    for (long i = 1; i <= NUM_LEVELS; i++){
        if ((i ^ 2*i ^ 3*i) == 0){
            count += 1;
        }
    }
    cout << count << endl;
}
