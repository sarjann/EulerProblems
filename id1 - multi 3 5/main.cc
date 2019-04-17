#include <iostream>
using namespace std;

bool test(int);

int main(){
	long sum = 0;
	for(int n = 0 ;n<10000000; n++){
		if (test(n)){
		sum = sum + n;
		}
	}
	cout << sum;
}

bool test(int n){
	if (n%3 == 0){
		return true;
	}
	if (n%5 == 0){
		return true;
	}
	return false;
}
