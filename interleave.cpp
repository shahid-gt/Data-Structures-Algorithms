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
#include <stack>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    for(int i = 1; i <= 10; i++) {
        q.push(i);
    }
    int size = q.size();
    stack<int> s;
    for (int i = 0; i < size; i++) {
        s.push(q.front());
        q.pop();
    }
    for (int i = 0; i < size; i++) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < size; i++) {
        s.push(q.front());
        q.pop();
    }
    for (int i = 0; i < size/2; i++) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < size/2; i++) {
        q.push(q.front());
        q.pop();
        q.push(s.top());
        s.pop();
    }
    for(int i = 0; i < 10; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
