#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int calcPi(long long int accuracyNum) {
  long long int count = 0;
  float piVal = 0;

  while (count < accuracyNum){
    if (count % 2 == 0) {
      piVal += (1.0 / ((2 * count) + 1.0));
      //cout << (1 / ((2 * count) + 1)) << endl;
    } else {
      piVal -= (1.0 / ((2 * count) + 1.0));
    }
    count++;
    //cout << "PI value after " << count << " iterations = " << piVal * 4.0  << endl;
  }
  cout << "PI value after " << count << " iterations = " << piVal * 4.0  << endl;

}

int main() {
  long long int acc;
  cout << setprecision(20) << fixed;
  cout << "How accurate do you want to be?" << endl << "A higher number will be more accurate to PI" << endl;
  cin >> acc;
  calcPi(acc);
  return 0;

}
