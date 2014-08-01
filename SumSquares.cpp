/*
 * SumSquares.cpp
 *
 * purpose: To find the total sum of the squares of the numbers from 1 to n
 *          n is a user-inputted number
 *
 *
 * @author Arush Shankar
 * @version 1.0 8/01/14
 */

#include <iostream>

using namespace std;

int sumSquares(int num);

int main() {
    cout << "Please input a number to sum the squares from 1 to that number " << endl;
    int num;
    cin >> num;
    cout << "Sum is " << sumSquares(num) << endl;
}

int sumSquares(int num) {
    if (num == 0) {
        return 0;
    } else {
        return num * num + sumSquares(num-1);
    }
}
