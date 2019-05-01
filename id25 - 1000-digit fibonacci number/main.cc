#include <iostream>
#include <ctime>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <sstream>

using namespace std;
using boost::multiprecision::cpp_int;


int main(){
    cpp_int prev = 1;
    cpp_int curr = 1;
    cpp_int temp;

    for (int i = 3; ; i++){
        temp = curr;
        curr += prev;
        prev = temp;

        stringstream ss;
        ss << curr;
        string curr_string = ss.str();

        if (curr_string.length() >= 1000){
            cout << "Index of number: " << i << endl;
            break;
        }
    }

}
