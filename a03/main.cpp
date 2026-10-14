
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

const int MAX_SCORES = 20;

// Function prototypes
void welcome();
void readScores(double scores[], int &count);
void readDouble(string prompt, double &num);
void calcGrade(double scores[], char grades[], int count);
void printList(double scores[], char grades[], int count);
void sort(double scores[], char grades[], int count);
double median(double scores[], int count);

int main() {
    double scores[MAX_SCORES];
    char grades[MAX_SCORES];

    int count;

    welcome();

    readScores(scores, count);
    if (count == 0) {
        cout << "No scores were entered." << endl;
        return 0;
    }

    calcGrade(scores, grades, count);
    
    cout << "\nYour stats are as below:\n" << endl;
    cout << "The list of scores and their grades are:"
         << endl;

    printList(scores, grades, count);

    sort(scores, grades, count);

    cout << "\nThe list sorted by scores in ascending order:"
         << endl;

    printList(scores, grades, count);

  
    double medianScore = median(scores, count);

    cout << "\nThe median score is "
         << fixed << setprecision(2)
         << medianScore << endl;

    cout << "\nThank you for using my Parallel Arrays program!!"
         << endl; 

    return 0;
}

void welcome() {
    cout << "Welcome to my Parallel Arrays program!" << endl;
    cout << "Please enter the list of scores (-1 to end input:)" << endl;
    cout << "Valid scores are between 0 and 4 inclusive." << endl;
}

void readScores(double scores[], int &count) {
    count = 0;
    double num = 0;

    while (num != -1 && count < 20) {

        readDouble(">>", num); 

        if (num != -1) {
            scores[count] = num;
            count++;
    
        }
        if (count == 20) {
        cout << "Max scores reached!" << endl;
        }
    }
}

void readDouble(string prompt, double &num) {
  cout << prompt;
  cin >> num;

  while (!cin || num > 4.0 || (num < 0 && num != -1))
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> num;
  }
  cin.ignore(10, '\n');
}

void calcGrade(double scores[], char grades[], int count) {

    for (int i = 0; i < count; i++) {
        if (scores[i] > 3.3) {
            grades[i] = 'A'; 
        }
        else if (scores[i] > 2.7) {
            grades[i] = 'B'; 
        }
        else if (scores[i] > 1.9) {
            grades[i] = 'C';
        }
        else if (scores[i] > 1.1) {
            grades[i] = 'D';
        }
        else {
            grades[i] = 'F';
        }             

    }
}

void printList(double scores[], char grades[], int count) {
    cout << fixed << setprecision(1);
    for (int i = 0; i < count; i++) {
        cout << scores[i] << " " << grades[i] << endl;
    }
}

void sort(double scores[], char grades[], int count) {
    int min;
    for (int i = 0; i < count - 1; i++) {
        min = i;
          	for (int j = i+1; j < count; j++) {
     		if (scores[j] < scores[min])
        		min = j;
            }
        if (min != i) {
            double tempScore = scores[min];
            scores[min] = scores[i];
            scores[i] = tempScore;

            char tempGrade = grades[min];
            grades[min] = grades[i];
            grades[i] = tempGrade;
        }    

    }
}

double median(double scores[], int count) {

    double medianValue = 0.0;

    if (count % 2 != 0) { //odd
        medianValue = scores[count / 2];         
    }

    else { // even
        medianValue = (scores[(count / 2) - 1] + scores[count / 2]) / 2.0;

    }

    return medianValue;
}
