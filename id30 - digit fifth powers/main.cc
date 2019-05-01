#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool check_digit(int value){
    stringstream ss;
    ss << value;

    string num_string = ss.str();

    int sum = 0;

    for (int i = 0; i < num_string.length(); i++){
        int digit = num_string[i] - '0';
        sum += pow(digit, 5);
    }

    if (sum == value){
        return true;
    }

    return false;
}

int main(){
    int sum = 0;
    for (int i = 2; i <= 999999; i++){
        bool check = check_digit(i);
        if (check){
            sum += i;
            }
    }

    cout << sum << endl;
}
