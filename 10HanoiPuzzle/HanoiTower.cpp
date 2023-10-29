#include <iostream>
#include <cmath>
using namespace std;

void moveDisk(int disk, char source, char destination) {
    cout << "Move disk " << disk << " from peg " << source << " to peg " << destination << endl;
}

void towerOfHanoi(int numDisks, char source, char auxiliary, char destination) {
    if (numDisks == 1) {
        moveDisk(numDisks, source, destination);
        return;
    }

    towerOfHanoi(numDisks - 1, source, destination, auxiliary);
    moveDisk(numDisks, source, destination);
    towerOfHanoi(numDisks - 1, auxiliary, source, destination);
}

int main() {
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    // Calculate total moves
    int totalMoves = pow(2, numDisks) - 1;

    cout << "Steps to solve the Tower of Hanoi with " << numDisks << " disks:" << endl;
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    cout << "Total moves required: " << totalMoves << endl;

    return 0;
}