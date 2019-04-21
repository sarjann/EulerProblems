#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string strtext = "";
string new_string = "";
char first_letter;
char second_letter;
char third_letter;

char lower_case[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int sum_ascii(string cracked_string){
  int sum = 0;
  int length = cracked_string.length();
  for (int i = 0; i < length; i++){
    sum += cracked_string[i];
  }
  return sum;
}
int main () {
  clock_t start;
  double duration;
  start = clock();

  string line;
  ifstream myfile ("input");
  if (myfile.is_open())
  {
    while ( getline (myfile,line, ',') )
    {
      strtext += (char) stoi(line);
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  int length = strtext.length();

  cout << "---" << endl;;

  for (int i = 0; i <= 25; i++){
  	for (int j = 0; j <= 25; j++){
  		for (int k = 0; k <= 25; k++){
  			first_letter = lower_case[i];
  			second_letter = lower_case[j];
  			third_letter = lower_case[k];
  			for (int l = 0; l < length; l++){
  				if (l % 3 == 0){
  					new_string += strtext[l] ^ first_letter;
  				}
  				else if (l % 3 == 1){
  					new_string += strtext[l] ^ second_letter;
  				}
  				else if (l % 3 == 2){
  					new_string += strtext[l] ^ third_letter;
  				}
  			}
  			cout << new_string << endl;
        if ((new_string.find("this") != string::npos) && (new_string.find("be") != string::npos) && (new_string.find("to") != string::npos)) {
          cout << "Found: " << first_letter << second_letter << third_letter << endl;
          cout << sum_ascii(new_string) << endl;

          duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
          cout << duration*1000 << "ms"<< endl;
          return 0;
        }

  			new_string = "";
  		}
  	}
  }

  return 0;
}
