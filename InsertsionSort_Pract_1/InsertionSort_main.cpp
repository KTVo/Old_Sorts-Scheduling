/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on May 30, 2019, 8:16 PM
 */

#include <iostream>
#include <cstdlib>
#include <vector>


using namespace std;


template <typename C>
void insertionSort(vector<C>& v)
{
    for (int i = 1; i < v.size(); i++)
    {
      
        C temp = v[i];
        int j = i;
        while (j > 0 && v[j - 1] > temp)
        {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = temp;
        
        cout<<"\ni = "<<i<<":\n";
        for(int k = 0; k < v.size(); k++)
            cout<<" [ "<<k<<" ] = "<<v[k]<<"\n";
        cout<<endl<<"--------------------------------"<<endl;
     }
}


int main(int argc, char** argv) {
    vector<int> v = {7, 5, 1, 6, 8, 3, 2};
    
    insertionSort(v);
    
    return 0;
}

