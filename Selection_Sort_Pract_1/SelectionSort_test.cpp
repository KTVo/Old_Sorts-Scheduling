/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on June 5, 2019, 4:04 PM
 */
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template <typename C>
void selectionSort(vector<C>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        
        int min = i;
        for (int j = i + 1; j < v.size(); j++)
        if (v[j] < v[min])
            min = j;
        if (min != i)
        { //swap v[min] and v[i]
            C temp = v[min];
            v[min] = v[i];
            v[i] = temp;
        }
        
        cout<<"\ni = "<<i<<":\n";
        for(int k = 0; k < v.size(); k++)
            cout<<" [ "<<k<<" ] = "<<v[k]<<"\n";
        cout<<endl<<"--------------------------------"<<endl;
    }
}


int main(int argc, char** argv) {
    vector<int> v = {7, 5, 1, 6, 8, 3, 2};
    
    selectionSort(v);
    return 0;
}

