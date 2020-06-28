/* 
 * File:   bubbleSort_main.cpp
 * Author: Kevin
 *
 * Created on June 13, 2020, 8:22 AM
 */

#include <iostream>

using namespace std;
void displayArr(const int[], const int);
void populateArr(int[], const int);

//sorts using bubble sort
void bubbleSort(int a[], const int sz)
{
    for(int i = 0; i < sz; i++)
        for(int j = i + 1; j < sz; j++)
        {
            if(a[i] > a[j])
            {
                cout<<a[i]<< " <-> "<<a[j]<<endl;
                cout<<"\t";
                displayArr(a, i);
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    
}


int main()
{
    srand(time(NULL)); //seeding for rng to populate array
    
    const int sz = 12;
    int a[sz];
    
    populateArr(a, sz);
    
    cout<<"Unsorted: ";
    
    displayArr(a, sz);
    
    bubbleSort(a, sz);
    
    //cout<<"Sorted:  ";
    
    
    cout<<endl<<endl;
    
    
    
    cout<<endl<<endl;
    
    displayArr(a, sz);

    return 0;
}
//Displays all values of an array
void displayArr(const int a[], const int sz)
{
    for(int i = 0; i < sz; i++)
    {
        cout<<a[i];
        
        if(i < sz-1)
            cout<<", ";
    }
    
    cout<<endl;
}

//fills array with random ints
void populateArr(int a[], const int sz)
{
    for(int i = 0; i < sz; i++)
    {
        a[i] = rand()%100;
    }
}