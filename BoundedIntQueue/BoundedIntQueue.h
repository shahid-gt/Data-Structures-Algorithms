#ifndef BOUNDED_INT_QUEUE
#define BOUNDED_INT_QUEUE

#define SCALE_FACTOR 3
class BoundedIntQueue
{
 	public:
		BoundedIntQueue (); // Default Constructor, with size of 10

    	BoundedIntQueue (int bounds);  // Constructor to set Queue size

    	~BoundedIntQueue (); // destructor

		int size () const; // returns the number of elements in the set

		void enqueue (int item); 
 		 /* Adds the item to the queue.*/

		int dequeue();
		/* Removes the item from the queue.*/

	private:
		int capacity;
		int * internalStorage;
		int front;
		int back;
		int ourSize;
		void increaseSize();
};
#endif
