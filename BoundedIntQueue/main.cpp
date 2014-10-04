#include "BoundedIntQueue.h"
#include <iostream>


using namespace std;

int main() {
	BoundedIntQueue q;
	for (int i = 0; i < 50; i++) {
		q.enqueue(i);
	}
	cout << q.size() << endl;
	for (int i = 0; i < 50; i ++) {
		cout << q.dequeue() << endl;
	}
	cout << q.size() << endl;
}