#include <iostream>
using namespace std;

#define SIZE 10
#define STARTING_AMOUNT 5

// TODO[X]: Insert and Delete elements from an array handling shifting elements to the left or right base on insert/delete

// FUNCTION PROTOTYPES
void printArray(int *arr, int *next_slot);
void insertValue(int *arr, int *next_slot);
void deleteValue(int *arr, int *next_slot);

int main(void) {

    int arr[SIZE];
    for(int i=0; i<SIZE - STARTING_AMOUNT; i++) arr[i] = i+1;

    int next_slot = SIZE-STARTING_AMOUNT;

    cout<<"Original Value: "<<endl;
    printArray(arr, &next_slot);

    insertValue(arr, &next_slot);
    printArray(arr, &next_slot);

    deleteValue(arr, &next_slot);
    printArray(arr, &next_slot);

    return 0; //code success
}

// FUNCTION DEFINITIONS
void printArray(int *arr, int *next_slot) {
    for(int i=0; i<(*next_slot); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertValue(int *arr, int *next_slot) {
    if (*next_slot == SIZE) {
        cout << "Array is full" << endl;
        return;
    }

    cout << "\n\nInserting Value" << endl;
    int pos, val;
    cout << "Enter value: ";
    cin >> val;

    do {
        cout << "Enter position: ";
        cin >> pos;
        if (pos < 0 || pos > SIZE) cout << "Position out of bound" << endl;
    } while(pos < 0 || pos > SIZE || pos > *next_slot);

    // insert at the next slot
    if(pos == *next_slot) {
        arr[pos] = val;
        (*next_slot)++;
        return;
    }

    // shift all elements right
    for(int i=*next_slot; i>pos; i--) {
        if(i >= SIZE) continue; // ignore exceeding position
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    (*next_slot)++;
}

void deleteValue(int *arr, int *next_slot) {
    if (*next_slot == 0) {
        cout << "Array is empty" << endl;
        return;
    }

    cout << "\n\nDeleting Value" << endl;
    int pos;
    do {
        cout << "Enter position: ";
        cin >> pos;
        if (pos < 0 || pos > SIZE) cout << "Position out of bound" << endl;
    } while(pos < 0 || pos > SIZE || pos >= *next_slot);

    // Shift all elements left
    for (int i = pos; i < *next_slot - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*next_slot)--;
}
