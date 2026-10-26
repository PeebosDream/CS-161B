#include <iostream>

using namespace std;

int enqueue(int queue[], int &size, int val);
int dequeue(int queue[], int &size, int &val);
void printQueue(int queue[], int size);
void welcome();
void getOption(char &option);
void readInteger(int &val);

const int MAX = 3; // maximum size of queue

int main() {
    int queue[MAX]; // integer array for queue
    int size = 0;   // contains number of elements in queue
    char option;
    int val;
    int resultDQ;
    int resultEQ;

    welcome();

    do {

    getOption(option);

    switch(option) {

        case '+': 
    
        readInteger(val);
        resultEQ = enqueue(queue, size, val);

        switch(resultEQ) {
            case 0: 
            printQueue(queue,size);
            break;

            case 1: 
            cout << "Error: Queue Overflow!" << endl;
            printQueue(queue,size);
            break;
        }

        break;

        case '-':

        readInteger(val);
        resultDQ = dequeue(queue, size, val);

        switch(resultDQ) {
            case 0: 
            printQueue(queue,size);
            break;

            case 1: 
            cout << "Queue Empty." << endl;
            printQueue(queue,size);
            break;

            case 2: 
            cout << val << " is not in the queue." << endl;
            printQueue(queue,size);
            break;

        }

        break;
        
        case 'p': 
        case 'P':
        printQueue(queue,size);
        break;

        case 'q':
        case 'Q':
        cout << "\nGoodbye!" << endl;
        break;

        default:
        cout << "Invalid option." << endl;
    }        

    } while (option != 'q' && option != 'Q');

    return 0;
}

void welcome() {
    cout << "Welcome to the FIFO Queue Program!" << endl;
}

void getOption(char &option) {
    cout << "\nEnter option: ";
    cin >> option; 
}

void readInteger(int &val) {
    cout << "Integer: ";
    cin >> val; 

    while (!cin) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Integer: ";
        cin >> val;

    } 
}

int enqueue(int queue[], int &size, int val){

    if (size == MAX) {
        return 1;
    }
    else {
        queue[size] = val;
        size++;
        return 0; 
    }

}

int dequeue(int queue[], int &size, int &val){

    if (size == 0) {
    return 1;
    }

    for (int i = 0; i < size; i++) { 

        if (queue[i] == val) {

            for(int j = 0; j < size - (i+1); j++ ) { 
                queue[j] = queue[j+i+1];
            } 
            size = size - (i+1);
            return 0; 
        }   
    }

    return 2;
}

// Call this function to print the queue
void printQueue(int queue[], int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << queue[i];
        
        if (i != size - 1)
            cout << ", " ;
    }
    cout << "]" << endl;
}

