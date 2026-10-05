#include <iostream>
#include <cctype>
#include <cstring>
#include "functions.h"

using namespace std;

int main()
{
    char userOption;
    char encryptedFileName[MAXPROMPT];
    welcome();

    do
    {
        displayMenu();
        readOption(userOption);

        if (userOption == 'e' || userOption == 'E')
        {
            encode(encryptedFileName);
        }

    } while (userOption != 'q' && userOption != 'Q');

    goodbye();
    return 0;
}
