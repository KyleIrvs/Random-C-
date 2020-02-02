#include<iostream>
#include<cmath>
using namespace std;


int findFactors(int num){
  int count = 0;
  double halfN = num / 2;
  int loopCount = 1;

  while (loopCount <= halfN){
    if(num % loopCount == 0){
    count ++;
    }
    loopCount++;
  }
  count ++;

  return count;
}


void findAnti(int amt){
  int ibest = 1;
  int bestNum = 1;
  int arrBest[300] = {0};
  int cc = 1;
  int xx = 0;
  int looper = 1;
  double halfC = 0;
  int checkNum;
  while(cc <= amt) {
  checkNum = findFactors(cc);
    if ( checkNum > ibest) {
      bestNum = cc;
      ibest = checkNum;
      for (xx = 0; xx < ibest; xx++ ){
        arrBest[xx] = 0;
      }

      halfC = bestNum / 2;

      xx = 0;
      looper = 1;
      while(looper <= bestNum/2){
        if(bestNum % looper == 0) {
          arrBest[xx] = looper;
          xx++;
        }
        looper++;
      }
      arrBest[xx] = looper-1;

    }
    cc++;
  }
  xx = 0;
  cout << "Best 'Anti-prime' before " << amt << " is " << bestNum << endl;
  cout << "It's factors are: " << endl;
  for(int c = 0; c < ibest; c++){
    cout << arrBest[c] << endl;
  }
  cout << "Totalling " << ibest << " factors" << endl;
}

int main (){
  int inNum;
  cout << "How many numbers do you want to look for to find the best 'Anti-prime'?" << endl;
  cin >> inNum;
  if (inNum > 100000) {
    cout << "Bruh...." << endl << "You're gonna be waiting" << endl;
  }
  findAnti(inNum);
  return 0;
}
