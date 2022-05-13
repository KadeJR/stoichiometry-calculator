#include <iostream>
#include <math.h> 
using namespace std;

float avagadroNum = 6.02 * pow(10, 23);
float STP = 22.4;

//periodic table data
float periodicMass[118] = {1.01, 4.00, 6.94, 9.01, 10.81, 12.01, 14.01, 16.00, 19.00, 20.18, 22.99, 24.30, 26.98, 28.09, 30.97, 32.07, 35.45, 39.95, 39.10, 40.08, 44.96, 47.87, 50.94, 52.00, 54.94, 55.84, 58.93, 58.69, 63.55, 65.39, 69.72, 72.61, 74.92, 78.96, 79.90, 83.80, 85.47, 87.62, 88.91, 91.22, 92.91, 95.94, 98.00, 101.07, 102.91, 106.42, 107.87, 112.41, 114.82, 118.71, 121.76, 127.60, 126.90, 131.29, 132.91, 137.33, 138.91, 140.12, 140.91, 144.24, 145.00, 150.36, 151.96, 200.59, 158.93, 162.50, 164.93, 167.26, 168.93, 173.04, 174.97, 178.49, 180.95, 183.84, 186.21, 190.23, 192.22, 195.08, 196.97, 200.59, 204.38, 207.20, 208.98, 209.00, 210.00, 222.00, 223.00, 226.00, 227.00, 232.04, 231.04, 238.03, 237.00, 244.00, 243.00, 247.00, 247.00, 251.00, 252.00, 257.00, 258.00, 259.00, 262.00, 261.00, 262.00, 263.00, 264.00, 269.00, 266.00, 271.00, 272.00, 277.00, 284.00, 289.00, 288.00, 293.00, 294.00, 294.00};

string periodicSymbols[118] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm" "Md", "Md", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

//gets input and returns it to function
int getSelection() {
  int input;
  cin >> input;
  return input;
}

//prints a set of instructions from an array of strings
void printSelection(int selectionArraySize, string selectionArray[]) {
  for(int i = 0; i < selectionArraySize; i++) {
    cout << i << ": " << selectionArray[i] << "\n";
  }
}

//grams of x for grams of y
void selectionZero() {
  string knownElement;
  string yesNo[] = {"Yes", "No"};
  bool gettingKnownElement = true;
  bool endLoop;
  float knownElementMolarMass = 0;
  int knownElementInput;
  int knownElementAmount;
  int isAdditionKnownElement;
  //get info on the element/s with known mass
  while (gettingKnownElement = true) {
    cout << "\nAtomic # of Element with known mass \n";
    knownElementInput;
    cin >> knownElementInput;
    knownElement += periodicSymbols[knownElementInput - 1];
    cout << "\nhow many of the element are there \n";
    knownElementAmount;
    cin >> knownElementAmount;
    knownElementMolarMass += periodicMass[knownElementInput - 1] * knownElementAmount;
    if (knownElementAmount > 1) {
      knownElement = knownElement + to_string(knownElementAmount);
    }
    cout << "\nis there an additional element with it \n";
    printSelection(2, yesNo);
    isAdditionKnownElement = getSelection();
    switch(isAdditionKnownElement) {
      case 0:
        endLoop = false;
        break;
      case 1:
        endLoop = true;
        cout << gettingKnownElement;
        break;
    }
    if (endLoop) {
      break;
    }
  }
  cout << "\nwhat is the known mass of the element/s \n";
  float fullKnownMass;
  cin >> fullKnownMass;
  cout << "Known Element/s " << knownElement << "\nKnown Element/s Molar Mass " << knownElementMolarMass << "g \nKnown Mass of element/s " << fullKnownMass << "g\n"; 

  string unknownElement;
  bool gettingUnknownElement = true;
  float unknownElementMolarMass = 0;
  int unknownElementInput;
  int unknownElementAmount;
  int isAdditionUnknownElement;

  //gets info on the element/s with unknown mass
  while (gettingUnknownElement) {
    cout << "\nAtomic # of Element with unknown mass \n";
    unknownElementInput;
    cin >> unknownElementInput;
    unknownElement += periodicSymbols[unknownElementInput - 1];
    cout << "\nhow many of the element are there \n";
    unknownElementAmount;
    cin >> unknownElementAmount;
    unknownElementMolarMass += periodicMass[unknownElementInput - 1] * unknownElementAmount;
    if (knownElementAmount > 1) {
      unknownElement = unknownElement + to_string(unknownElementAmount);
    }
    cout << "\nis there an additional element with it \n";
    printSelection(2, yesNo);
    isAdditionUnknownElement = getSelection();
    switch(isAdditionUnknownElement) {
      case 0:
        endLoop = false;
        break;
      case 1:
        endLoop = true;
        cout << gettingUnknownElement;
        break;
    }
    if (endLoop) {
      break;
    }
  }
  cout << "\nUnknown Element/s " << unknownElement << "\nUnknown Element/s Molar Mass " << unknownElementMolarMass << "g \n"; 

  float knownElementMolarRatio;
  cout << "known element ratio \n";
  cin >> knownElementMolarRatio;

  float unknownElementMolarRatio;
  cout << "\nunknown element ratio \n";
  cin >> unknownElementMolarRatio;

  float stepOne = fullKnownMass / 1;
  float stepTwo = 1 / knownElementMolarMass;
  float stepThree = unknownElementMolarRatio / knownElementMolarRatio;
  float stepFour = unknownElementMolarMass / 1;
  float unknownElementFullMass = stepOne * stepTwo * stepThree * stepFour;

  cout << "\nunknown element/s mass: " << unknownElementFullMass << "g";
  cout << "\nwork: " << "(" << fullKnownMass << " / 1) * (1 / " << knownElementMolarMass << ") * (" << unknownElementMolarRatio << " / " << knownElementMolarRatio << ") * (" << unknownElementMolarMass << " / 1)";
}

//grams of x to liters of y
void selectionOne() {
  string knownElement;
  string yesNo[] = {"Yes", "No"};
  bool gettingKnownElement = true;
  bool endLoop;
  float knownElementMolarMass = 0;
  int knownElementInput;
  int knownElementAmount;
  int isAdditionKnownElement;
  //get info on the element/s with known mass
  while (gettingKnownElement = true) {
    cout << "\nAtomic # of Element with known mass \n";
    knownElementInput;
    cin >> knownElementInput;
    knownElement += periodicSymbols[knownElementInput - 1];
    cout << "\nhow many of the element are there \n";
    knownElementAmount;
    cin >> knownElementAmount;
    knownElementMolarMass += periodicMass[knownElementInput - 1] * knownElementAmount;
    if (knownElementAmount > 1) {
      knownElement = knownElement + to_string(knownElementAmount);
    }
    cout << "\nis there an additional element with it \n";
    printSelection(2, yesNo);
    isAdditionKnownElement = getSelection();
    switch(isAdditionKnownElement) {
      case 0:
        endLoop = false;
        break;
      case 1:
        endLoop = true;
        cout << gettingKnownElement;
        break;
    }
    if (endLoop) {
      break;
    }
  }
  cout << "\nwhat is the known mass of the element/s \n";
  float fullKnownMass;
  cin >> fullKnownMass;
  cout << "Known Element/s " << knownElement << "\nKnown Element/s Molar Mass " << knownElementMolarMass << "g \nKnown Mass of element/s " << fullKnownMass << "g\n"; 

  string unknownElement;
  bool gettingUnknownElement = true;
  float unknownElementMolarMass = 0;
  int unknownElementInput;
  int unknownElementAmount;
  int isAdditionUnknownElement;

  //gets info on the element/s with unknown mass
  while (gettingUnknownElement) {
    cout << "\nAtomic # of Element with unknown mass \n";
    unknownElementInput;
    cin >> unknownElementInput;
    unknownElement += periodicSymbols[unknownElementInput - 1];
    cout << "\nhow many of the element are there \n";
    unknownElementAmount;
    cin >> unknownElementAmount;
    unknownElementMolarMass += periodicMass[unknownElementInput - 1] * unknownElementAmount;
    if (knownElementAmount > 1) {
      unknownElement = unknownElement + to_string(unknownElementAmount);
    }
    cout << "\nis there an additional element with it \n";
    printSelection(2, yesNo);
    isAdditionUnknownElement = getSelection();
    switch(isAdditionUnknownElement) {
      case 0:
        endLoop = false;
        break;
      case 1:
        endLoop = true;
        cout << gettingUnknownElement;
        break;
    }
    if (endLoop) {
      break;
    }
  }
  cout << "\nUnknown Element/s " << unknownElement << "\nUnknown Element/s Molar Mass " << unknownElementMolarMass << "g \n"; 

  float knownElementMolarRatio;
  cout << "known element ratio \n";
  cin >> knownElementMolarRatio;

  float unknownElementMolarRatio;
  cout << "\nunknown element ratio \n";
  cin >> unknownElementMolarRatio;

  float stepOne = fullKnownMass / 1;
  float stepTwo = 1 / knownElementMolarMass;
  float stepThree = unknownElementMolarRatio / knownElementMolarRatio;
  float stepFour = STP / 1;
  float unknownElementFullMass = stepOne * stepTwo * stepThree * stepFour;

  cout << "\nunknown element/s volume: " << unknownElementFullMass << "L";
  cout << "\nwork: " << "(" << fullKnownMass << " / 1) * (1 / " << knownElementMolarMass << ") * (" << unknownElementMolarRatio << " / " << knownElementMolarRatio << ") * (" << STP << " / 1)";
}

//Liters of x to grams of y
void selectionTwo() {
  string knownElement;
  string yesNo[] = {"Yes", "No"};
  bool gettingKnownElement = true;
  bool endLoop;
  float knownElementMolarMass = 0;
  int knownElementInput;
  int knownElementAmount;
  int isAdditionKnownElement;
  //get info on the element/s with known mass
  while (gettingKnownElement = true) {
    cout << "\nAtomic # of Element with known mass \n";
    knownElementInput;
    cin >> knownElementInput;
    knownElement += periodicSymbols[knownElementInput - 1];
    cout << "\nhow many of the element are there \n";
    knownElementAmount;
    cin >> knownElementAmount;
    knownElementMolarMass += periodicMass[knownElementInput - 1] * knownElementAmount;
    if (knownElementAmount > 1) {
      knownElement = knownElement + to_string(knownElementAmount);
    }
    cout << "\nis there an additional element with it \n";
    printSelection(2, yesNo);
    isAdditionKnownElement = getSelection();
    switch(isAdditionKnownElement) {
      case 0:
        endLoop = false;
        break;
      case 1:
        endLoop = true;
        cout << gettingKnownElement;
        break;
    }
    if (endLoop) {
      break;
    }
  }
  cout << "\nwhat is the known volume of the element/s \n";
  float fullKnownVol;
  cin >> fullKnownVol;
  cout << "Known Element/s " << knownElement << "\nKnown Element/s Molar Mass " << knownElementMolarMass << "g \nKnown Volume of element/s " << fullKnownVol << "L\n"; 

  string unknownElement;
  bool gettingUnknownElement = true;
  float unknownElementMolarMass = 0;
  int unknownElementInput;
  int unknownElementAmount;
  int isAdditionUnknownElement;

  //gets info on the element/s with unknown mass
  while (gettingUnknownElement) {
    cout << "\nAtomic # of Element with unknown mass \n";
    unknownElementInput;
    cin >> unknownElementInput;
    unknownElement += periodicSymbols[unknownElementInput - 1];
    cout << "\nhow many of the element are there \n";
    unknownElementAmount;
    cin >> unknownElementAmount;
    unknownElementMolarMass += periodicMass[unknownElementInput - 1] * unknownElementAmount;
    if (knownElementAmount > 1) {
      unknownElement = unknownElement + to_string(unknownElementAmount);
    }
    cout << "\nis there an additional element with it \n";
    printSelection(2, yesNo);
    isAdditionUnknownElement = getSelection();
    switch(isAdditionUnknownElement) {
      case 0:
        endLoop = false;
        break;
      case 1:
        endLoop = true;
        cout << gettingUnknownElement;
        break;
    }
    if (endLoop) {
      break;
    }
  }
  cout << "\nUnknown Element/s " << unknownElement << "\nUnknown Element/s Molar Mass " << unknownElementMolarMass << "g \n"; 

  float knownElementMolarRatio;
  cout << "known element ratio \n";
  cin >> knownElementMolarRatio;

  float unknownElementMolarRatio;
  cout << "\nunknown element ratio \n";
  cin >> unknownElementMolarRatio;

  float stepOne = fullKnownVol / 1;
  float stepTwo = 1 / STP;
  float stepThree = unknownElementMolarRatio / knownElementMolarRatio;
  float stepFour = unknownElementMolarMass / 1;
  float unknownElementFullVol = stepOne * stepTwo * stepThree * stepFour;

  cout << "\nunknown element/s volume: " << unknownElementFullVol << "L";
  cout << "\nwork: " << "(" << fullKnownVol << " / 1) * (1 / " << STP << ") * (" << unknownElementMolarRatio << " / " << knownElementMolarRatio << ") * (" << unknownElementMolarMass << " / 1)";
}

//prints out a menu to select what equations teps to use
void selectionMenu() {
  string menuSelections[] = {"grams of x for grams of y", "grams of x to liters of y", "liters of x to grams of y"};
  printSelection(3, menuSelections);
  int input = getSelection();
  switch(input) {
    case 0:
      selectionZero();
      break;
    case 1:
      selectionOne();
      break;
    case 2:
      selectionTwo();
      break;
  }
}

int main() {
  selectionMenu();
  return 0;
}
