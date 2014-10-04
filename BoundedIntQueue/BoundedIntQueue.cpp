#include "BoundedIntQueue.h"
#include "EmptyQueueException.h"
#include <cstddef>
#include <iostream>

BoundedIntQueue::BoundedIntQueue() {
	ourSize = 0;
	internalStorage = new int[10];
	front = back = 0;
	capacity = 10;
}

BoundedIntQueue::BoundedIntQueue(int bounds) {
	ourSize = 0;
	internalStorage = new int[bounds];
	front = back = 0;
	capacity = bounds;
}

BoundedIntQueue::~BoundedIntQueue() {
	delete [] internalStorage;
}

int BoundedIntQueue::size() const {
	return ourSize;
}

void BoundedIntQueue::enqueue(int item) {
	if (back > front) {
		if (back == capacity) {
			increaseSize();
		}
		internalStorage[back] = item;
	} else if (back < front) {
		if(back - front > 1) {
			internalStorage[back] = item;
		} else {
			increaseSize();
			internalStorage[back] = item;
		}
	} else {
		internalStorage[back] = item;
	}
	back++;
	ourSize++;
}

int BoundedIntQueue::dequeue() {
	if (ourSize > 0) {
		if (front < capacity) {
			front++;
			ourSize--;
			return internalStorage[front - 1];
		} else {
			front = 0;
			ourSize--;
			return internalStorage[capacity - 1];
		}
	} else {
		throw EmptyQueueException();
	}
}

void BoundedIntQueue::increaseSize() {
	int * temp = new int[capacity * SCALE_FACTOR];
	int counter = 0;
	for (int i = front; i < ourSize; i++) {
		temp[counter] = internalStorage[i];
		counter++;
	}
	if (back < front) {
		for (int i = back; i >= 0; i--) {
			temp[counter] = internalStorage[i];
			counter++;
		}
	}
	back = counter;
	front = 0;
	delete [] internalStorage;
	internalStorage = temp;
	temp = nullptr;
	capacity *= 3;
}

