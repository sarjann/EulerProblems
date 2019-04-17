#include <iostream>
#include <cmath>

using namespace std;

long long triangle_number(int);
int divisors(long long);

int main() {
    int start = 0;
    long long tri = triangle_number(start);
    for (int i = start + 1; true; i++){
        tri += i;
//        cout << tri << endl;
        int div = divisors(tri);
//        cout << div <<endl;
        if (i%100==0) {
            cout << i << endl;
        }
        if (div >= 300){
            cout << "Current div: ";
            cout << div <<endl;
        }
        if (div >= 500){
            cout << tri << endl;
            cout << div <<endl;
            break;
        }

    }
    return 0;
}


long long triangle_number(int n){
    if (n%2==0){
        long long tri_num = n*(n+1)/2;
        return tri_num;
    }
    long long tri_num = n + (n-1)*n/2;
    return tri_num;
}

//int divisors(long long n){
//    int count = 1;
////    for (int j = 1; j <= n; j++){
////        if (n%j == 0){
////            count += 1;
////        }
////    }
//    for (int j = 1; j <= n/2; j++){
////    for (int j = 1; j <= sqrt(n) + 1; j++){
//        if (n%j == 0){
//            count += 1;
//        }
//    }
//    return count;
//}

int divisors(long long n) {
    int count = 0;
    for (int j = 1; j <= sqrt(n) + 1; j++){
        if (n % j == 0) {
            if (n/j == j){
                count += -1;
//                cout << j << endl;
            }
//            cout << j << endl;
//            cout << n/j << endl;
            count += 2;
        }
    }
    return count;
}
