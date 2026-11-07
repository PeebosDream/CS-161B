
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_ROWS = 30;
const int MAX_NAME = 100;

bool loadData(char occupations[][MAX_NAME],
              double sleepData[][3],
              int &size);
void printData(const char occupations[][MAX_NAME],
               const double sleepData[][3],
               int size);
void comparisonAnalysis(const char occupations[][MAX_NAME],
                        const double sleepData[][3],
                        int size);
void summationAnalysis(const double sleepData[][3], int size);

int main()
{

    char occupations[MAX_ROWS][MAX_NAME];
    double sleepData[MAX_ROWS][3];
    int size = 0;

    cout << "Welcome to the Sleep Data Analysis Program!"
         << endl;

    bool success = loadData(occupations, sleepData, size);

    if (success)
    {
        cout << "Records loaded: " << size << endl;
        printData(occupations, sleepData, size);
        comparisonAnalysis(occupations, sleepData, size);
        summationAnalysis(sleepData, size);
    }

    else
    {
        cout << "Error loading data." << endl;
    }

    cout << "Goodbye!" << endl;

    return 0;
}

bool loadData(char occupations[][MAX_NAME],
              double sleepData[][3],
              int &size)
{

    ifstream inFS;
    inFS.open("sleep_data.txt");

    if (!inFS.is_open())
    {
        return false;
    }

    bool valid = true;
    char separator;

    while (size < MAX_ROWS && valid &&
           inFS.getline(occupations[size],
                        MAX_NAME, ';'))
    {

        if (!(inFS >> sleepData[size][0]))
        {
            valid = false;
        }

        if (valid)
        {
            if (!inFS.get(separator) ||
                separator != ';')
            {
                valid = false;
            }
        }

        if (valid)
        {
            if (!(inFS >> sleepData[size][1]))
            {
                valid = false;
            }
        }

        if (valid)
        {
            if (!inFS.get(separator) ||
                separator != ';')
            {
                valid = false;
            }
        }

        if (valid)
        {
            if (!(inFS >> sleepData[size][2]))
            {
                valid = false;
            }
        }

        if (valid)
        {
            int next = inFS.peek();

            if (next == '\r')
            {
                inFS.get();
                next = inFS.peek();
            }

            if (next == '\n')
            {
                inFS.get();
            }
            else if (next != EOF)
            {
                valid = false;
            }
        }

        if (valid)
        {
            size++;
        }
    }

    inFS.close();

    return valid && size > 0;
}

void printData(const char occupations[][MAX_NAME],
               const double sleepData[][3],
               int size)
{

    cout << endl;
    cout << "Sleep Health and Lifestyle Data" << endl;

    cout << left << setw(25) << "Occupation"
         << right << setw(15) << "Sleep Duration"
         << setw(15) << "Sleep Quality"
         << setw(18) << "Physical Activity"
         << endl;

    cout << setfill('-') << setw(73) << ""
         << setfill(' ') << endl;

    for (int i = 0; i < size; i++)
    {

        cout << left << setw(25) << occupations[i]
             << right << setw(15) << fixed
             << setprecision(1) << sleepData[i][0]
             << setw(15) << setprecision(0)
             << sleepData[i][1]
             << setw(18) << sleepData[i][2]
             << endl;
    }
}

void comparisonAnalysis(const char occupations[][MAX_NAME],
                        const double sleepData[][3],
                        int size)
{

    int highestIndex = 0;
    int lowestIndex = 0;

    for (int i = 1; i < size; i++)
    {

        if (sleepData[i][0] > sleepData[highestIndex][0])
        {
            highestIndex = i;
        }

        if (sleepData[i][0] < sleepData[lowestIndex][0])
        {
            lowestIndex = i;
        }
    }

    cout << endl;
    cout << "Sleep Duration Analysis" << endl;
    cout << fixed << setprecision(1);
    cout << "Highest sleep duration: "
         << occupations[highestIndex] << " ("
         << sleepData[highestIndex][0] << " hours)"
         << endl;

    cout << "Lowest sleep duration: "
         << occupations[lowestIndex] << " ("
         << sleepData[lowestIndex][0] << " hours)"
         << endl;
}

void summationAnalysis(const double sleepData[][3],
                       int size)
{

    double totalSleep = 0;
    double totalQuality = 0;

    for (int i = 0; i < size; i++)
    {
        totalSleep += sleepData[i][0];
        totalQuality += sleepData[i][1];
    }

    double averageSleep = totalSleep / size;
    double averageQuality = totalQuality / size;

    cout << endl;
    cout << "Sleep Averages" << endl;

    cout << fixed << setprecision(2);

    cout << "Average sleep duration: "
         << averageSleep << " hours" << endl;

    cout << "Average sleep quality: "
         << averageQuality << " / 10" << endl;
}
