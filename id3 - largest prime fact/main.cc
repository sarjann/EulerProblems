#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int);

int main(){
	long n = 600851475143;
	int i = 2;
	while(i*i <= n){
	if (n%i == 0){
	if(isprime(i)){
	cout << i <<endl;
	}
	}
	i = i + 1;
	}
}

bool isprime(int n){
	for(int i=2; i<sqrt(n)+1; i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
