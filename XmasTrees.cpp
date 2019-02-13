#include <iostream>
#include <string>
#include <cstdlib> //Used for random
#include <windows.h> //used for playing audio & colors
#pragma comment(lib, "winmm.lib") //used for playing audio

using namespace std;

char const BLANK = ' '; //constant: symbol used for drawing the space around the tree
char const LEAF = '#';  //constant: symbol used for drawing the tree’ leaves’
char const WOOD = '|';  //constant: symbol used for drawing the tree’s trunk
char const DECOR = '.';  //constant: symbol used for drawing the outside decoration
int const MINSIZE = 4;  //constant: symbol used for checking min tree height
int const MAXSIZE = 20; //constant: symbol used for checking max tree height
int treeHeight;         //height of the tree
int branchLine;         //line of branch being drawn
int leafNum, rownumber, spaces, leaves, trunkLine;  //various needed variables
string moreInput;
bool validHeight;       //holds return value of the procedure
bool more = true;       //holds value if more trees wanted

//procedure delcorations
void getValidHeight();
void christmasGreeting();
void drawAXmasTree();
void drawFoliage(int treeHeight, int branchLine);
void drawALineOfFoliage(int treeHeight, int branchLine);
void drawTrunk();
char randomDecoration();
void agreeToContinue(string moreInput);


int main()
{
  cout << "Lewis Teather - December 2017" << endl << endl;

  PlaySound(TEXT("Xmas.wav"), NULL, SND_FILENAME); //Plays christmas music while program runs

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 166);
  drawAXmasTree();
  
  system("pause");
  return 0;
}

void agreeToContinue(string moreInput) {
  if (moreInput == "Y" || moreInput == "y") {
    drawAXmasTree();
  }
  else {
    return;
  }

  return;
}

char randomDecoration() {
    int Min = 0;
    int Max = 3;

    //calculates a random number between min and max values
    int randomNumber = rand() % (Max + 1 - Min) + Min;

    //takes random number and outputs depending on the result
    switch(randomNumber) {
        case '0' :
            return '*';
            break;
        case '1' :
            return '&';
            break;
        case '2' :
            return '@';
            break;     
        case '3' :
            return '0';
            break;             
        default :
            return '*';
            break;      
    }
}

void getValidHeight() {
  validHeight = false;
  treeHeight = 0;
  while (validHeight == false) {
    cout << "Enter the size of the tree (4-20):";
    cin >> treeHeight;
    
    //check if entered height is between 4 and 20
    if(treeHeight >= 4 && treeHeight <= 20) {
      validHeight = true;
    }
    else {
      cout << "ERROR: Invalid height!" << endl;
      validHeight =  false;
    }
  }
}

void drawFoliage(int treeHeight, int branchLine) {
  branchLine = 1;
  
  //loop to draw top border
  for(int i = 0; i <= (treeHeight * 2); i++) {
    cout << DECOR;
  }
 
  cout << endl;

  //draw foliage while the row is less than the height
  do {
    drawALineOfFoliage(treeHeight, branchLine);
    branchLine++;  
  }
  
  while(branchLine <= treeHeight - 2); 
}

void drawALineOfFoliage(int treeHeight, int branchLine) {
  //output the left border
  cout << DECOR;

  //places the spaces before the leaves to create triangle shape
  for (spaces = treeHeight - branchLine; spaces >= 1; spaces--) {
    cout << BLANK; 
  }

  //for loop to place number of leaves needed for the line
  for (leaves = 1; leaves <= (branchLine * 2) - 1; leaves++) {
    //if first line output random decoration
    if (branchLine == 1) {
      cout << randomDecoration();
    }
    else {
      cout << LEAF; 
    }
  }    

  //secondry for loop to place spaces for right border
  for (spaces = treeHeight - branchLine; spaces >= 1; spaces--) {
    cout << BLANK; 
  }    

  //output the boarder and start a new line
  cout << DECOR << endl;

  return;
}


void drawTrunk(int treeHeight) {
  do {
    
    //output the left border
    cout << DECOR;

    //loop to place spaces for left border
    for (spaces = treeHeight - 1; spaces >= 1; spaces--) {
      cout << BLANK;
    }

    cout << WOOD;

    //secondry for loop to place spaces for right border
    for (spaces = treeHeight - 1; spaces >= 1; spaces--) {
      cout << BLANK;
    }

    //output the boarder and start a new line
    cout << DECOR << endl;          

    trunkLine++;    
  }
  
  while (trunkLine < 2); //for each line in the truck

  //loop to draw bottom border
  for(int i = 0; i <= (treeHeight * 2); i++) {
    cout << DECOR;
  }    
}

void drawAXmasTree() {
  getValidHeight();
  drawFoliage(treeHeight, branchLine);
  drawTrunk(treeHeight);

  cout << endl;

  treeHeight = 0;
  cout << "Would you like another tree? (Y/N): ";
  cin >> moreInput;
  agreeToContinue(moreInput);
  return;
}