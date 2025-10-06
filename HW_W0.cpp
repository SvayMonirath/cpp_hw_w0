#include <iostream>
using namespace std;

#define SIZE 10
#define STARTING_AMOUNT 5

// TODO[X]: Insert and Delete elements from an array handling shifting elements to the left or right base on insert/delete

// FUNCTION PROTOTYPES
void printArray(int *arr, int *next_slot);
void insertValue(int *arr, int pos, int val, int *next_slot);
void deleteValue(int *arr, int pos, int *next_slot);

int main(void) {

    int arr[SIZE];
    for(int i=0; i<SIZE - STARTING_AMOUNT; i++) arr[i] = i+1;

    int next_slot = SIZE-STARTING_AMOUNT;

    cout<<"Original Value: "<<endl;
    printArray(arr, &next_slot);

    // Insert at next pos
    insertValue(arr, next_slot, 99, &next_slot);
    printArray(arr, &next_slot);

    // Insert in between
    insertValue(arr, 2, 55, &next_slot);
    printArray(arr, &next_slot);

    // Insert next_slot ahead
    insertValue(arr, 8, 77, &next_slot);
    printArray(arr, &next_slot);

    // 1 2 55 3 4 5 99 0 77  *VALUE AFTER ALL INSERT PERFORM
    deleteValue(arr, next_slot-1, &next_slot);
    printArray(arr, &next_slot);

    deleteValue(arr, 4, &next_slot);
    printArray(arr, &next_slot);

    deleteValue(arr, SIZE, &next_slot);
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

void insertValue(int *arr, int pos, int val, int *next_slot) {
    if(pos < 0 || pos >= SIZE) return; // invalid position

    // insert at the next slot
    if(pos == *next_slot) {
        arr[pos] = val;
        (*next_slot)++;
        return;
    }

    // insert past the next slot
    if(pos > *next_slot) {
        for(int i=*next_slot; i<pos; i++) arr[i] = 0;
        arr[pos] = val;
        *next_slot = pos + 1;
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

void deleteValue(int *arr, int pos, int *next_slot) {
    if (pos < 0 || pos >= *next_slot) return; // invalid position

    // Shift all elements left
    for (int i = pos; i < *next_slot - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*next_slot)--;
}
