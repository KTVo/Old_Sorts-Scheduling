// a4q5.cpp

#include "MaxHeap.h"
#include <iostream>
using namespace std;


//6 3 9 1 8 4 6 4 1
int main()
{
    MaxHeap<int> maxheap;
    int n, i, num;
    //cout << "Enter size: ";
    //cin >> n;
    n = 9;
    cout << "Enter the numbers\n";
    
    for(i = 0; i < n; i++)
    {
        cin >> num;
        maxheap.insert(num);

        // can be commented out it output is to be required at every step
        /*
        cout << "Heap:\n";
        maxheap.print();
        */
    }

    while(!maxheap.isEmpty())
    {
        cout << maxheap.findMax() << " ";
        maxheap.deleteMax();

        // can be commented out it output is to be required at every step
        /*
        cout << "Heap:\n";
        maxheap.print();
        */
    }
}

