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

// MaxHeap.h
#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;

// BinaryHeap class
//
// CONSTRUCTION: with an optional capacity (that defaults to 100)
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// deleteMin( minItem )   --> Remove (and optionally return) smallest item
// C findMin( )           --> Return smallest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items

template <typename C>
class MaxHeap
{
  public:
    MaxHeap( int capacity = 100 ) : items( capacity + 1 ), currentSize{ 0 }
    {   }

    bool isEmpty( ) const
    {
    	return currentSize == 0; 
    }

    void printJobs()
    {
        for(int i = 1; i <= currentSize; i++)
            cout<<items[i]<<" ";
	
    
    }

    /**
     * Find the largest item in the priority queue.
     * Return the largest item
     */
    const C & findMax( ) const
    {
        assert(!isEmpty());
        return items[ 1 ];
    }
    
    /**
     * Insert item x, allowing duplicates.
     */
    void insert( const C & x )
    {
        if( currentSize == items.size( ) - 1 )
            items.resize( items.size( ) * 2 );

        // Percolate up
        int hole = ++currentSize;
        C copy = x;
        
        items[ 0 ] = copy;
        for( ; x > items[ hole / 2 ]; hole /= 2 )
            items[ hole ] = items[ hole / 2 ];
        items[ hole ] = items[ 0 ];
    }
    
    /**
     * Remove the maximum item.
     */
    void deleteMax( )
    {
        assert(!isEmpty());
        
        items[ 1 ] = items[ currentSize ];
        currentSize = currentSize - 1;
        percolateDown( 1 );
    }

    /**
     * Remove the maximum item and place it in maxItem.
     */
    void deleteMax( C & maxItem )
    {
        assert(!isEmpty());

        maxItem = items[ 1 ];
        items[ 1 ] = items[ currentSize ];
        currentSize = currentSize - 1;
        percolateDown( 1 );
    }

    void makeEmpty( )
    {
        currentSize = 0;
    }
		
  private:
    int currentSize;  // Number of elements in heap
    vector<int> items;  // The heap array


    /**
     * Establish heap order property from an arbitrary
     * arrangement of items. Runs in linear time.
     */
    void buildHeap( )
    {
        for( int i = currentSize / 2; i > 0; --i )
            percolateDown( i );
    }

    /**
     * Internal method to percolate down in the heap.
     * hole is the index at which the percolate begins.
     */
    void percolateDown( int hole )
    {
        int child;
        C tmp = items[ hole ];

        for( ; hole * 2 <= currentSize; hole = child )
        {
            child = hole * 2;
            if( child != currentSize && items[ child + 1 ] > items[ child ] )
                ++child;
            if( items[ child ] > tmp )
                items[ hole ] = items[ child ];
            else
                break;
        }
        items[ hole ] = tmp;
    }
};

#endif	
