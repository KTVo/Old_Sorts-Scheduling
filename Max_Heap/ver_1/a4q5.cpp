/*
 * Name: Kevin Vo
 * Student ID: 006316930
 * Professor: Dr. Yan Zhang
 * Assignment: Assignment#4 - Problem 5: Max Heap
 * Course: CSE-330
 * Date: June 4, 2019
 * Purpose: This program demonstrates Max Heaps by taking in a sequence of values
 *          then calling the max heap and deleting it after until heap is empty.
*/

#include <cstdlib>
#include "MaxHeap.h"

using namespace std;


int main() 
{

    MaxHeap<int> maxheap;   //Declaration to create a max heap
    int size,   //hold number of elements allowed for max heap
        input;  //stores inputs for integer elements 
    
    //Prompts user for the size of the heap tree
    cout<<"\nEnter SIZE for insertion: ";
    cin>>size;
    
    //Prompts user to enter a sequence of integer elements
    cout<<"\nEnter a sequence of integers:\n";
    for(int i = 0; i < size; i++){
        cin>>input;
        maxheap.insert(input);
    }
    
    cout<<endl;
    
    //Prints entire heap until heap is empty
    cout<<"\nNow repeatedly print the maximal element repeatedly maxheap is empty\n.";
    cout<<endl<<"Results for part 5.b.3:\n";
    while(!maxheap.isEmpty())
    {
        cout<<"Max Heap: "<<maxheap.findMax()<<endl;
        maxheap.deleteMax();
    
    }
    
    cout<<endl<<endl;
    return 0;
}

