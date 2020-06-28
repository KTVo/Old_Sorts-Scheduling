//MaxHeap.h

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MaxHeap
{
private:
    vector<T> arr;

public:
    void deleteMax()
    {
        arr[0] = arr.back(); // copy last element as root
        arr.pop_back(); // delete redundant last element
        //loop to drop the last element from root to its new position
        int cur = 0, maxpos;
        while(cur < arr.size())
        {
            maxpos = cur;
            
            if(2 * cur + 1 < arr.size()) // first child
            {
                if(arr[2 * cur + 1] > arr[maxpos])
                    maxpos = 2 * cur + 1;
            }
            if(2 * cur + 2 < arr.size()) // second child
            {
                if(arr[2 * cur + 2] > arr[maxpos])
                    maxpos = 2 * cur + 2;
            }

            if(maxpos == cur) //at the correct location
                break;

            //swap cur and max
            T tmp = arr[cur];
            arr[cur] = arr[maxpos];
            arr[maxpos] = tmp;

            //update cur
            cur = maxpos;
        }
    }

    void insert(T val)
    {
        arr.resize(arr.size() + 1); // increase size

        // Now push up in height = log(N) time
        int cur = arr.size() - 1; // index of last element

        //loop while parent is smaller, and shift the parent down
        while(cur > 0 && arr[ (cur - 1) / 2 ] < val)
        {
            arr[cur] = arr[ (cur - 1) / 2 ];
            cur = (cur - 1) / 2;
        }

        arr[cur] = val;
    }

    T findMax()
    {
        if(arr.empty())
            return 0; // denoting error or empty heap
        return arr[0];
    }

    bool isEmpty()
    {
        return arr.empty();
    }

    void print() // function for debugging
    {
        int i, num, linecnt;
        for(i = linecnt = 0, num = 1; i < arr.size(); i++, linecnt++)
        {
            if(linecnt == num)
            {
                cout << "\n";
                linecnt = 0;
                num *= 2;
            }
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
#endif