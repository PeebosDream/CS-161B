#ifndef FUNCTIONS_H
#define FUNCTIONS_H

const int MAXPROMPT = 101;
const int MAXNAME = 21;

void print(char text[MAXPROMPT], bool endLine, bool startLine);
void welcome();
void displayMenu();
void readOption(char &option);
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag); //  overloaded function
void readInput(char parsedID[], char fileName[]);           // overloaded function
void readTime(char strTime[]);
void convertLower(char input[]);
bool validName(char name[]);
void invalidInput();
bool validID(char stdID[]);
void goodbye();

#endif
