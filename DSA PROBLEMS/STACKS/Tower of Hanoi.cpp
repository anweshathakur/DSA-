/*
--- EDITORIAL ---
Intuition:
Move n disks from source rod to destination rod using an auxiliary rod.

Approach (Recursive):
1. Move n-1 disks from source to auxiliary using destination.
2. Move the n-th (largest) disk from source to destination.
3. Move n-1 disks from auxiliary to destination using source.

Complexity:
- Time: O(2^n)
- Space: O(n) for recursion depth
-----------------
*/
//--------------------TOWER OF HANOI-----------------------
//PROBLEM STATEMENT:

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case: If there is only one disk, move it directly from source to destination
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }   
    
    // Step 1: Move n-1 disks from source to auxiliary, using destination as auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);
    // Step 2: Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    // Step 3: Move the n-1 disks from auxiliary to destination, using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    
    // Call the function to solve Tower of Hanoi
    towerOfHanoi(n, 'A', 'B', 'C');
    
    return 0;
}