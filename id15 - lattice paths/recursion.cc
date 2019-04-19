#include <iostream>
#include <string>
#include <tuple>
#include <stdlib.h>
//Naive and very inefficient
using namespace std;

int count = 0;

struct route {
    int right;
    int down;
};

int recursion(route);

int main() {
    route current = route {20, 20};
    recursion(current);
    cout << count << endl;
    return 0;
}

int recursion(route cur_route){
    if (cur_route.right == 0 && cur_route.down == 0){
        count += 1;
        return 0;
    }

    if (cur_route.right < 0 || cur_route.down < 0){
        return 0;
    }

    route route_right = route {cur_route.right - 1, cur_route.down};
    recursion(route_right);

    route route_down = route {cur_route.right, cur_route.down - 1};
    recursion(route_down);

    return 0;
}
