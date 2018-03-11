/*
General practice with recursive functions.
Takes an array of integers, uses the size
as the end bound of the array, then sorts
by ascending order.
*/

#include <iostream>

using namespace std;

/*
void sortIntegers(int x[], int startBound, int endBound);
pre: takes an array of ints, and two int bounds.
post: sorts the array by ascending order between the bounds.

int indexOfSmallest(int x[], int startingIndex, int size);
pre: takes an array of ints, the starting int, and the size (or end bound)
post: returns the index of the smallest number in the array.
*/
void sortIntegers(int x[], int startBound, int endBound);

int indexOfSmallest(const int x[], int startingIndex, int size);

int main() {
    int x[] = {20, 5, 60, 2, 1, 10, 13};
    int size = 6;

    cout << "Given:\n";
    for (int i = 0; i <= size; i++) {
        cout << "x[" << i << "] == " << x[i] << endl;
    }

    cout << "\nSorted:\n";

    sortIntegers(x, 0, size);

    for (int i = 0; i <= size; i++) {
        cout << "x[" << i << "] == " << x[i] << endl;
    }

    cout << endl;
}


/*
Takes an array of integers, and two bounds: a start and end.
Uses a recursive loop, and the indexOfSmallest function, to
find the index of the smallest number, and make it the first
in the array. Stops once start is greater than end.
*/
void sortIntegers(int x[], int startBound, int endBound) {
    if (startBound > endBound) {
        return;
    } else {
        swap(x[indexOfSmallest(x, startBound, endBound)], x[startBound]);
        sortIntegers(x, startBound + 1, endBound);
    }
}


/*
Takes an array of integers, a starting point, and the size (or end bound).
Compares each member of the array to the starting value until the smallest
is found, and returns the index to that smallest number.
*/
int indexOfSmallest(const int x[], int startingIndex, int size) {
    int targetIndex = startingIndex;

    for (int count = startingIndex + 1; count <= size; count++) {
        if (x[count] < x[targetIndex]) {
            targetIndex = count;
        }
    }
    return targetIndex;
}






/*
OUTPUT:

Given:
x[0] == 20
x[1] == 5
x[2] == 60
x[3] == 2
x[4] == 1
x[5] == 10
x[6] == 13

Sorted:
x[0] == 1
x[1] == 2
x[2] == 5
x[3] == 10
x[4] == 13
x[5] == 20
x[6] == 60

Process finished with exit code 0
*/