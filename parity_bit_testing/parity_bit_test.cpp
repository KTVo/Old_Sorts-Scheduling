/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   parity.cpp
 * Author: Kevin
 *
 * Created on May 12, 2020, 5:59 AM
 */

#include <cstdlib>
#include <iostream>

int XOR(const int, const int);
void checkWrong(int []);
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    
    const int original[8] = {1, 1, 0, 0, 0, 1, 0, 0};
    int p[4];
    
    int string[12];
    
    string[3 -1] = original[1 -1], string[5 -1] = original[2 -1], string[6 -1] = original[3 -1], 
            string[7 -1] = original[4 -1], string[9 -1] = original[5 -1], string[10 -1] = original[6 -1], 
            string[11 -1] = original[7 -1], string[12 -1] = original[8 -1];
    
    int temp;
    
    cout<<"\nOriginal bits: ";
        
    for(int i = 0; i < 8; i++)
    {   
        cout<<original[i]<<", ";
    }
    
    cout<<endl;
        
    temp = string[3 -1];
    
    temp = XOR(temp, string[5 -1]);
    temp = XOR(temp, string[7 -1]);
    temp = XOR(temp, string[9 -1]);
    temp = XOR(temp, string[11 -1]);
    
    string[1 -1] = temp;
    p[0] = temp;
    
    
    
    temp = string[3 -1];
    
    temp = XOR(temp, string[6 -1]);
    temp = XOR(temp, string[7 -1]);
    temp = XOR(temp, string[10 -1]);
    temp = XOR(temp, string[11 -1]);
    
    
    string[2 -1] = temp;
    p[1] = temp;
    
    temp = string[5 -1];
    
    temp = XOR(temp, string[6 -1]);
    temp = XOR(temp, string[7 -1]);
    temp = XOR(temp, string[12 -1]);
    
    
    
    string[4 -1] = temp;
    p[2] = temp;
    
    
    temp = string[9 -1];

    temp = XOR(temp, string[10 -1]);
    temp = XOR(temp, string[11 -1]);
    temp = XOR(temp, string[12 -1]);
    
    string[8 -1] = temp;
    p[3] = temp;
    
    cout<<"\n---> ";
    for(int i = 8-1; i < 12; i++)
        cout<<i+1<<" - "<<string[i]<<endl;
    
    cout<<"\nParity Bits Completed: ";
    for(int i = 0; i < 4; i++)
    {
        cout<<"\np[ "<<i<<" ] = "<<p[i];
    }
    
    cout<<endl; 
    
    
    cout<<"\nCompleted String: ";
    for(int i = 0; i < 12; i++)
    {
        cout<<string[i]<<"  ";
    }
    
    cout<<endl;
    
    int C[4];
    
    temp = string[1 -1];
    temp = XOR(temp, string[3 -1]);
    temp = XOR(temp, string[5 -1]);
    temp = XOR(temp, string[7 -1]);
    temp = XOR(temp, string[9 -1]);
    temp = XOR(temp, string[11 -1]);
    
    C[0] = temp;

    
    
    
    temp = string[2 -1];
    temp = XOR(temp, string[3 -1]);
    temp = XOR(temp, string[6 -1]);
    temp = XOR(temp, string[7 -1]);
    temp = XOR(temp, string[10 -1]);
    temp = XOR(temp, string[11 -1]);
    
    
    C[1] = temp;

    
    
    temp = string[4 -1];
    temp = XOR(temp, string[5 -1]);
    temp = XOR(temp, string[6 -1]);
    temp = XOR(temp, string[7 -1]);
    temp = XOR(temp, string[12 -1]);
    
    
    
    C[2] = temp;

    
    temp = string[8 -1];
    temp = XOR(temp, string[9 -1]);
    temp = XOR(temp, string[10 -1]);
    temp = XOR(temp, string[11 -1]);
    temp = XOR(temp, string[12 -1]);
    
    C[3] = temp;
    
    
    for(int i = 0; i < 4; i++)
    {
        cout<<"\nC[ "<<i<<" ] = "<<C[i]<<endl;
    }
    
    cout<<"\n-----------------------------------------------------------------------\n";
    checkWrong(p);
    
    return 0;
}

int XOR(const int x, const int y)
{
    if(x == 0 && y == 0)
        return 0;
    else if(x == 0 && y == 1)
        return 1;
    else if(x == 1 && y == 0)
        return 1;
    else if(x == 1 && y == 1)
        return 0;
    
}

void checkWrong(int p[])
{
    int temp; 
    int string[12];
    
    string[1 -1] = p[0];
    string[2 -1] = p[1];
    string[4 -1] = p[2];
    string[8 -1] = p[3];
    
    /*
    string[3 -1] = ;
    string[5 -1] = ;
    string[6 -1] = ;
    string[7 -1] = ;
    string[9 -1] = ;
    string[10 -1] = ;
    string[11 -1] = ;
    string[12 -1] = ;
    */
    
    cout<<endl<<"\nCheck WRONG STRING:\n";
    
    cout<<"\nCompleted WRONG String: ";
    for(int i = 0; i < 12; i++)
    {
        cout<<string[i]<<"  ";
    }
    
    int C[4];
    
    temp = string[1 -1];
    temp = XOR(temp, string[3 -1]);
    temp = XOR(temp, string[5 -1]);
    temp = XOR(temp, string[7 -1]);
    temp = XOR(temp, string[9 -1]);
    temp = XOR(temp, string[11 -1]);
    
    C[0] = temp;

    
    
    
    temp = string[2 -1];
    temp = XOR(temp, string[3 -1]);
    temp = XOR(temp, string[6 -1]);
    temp = XOR(temp, string[7 -1]);
    temp = XOR(temp, string[10 -1]);
    temp = XOR(temp, string[11 -1]);
    
    
    C[1] = temp;

    
    
    temp = string[4 -1];
    temp = XOR(temp, string[5 -1]);
    temp = XOR(temp, string[6 -1]);
    temp = XOR(temp, string[7 -1]);
    temp = XOR(temp, string[12 -1]);
    
    
    
    C[2] = temp;

    
    temp = string[8 -1];
    temp = XOR(temp, string[9 -1]);
    temp = XOR(temp, string[10 -1]);
    temp = XOR(temp, string[11 -1]);
    temp = XOR(temp, string[12 -1]);
    
    C[3] = temp;
    
    for(int i = 0; i < 4; i++)
    {
        cout<<"\nC[ "<<i<<" ] = "<<C[i]<<endl;
    }
}

