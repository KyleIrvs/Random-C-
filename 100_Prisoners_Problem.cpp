#include<iostream>
#include<ctime>
using namespace std;


int arrPrisonerNums[100];
int arrBoxNums[100];
int arrAllNums[100];

double iPass, iFail = 0;

void populateBoxes() {

  int randoNum = rand() % 100;
  for (int i = 0; i < 100; i++){
    arrPrisonerNums[i] = i;
    arrAllNums[i] = i;
  }
  for (int j = 0; j < 100; j++){
    randoNum = rand() % 100;
    while (arrAllNums[randoNum] == -1){
      randoNum = rand() % 100;
    }

    arrBoxNums[j] = arrAllNums[randoNum];
    arrAllNums[randoNum] = -1;
  }


}

void findBoxes() {
  bool noFind = false;
  int i = 0;
  int foundNumber, prisonerNumber, index = 0;

  while ((!noFind) && (i < 100)){
    prisonerNumber = i;
    index = prisonerNumber;
    foundNumber = arrBoxNums[index];
      for (int k = 0; k < 50; k++){
        if (foundNumber == prisonerNumber) {
          break;
        } else {
          index = foundNumber;
          foundNumber = arrBoxNums[index];
        }
      }
      if (arrBoxNums[index] == prisonerNumber) {
        i++;
      } else {
        noFind = true;
    }
  }
  if (noFind){
      iFail++;
  } else {
    iPass++;
  }
}
int main () {
  srand(time(0));
  int amnt;
  cout << "How many times must this be performed?" << endl;
  cin >> amnt;
  for (int i = 0; i < amnt; i++) {
    populateBoxes();
    findBoxes();
  }

  cout << "Pass chances that round: " << to_string((iPass/amnt)*100)  << endl;
  cout << "Challenges passed: " << to_string(iPass) << endl;
  cout << "Challenges failed: " << to_string(iFail) << endl;
  return 0;
}
