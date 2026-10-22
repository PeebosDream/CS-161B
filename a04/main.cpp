#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

const int MAXCHAR = 52;
const int MAXCOURSE = 20;
const int MAXSTUDENTS = 25;

//function prototypes
void welcome();
void readInt(string prompt, int &num);
void readInput(char courseNums[][MAXCHAR], int students[], int &count);
void printList(char courseNums[][MAXCHAR], int students[], int count);
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count);

int main() {

    char courseNums[MAXCOURSE][MAXCHAR];
    int students[MAXCOURSE];
    int count = 0;

    welcome();
    readInput(courseNums,students,count);
    cout << "\nList of courses and students:" << endl;
    printList(courseNums, students, count);
    cancelCourses(courseNums,students,count);
    cout << "\nList after cancellations:" << endl;
    printList(courseNums,students,count);
    cout << "\nThank you for checking out my Course Rosters program!" << endl;

return 0;
}

void welcome() {

    cout << "Welcome to my Course Rosters program!!" << endl;
        cout << "Enter course number and students enrolled when prompted. "
    "Enter Quit or quit for course number when you are done." << endl;    
}


void readInput(char courseNums[][MAXCHAR], int students[], int &count) {

    char tempCourse[MAXCHAR];
    int tempStudents;

    cout << "Enter course number: ";
    cin.getline(tempCourse, MAXCHAR); //initial read

    while (strcmp(tempCourse, "quit") != 0 && strcmp(tempCourse, "Quit") != 0 && count < MAXCOURSE) {

        readInt("Number of students enrolled: ", tempStudents);

       while (tempStudents < 0 || tempStudents > 25) {

        cout << "Invalid number!! Please enter a number between 0 and 25" << endl; 
        cin.clear();
        cin.ignore(100, '\n');
        readInt("Number of students enrolled: ", tempStudents);
       }

       int i = 0;

       while (i < count && strcmp(tempCourse, courseNums[i]) > 0 ) {
            i++; // i is incrementing to show the correct insertion spot. this increments only if
                // the course number is greater than the last position
       }

       // Shift right
       for (int j = count; j > i; j--) { 
            strcpy(courseNums[j], courseNums[j-1]);
            students[j] = students[j-1];
       }

       // insert
        strcpy(courseNums[i], tempCourse);
        students[i] = tempStudents;
        // increment count to keep track of working size of array
        count++;

        if (count < MAXCOURSE) {
            cout << "Enter course number: ";
            cin.getline(tempCourse, MAXCHAR);
        }

    }
}

void readInt(string prompt, int &num) {
  cout << prompt;
  cin >> num;

  while (!cin)
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> num;
  }
  cin.ignore(10, '\n');
}

void printList(char courseNums[][MAXCHAR], int students[], int count) {

    for (int i = 0; i < count; i++) {
        cout << left << setw(20) << courseNums[i]
        << students[i] << endl;
    }

}

void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count) {

    for(int i = 0; i < count; i++) {

        if (students[i] < 10) {
            int removeIndex = i; // students[i] is the spot that needs to be shifted left out of the array

            /*start at the spot that needs to get booted out, You stop at count - 1 because 
            you're accessing j + 1, and you don't want to read beyond the last active element. (count is working size)*/
            for (int j = removeIndex; j < count - 1; j++) {   
                students[j] = students[j+1];                
                strcpy(courseNums[j], courseNums[j+1]);          
            }
            // deincrement count so that it correctly matches the size of the array
            // deincremnt i so that when it goes back into the outer for loop it is on the correct element. 
        count--;
        i--;    
        }
    }

}
