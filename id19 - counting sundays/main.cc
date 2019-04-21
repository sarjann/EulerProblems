#include <iostream>
#include <vector>

using namespace std;

int elapsed_year = 0;
int current_year = 1900;

vector <int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    bool leap = false;
    int days = 0;
    int count = 0;
    while (current_year != 2001) {
    for (int month = 0; month < 12; month++){
        if (leap && (month == 1)){
            days += days_in_month[month] + 1;
        }
        else {
            days += days_in_month[month];
        }

        if ((days % 7 == 6) && (current_year > 1900)){
            count += 1;
        }

        if (month == 11){
            elapsed_year += 1;
            current_year += 1;
            if ((current_year % 400 == 0) || ((current_year % 4 == 0) && (current_year % 100 != 0))){
                leap = true;
            }
            else {
                leap = false;
            }
        }
    }
    }

    cout << count << endl;
}
