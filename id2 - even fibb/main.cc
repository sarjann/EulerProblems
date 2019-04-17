#include <iostream>
using namespace std;

int main(){
	long sum = 0;
	int prev = 1;
	int current = 2;
	for (;;){
	if (current > 4000000){
		break;
	}
	if (current%2 == 0){
		sum = sum + current;
	}
	current = current + prev;
	prev = current - prev;
	}
	cout << sum;
}

