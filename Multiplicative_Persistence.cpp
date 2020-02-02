#include<iostream>
#include<string>
using namespace std;


int findPer(unsigned long long int num,int c){
  int count = c;
  unsigned long long int tNum = num;
  int arrSize = to_string(num).length();
  int arrNum[arrSize];


  if (tNum > 9) {
    for (int i = arrSize-1; i >= 0; i--){
      arrNum[i] = tNum % 10;
      tNum /=10;
    }

    tNum = arrNum[0];
    for (int x = 1;x < arrSize; x++ ){
      tNum *= arrNum[x];
    }

  } else {
    return count;
  }

  count ++;
  findPer(tNum, count);

  //return count;
}

int main () {

  int persFound = 0;
  int desiredPers;
  cout << "How many persistence values do you want to find?"<< endl;
  cin >> desiredPers;
  if (desiredPers > 11) {
    cout << "Cannot find any higher than 11";
  } else {
  cout << "Finding Persistence Values..." << endl;
  unsigned long long int x = 0;
  while (persFound <= desiredPers ){
    while ( findPer(x,0) != persFound ) {
      x++;
      //TODO: Check values for number and make sure that after 2nd digit, make sure they are 7,8 or 9 only!!
      /*if (to_string(x).length() > 5){
        string sNum = to_string(x);
        cout << sNum;
        break;
      }*/
    }
    cout << "Smallest number with Multiplicative Persistence of " << persFound << " is: " << x << endl;
    persFound++;
  }
}
  return 0;
}
