#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;
namespace mp = boost::multiprecision;

// Mainly venn diagrams to solve, can start from n = 3 as having a length of two can't contain 1, A and 0.

int main(){
    cpp_int sum = 0;
    for (int n = 3; n <= 16; n++){
        sum += 41*mp::pow(cpp_int(14), n-1) - 43*mp::pow(cpp_int(15), n-1) + 15*mp::pow(cpp_int(16), n-1)
                - mp::pow(cpp_int(13), n);
    }

    cout << hex << sum << endl;
}
