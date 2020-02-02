#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int Nilakantha(long long int ac){
  double piVal = 3;
  long long int count = 0;
  while(count < ac){
    if(count % 2 == 0) {
      piVal += (4.0/(((2.0*count)+2.0)*((2.0*count)+3.0)*((2.0*count)+4.0)));
    } else {
      piVal -= (4.0/(((2.0*count)+2.0)*((2.0*count)+3.0)*((2.0*count)+4.0)));
    }
    count++;
    //cout << "PI value after " << count << " iterations = " << piVal  << endl;
  }
  cout << "PI value after " << count << " iterations = " << piVal  << endl;
  return 0;
}

int main() {
  long long int acc;
  cout << setprecision(50) << fixed;
  cout << "How accurate do you want to be?" << endl << "A higher number will be more accurate to PI" << endl;
  cin >> acc;
  Nilakantha(acc);
  return 0;
}
