## Issue 1
Time Complexity by Coding ninjas O( n*logn)
But according to me ( n^2 * long)

``` cpp
 

#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    // Queue to maintain the order of people
    queue<int> peopleQueue;

    // Max-heap to get the highest priority element
    priority_queue<int> maxHeap;

    // Push all people and their priorities into the queues
    for (int i = 0; i < n; i++) {
        peopleQueue.push(arr[i]);
        maxHeap.push(arr[i]);
    }

    // Counter to keep track of the number of tickets bought
    int count = 0;

    // Process the queues
    int ch=0;
    while (!maxHeap.empty()) {
        ch++;
        // Check if the person at the front of the queue has the highest priority
        if (peopleQueue.front() == maxHeap.top()) {
            // Check if this person is the one we are interested in
            if (k == 0) {
                cout<<ch<<endl;
                return count + 1;  // Return the number of tickets bought plus one
            } else {
                // This person buys a ticket
                count++;
                peopleQueue.pop();
                maxHeap.pop();
                k--;
            }
        } else {
            // Move the person at the front to the end of the queue
            peopleQueue.push(peopleQueue.front());
            peopleQueue.pop();
            // Adjust the index k to maintain the original position of the person of interest
            if (k == 0) {
                k = peopleQueue.size() - 1;
            } else {
                k--;
            }
        }
    }
    // cout<<ch<<endl;

    // Return the total count of tickets bought
    return count;
}
```
