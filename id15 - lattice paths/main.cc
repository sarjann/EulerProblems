#include <iostream>
#include <string>
#include <tuple>
#include <stdlib.h>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    vector<long> prev = {1};
    vector<long> current = {1};

    for (int i = 1; i <= 20; i++){

        for (int l = 0; l < current.size(); l++){
            cout << current[l] << endl;
        }

        cout << "--------------" << endl;
        current.clear();
        current.push_back(1);

        if (i != 1) {
            for (int j = 0; j <= prev.size() - 2; j++){
                current.push_back(prev[j] + prev[j + 1]);
            }
        }
        current.push_back(1);

        prev.clear();
        for (int k = 0; k < current.size(); k++){
            prev.push_back(current[k]);
        }
    }

    prev.clear();
    for (int k = 0; k < current.size(); k++){
        prev.push_back(current[k]);
    }
    cout << prev.size() << endl;

    while(prev.size() != 1){
        current.clear();

        for (int l = 0; l < prev.size(); l++){
            cout << prev[l] << endl;
        }

        for (int j = 0; j <= prev.size() - 2; j++){
            current.push_back(prev[j] + prev[j + 1]);
        }

        prev.clear();

        for (int k = 0; k < current.size(); k++){
            prev.push_back(current[k]);
        }

        cout << "--------------" << endl;

    }

    for (int l = 0; l < prev.size(); l++){
        cout << prev[l] << endl;
    }
    return 0;
}
