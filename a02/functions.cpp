// Function defs
using namespace std;
#include <iostream>
#include <cctype>
#include <cstring>
#include "functions.h"

void goodbye()
{
    char goodbye[MAXPROMPT] = "Thank you for using my fileName generator!";
    print(goodbye, true, true);
}
void welcome()
{
    char prompt[MAXPROMPT] = "Welcome to my fileName encoding program!!";
    print(prompt, true, true);
}
void displayMenu()
{
    char prompt[MAXPROMPT] = "Please pick an option below:\n(e)Encode a file name\n(q)quit";
    print(prompt, true, true);
}
void readOption(char &option)
{
    char prompt[MAXPROMPT] = ">> ";
    print(prompt, false, false);
    cin >> option;

    while (option != 'e' && option != 'E' && option != 'Q' && option != 'q')
    {
        char invalidPrompt[MAXPROMPT] = "Invalid option! Please try again!!";
        print(invalidPrompt, true, true);
        displayMenu();
        char prompt[MAXPROMPT] = ">>";
        print(prompt, true, true);
        cin >> option;
    }
}
void encode(char encodeFileName[])
{
    char fName[MAXNAME];
    char lName[MAXNAME];
    bool lateFlag;
    char parsedID[5];
    char fileName[MAXNAME];
    char strTime[6];
    char timeEncoded[5];

    readInput(fName, lName, lateFlag);
    readInput(parsedID, fileName);
    readTime(strTime);

    timeEncoded[0] = strTime[0];
    timeEncoded[1] = strTime[1];
    timeEncoded[2] = strTime[3];
    timeEncoded[3] = strTime[4];
    timeEncoded[4] = '\0';

    strcat(lName, "_");
    strcat(lName, fName);
    strcpy(encodeFileName, lName);
    if (lateFlag == true)
    {
        strcat(encodeFileName, "_LATE_");
    }
    else
    {
        strcat(encodeFileName, "_");
    }
    strcat(encodeFileName, parsedID);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, timeEncoded);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, fileName);
    print(encodeFileName, true, true);
}
// Overload 1 - cstring, cstring, bool
void readInput(char fName[], char lName[], bool &lateFlag)
{

    char lNamePrompt[MAXPROMPT] = "Enter your last name: ";
    char fNamePrompt[MAXPROMPT] = "Enter your first name: ";
    char lateAssignPrompt[MAXPROMPT] = "Was your assignment Late (y/n)?: ";
    char isLate[10];
    // Last name logic
    print(lNamePrompt, false, false);
    cin >> lName;
    while (!validName(lName))
    {
        print(lNamePrompt, false, false);
        cin >> lName;
    }
    convertLower(lName);

    // First name logic
    print(fNamePrompt, false, false);
    cin >> fName;
    while (!validName(fName))
    {
        print(fNamePrompt, false, false);
        cin >> fName;
    }
    convertLower(fName);
    // check if late
    print(lateAssignPrompt, false, false);
    cin >> isLate;
    convertLower(isLate);

    while (strcmp(isLate, "y") != 0 && strcmp(isLate, "n") != 0)
    {
        invalidInput();
        cin >> isLate;
        convertLower(isLate);
    }

    if (strcmp(isLate, "y") == 0)
    {
        lateFlag = true;
    }
    else
    {
        lateFlag = false;
    }
}
// overload 2: cstring, cstring
void readInput(char parsedID[], char fileName[])
{
    char stdID[12];
    char studentIDprompt[MAXPROMPT] = "Enter your Student-ID (format: 222-22-2222): ";
    char fileNamePrompt[MAXPROMPT] = "Enter the file name: ";
    // student ID logic
    print(studentIDprompt, false, false);
    cin >> stdID;
    while (!validID(stdID))
    {
        invalidInput();
        print(studentIDprompt, false, false);
        cin >> stdID;
    }
    strncpy(parsedID, stdID + 7, 4);
    parsedID[4] = '\0';

    // fileName logic
    print(fileNamePrompt, false, false);
    cin >> fileName;
}
void readTime(char strTime[])
{
    char timePrompt[MAXPROMPT] = "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
    print(timePrompt, false, false);
    cin >> strTime;
}
void invalidInput()
{
    char prompt[MAXPROMPT] = "Invalid option! Please try again!!: ";
    print(prompt, false, false);
}
bool validID(char stdID[])
{

    if (strlen(stdID) != 11 ||
        !isdigit(stdID[0]) ||
        !isdigit(stdID[1]) ||
        !isdigit(stdID[2]) ||
        stdID[3] != '-' ||
        !isdigit(stdID[4]) ||
        !isdigit(stdID[5]) ||
        stdID[6] != '-' ||
        !isdigit(stdID[7]) ||
        !isdigit(stdID[8]) ||
        !isdigit(stdID[9]) ||
        !isdigit(stdID[10]))
    {
        return false;
    }
    return true;
}
bool validName(char name[])
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha(static_cast<unsigned char>(name[i])))
        {
            return false;
        }
    }

    return true;
}
void convertLower(char input[])
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        input[i] = tolower(static_cast<unsigned char>(input[i]));
    }
}
void print(char text[101], bool endLine, bool startLine)
{
    if (startLine)
    {
        cout << endl;
    }
    if (endLine)
    {
        cout << text << endl;
    }
    else
    {
        cout << text;
    }
}