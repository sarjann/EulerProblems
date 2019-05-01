#include <iostream>
#include <ctime>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <sstream>

using namespace std;
using boost::multiprecision::cpp_int;

int main(){
    cpp_int value = 2;
    for (int i = 0; i < 999; i++){
        value *= 2;
    }

    stringstream ss;
    ss << value;

    string num_string = ss.str();
    cout << num_string << endl;

    int sum = 0;

    for (int i = 0; i < num_string.length(); i++){
        sum += num_string[i] - '0';
    }

    cout << sum << endl;
}
