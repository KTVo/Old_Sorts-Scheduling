
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

typedef long long int ll; 

int gcd(int a, int b);
ll findlcm(int arr[], int n);
float findMax(float arr[], int n);
float findMax(float arr[], int n);
int findMin(int arr[], int n);
void findFrameSz(float C[], int T[], int D[], int sz, bool &sz_is_max_frame, float f_min, int f_max);
void countTaskInstances(int P, int T[], int sz);
void find_Shift_with_MIN(int *f1, int *f2, int *f3, int *f4, int num_Phase, int* frame_max_cnt, float f, int *T, float *phase_float);
void find_Shift_with_MAX(int *f1, int *f2, int *f3, int *f4, int num_Phase, int* frame_max_cnt, int f, int *T, int *phase_int);
void check_Phase_int(int *T, int *phase, int *D, int f, int *, int *, int *, int *, int sz, int *frame_max_cnt);
void check_Phase_float(int *T, float *phase, int *D, int f, int *, int *, int *, int *, int sz, int *frame_max_cnt);


int main(int argc, char** argv) {
    /*
    const int sz = 4; 
    int T[sz] = { 6, 9, 12, 18 };
    int D[sz] = { 6, 9, 8,  10 };
    float C[sz] = { 2.0, 2.0, 2.0, 4.0 };
    */
    
    int sz = 3;               //number of tasks
    int T[sz] = { 15, 10, 6 };  //Period
    int D[sz] = { 3, 5 , 6 };    //Absolute deadline
    float C[sz] = { 3, 3, 3 }; //execution time

     
    
    int f1_cnt = 2, 
        f2_cnt = 3, 
        f3_cnt = 5, 
        f4_cnt = 3;
    
    int frames_1[f1_cnt] = {1, 6};
    int frames_2[f2_cnt] = {2, 5, 9};
    int frames_3[f3_cnt] = {3, 4, 7, 8, 10};
    int frames_4[f4_cnt] = {2, 3, 5};
    
    int frame_max_cnt[sz] = {f1_cnt, f2_cnt, f3_cnt, f4_cnt};
    
    int phase_int[sz];
    float phase_float[sz];
    
    int P = findlcm(T, sz);
    
    
    cout<<"\nPeriod = "<<P<<endl;
    
    
    float f_min = findMax(C, sz);
    
    int f_max = findMin(T, sz);
    
    
    //GIVEN
    f_min = 3;
    f_max = 3;
    
    
    
    
  
    bool sz_is_max_frame = true;
       
    findFrameSz(C, T, D, sz, sz_is_max_frame, f_min, f_max);
    
    countTaskInstances(P, T, sz);
    
    if(sz_is_max_frame == false)
    {
        find_Shift_with_MIN(frames_1, frames_2, frames_3, frames_4, sz, frame_max_cnt, f_min, T, phase_float);
        check_Phase_float(T, phase_float,  D, f_min, frames_1, frames_2, frames_3, frames_4, sz, frame_max_cnt);
    }
    else
    {
        find_Shift_with_MAX(frames_1, frames_2, frames_3, frames_4, sz, frame_max_cnt, f_max, T, phase_int);
        
        check_Phase_int(T, phase_int, D, f_max, frames_1, frames_2, frames_3, frames_4, sz, frame_max_cnt);
    }   
    

    return 0;
}


void find_Shift_with_MIN(int *f1, int *f2, int *f3, int *f4, int num_Phase, int* frame_max_cnt, float f, int *T, float *phase_float)
{
    int cnt_phase = 0;
    int phase_min_1 [frame_max_cnt[0]],
        phase_min_2 [frame_max_cnt[1]],
        phase_min_3 [frame_max_cnt[2]],
        phase_min_4 [frame_max_cnt[3]];
    
    f = 4;
    
    cout<<"\nPhase 1:\n";
    
    for(int i = 0; i < frame_max_cnt[0]; i++)
    {
            phase_min_1[i] = f1[i] - 1;
            phase_min_1[i] *= f;
            phase_min_1[i] -= (i*T[0]);
            
            cout<<phase_min_1[i];
            
            if(i != frame_max_cnt[0]-1)
            cout<<"\n";  
    }
    
    cout<<endl;
    
    phase_float[0] = findMin(phase_min_1, frame_max_cnt[0]);
    cout<<"\nminimum for Phase 1 = "<<phase_float[0] <<endl;

    
    cout<<"\n\n------------------------------------------------------------------------------------------\n\n";
    
    
    cout<<"\nPhase 2:\n";
    
    
    for(int i = 0; i < frame_max_cnt[1]; i++)
    {
            phase_min_2[i] = f2[i] - 1;
            phase_min_2[i] *= f;
            phase_min_2[i] -= (i*T[1]);
            
            cout<<phase_min_2[i];
            
            if(i < frame_max_cnt[1]-1)
            cout<<"\n";  
    }
    
    cout<<endl<<endl;
    phase_float[1] = findMin(phase_min_2, frame_max_cnt[1]);
    cout<<"\nminimum for Phase 2 = "<<phase_float[1]<<endl;

    cout<<"\n\n------------------------------------------------------------------------------------------\n\n";
    
    
    cout<<"\nPhase 3:\n";
    
    
    for(int i = 0; i < frame_max_cnt[2]; i++)
    {
        phase_min_3[i] = f3[i] - 1;
        phase_min_3[i] *= f;
        phase_min_3[i] -= (i*T[2]);
            
        cout<<phase_min_3[i];
            
        if(i < frame_max_cnt[2]-1)
            cout<<"\n";  
    }
    
    cout<<endl<<endl;
    
    phase_float[2] = findMin(phase_min_3, frame_max_cnt[2]);
    cout<<"\nminimum for Phase 3 = "<<phase_float[2]<<endl;
    
    

    cout<<"\n\n------------------------------------------------------------------------------------------\n\n";
    
    
    cout<<"\nPhase 4:\n";
    
    
    for(int i = 0; i < frame_max_cnt[3]; i++)
    {
            phase_min_4[i] = f4[i] - 1;
            phase_min_4[i] *= f;
            phase_min_4[i] -= (i*T[3]);
            
            cout<<phase_min_4[i];
            
            if(i < frame_max_cnt[3]-1)
                cout<<"\n";  
    }
    
    cout<<endl<<endl;
    
    phase_float[3] = findMin(phase_min_4, frame_max_cnt[3]);
            
    cout<<"\nminimum for Phase 4 = "<<phase_float[3]<<endl;  
}





void find_Shift_with_MAX(int *f1, int *f2, int *f3, int *f4, int num_Phase, int* frame_max_cnt, int f, int *T, int *phase_int)
{
    int cnt_phase = 0;
    int phase_min_1 [frame_max_cnt[0]],
        phase_min_2 [frame_max_cnt[1]],
        phase_min_3 [frame_max_cnt[2]],
        phase_min_4 [frame_max_cnt[3]];
    

    
    cout<<"\nPhase 1:\n";
    
    for(int i = 0; i < frame_max_cnt[0]; i++)
    {
            phase_min_1[i] = f1[i] - 1;
            phase_min_1[i] *= f;
            phase_min_1[i] -= (i*T[0]);
            
            cout<<phase_min_1[i];
            
            if(i != frame_max_cnt[0]-1)
            cout<<"\n";  
    }
    
    cout<<endl;
    
    phase_int[0] = findMin(phase_min_1, frame_max_cnt[0]);
            
    cout<<"\nminimum for Phase 1 = "<<phase_int[0]<<endl;

    
    cout<<"\n\n------------------------------------------------------------------------------------------\n\n";
    
    
    cout<<"\nPhase 2:\n";
    
    
    for(int i = 0; i < frame_max_cnt[1]; i++)
    {
            phase_min_2[i] = f2[i] - 1;
            phase_min_2[i] *= f;
            phase_min_2[i] -= (i*T[1]);
            
            cout<<phase_min_2[i];
            
            if(i < frame_max_cnt[1]-1)
            cout<<"\n";  
    }
    
    cout<<endl<<endl;
    
    phase_int[1] = findMin(phase_min_2, frame_max_cnt[1]);
    
    cout<<"\nminimum for Phase 2 = "<<phase_int[1]<<endl;

    cout<<"\n\n------------------------------------------------------------------------------------------\n\n";
    
    
    cout<<"\nPhase 3:\n";
    
    
    for(int i = 0; i < frame_max_cnt[2]; i++)
    {
        phase_min_3[i] = f3[i] - 1;
        phase_min_3[i] *= f;
        phase_min_3[i] -= (i*T[2]);
            
        cout<<phase_min_3[i];
            
        if(i < frame_max_cnt[2]-1)
            cout<<"\n";  
    }
    
    cout<<endl<<endl;
    
    phase_int[2] = findMin(phase_min_3, frame_max_cnt[2]);
    
    cout<<"\nminimum for Phase 3 = "<<phase_int[2]<<endl;
    
    

    cout<<"\n\n------------------------------------------------------------------------------------------\n\n";
    
    
    cout<<"\nPhase 4:\n";
    
    
    for(int i = 0; i < frame_max_cnt[3]; i++)
    {
            phase_min_4[i] = f4[i] - 1;
            phase_min_4[i] *= f;
            phase_min_4[i] -= (i*T[3]);
            
            cout<<phase_min_4[i];
            
            if(i < frame_max_cnt[3]-1)
                cout<<"\n";  
    }
    
    cout<<endl<<endl;
    
    phase_int[3] = findMin(phase_min_4, frame_max_cnt[3]);
    
    cout<<"\nminimum for Phase 4 = "<<phase_int[3]<<endl;  
}














// Utility function to find 
// GCD of 'a' and 'b' 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
// Returns LCM of array elements 
ll findlcm(int arr[], int n) 
{ 
    // Initialize result 
    ll ans = arr[0]; 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 

float findMax(float arr[], int n)
{
    float temp = arr[0];
    
    for(int i = 0; i < n; i++)
        if(temp < arr[i])
            temp = arr[i];
    
    return temp;
}

int findMin(int arr[], int n)
{
    int temp = arr[0];
    
    for(int i = 0; i < n; i++)
        if(temp > arr[i])
            temp = arr[i];
    
    return temp;
}

void findFrameSz(float C[], int T[], int D[], int sz, bool &sz_is_max_frame, float f_min, int f_max)
{
    
    cout<<endl;
    
    cout<<f_min<<" <= f <= "<<f_max<<endl;
    
    
    
    cout<<endl<<"D = {";
    
    for(int i = 0; i < sz; i++)
    {
        cout<<D[i]<<", ";
        if(f_max >= D[i])
            sz_is_max_frame = false;
    }
    
    cout<<" }\n";
    
    if(sz_is_max_frame == false)
        cout<<"\tTherefore, size of frame = f_min -> f = "<<f_min<<endl;
    else
        cout<<"\tTherefore, size of frame = f_max -> f = "<<f_max<<endl;
    
    
    

}

void countTaskInstances(int P, int T[], int sz)
{
    cout<<"\nNumber of Instances for each Task:\n--------------------------------\n";
    
    for(int i = 0; i < sz; i++)
    {
        float temp = (float)(P/T[i]);
        
        cout<<temp<<" for Task "<<i+1<<endl;
    }           
}


void check_Phase_int(int *T, int *phase, int *D, int f, int *f_i_j_1, int *f_i_j_2, int *f_i_j_3, int *f_i_j_4, int sz, int *frame_max_cnt)
{
    //(j − 1)Ti + Φi + Di ≥ fi,j * f            ∀ i,  1 ≤ j ≤ P/Ti
    
    
    int i = 0;
    
    cout<<"\nPhase "<<i+1<<":\n";
        
    for(int j = 0; j < frame_max_cnt[i]; j++)
    {
        int temp = j*T[i] + phase[i] + D[i];
            
        cout<<"("<<j+1<<" - 1)*"<<T[i]<<" + "<<phase[i]<<" + "<<D[i]<<" = "
            <<temp<<" >= "<<f_i_j_1[j]*f<<" = "<<f_i_j_1[j]<<" * 4 \t";
            
        if(temp >= f_i_j_1[j]*f)
            cout<<"TRUE\n";
        else
            cout<<"FALSE\n";
    }

        cout<<endl<<endl;
  
        cout<<"------------------------------------------------------------------------------\n";
    
    i = 1;
    cout<<"\nPhase "<<i+1<<":\n";
        
    for(int j = 0; j < frame_max_cnt[i]; j++)
    {
        int temp = j*T[i] + phase[i] + D[i];
            
        cout<<"("<<j+1<<" - 1)*"<<T[i]<<" + "<<phase[i]<<" + "<<D[i]<<" = "
            <<temp<<" >= "<<f_i_j_2[j]*f<<" = "<<f_i_j_2[j]<<" * 4 \t";
            
        if(temp >= f_i_j_2[j]*f)
            cout<<"TRUE\n";
        else
            cout<<"FALSE\n";
    }

        cout<<endl<<endl;
  
        cout<<"------------------------------------------------------------------------------\n";
        
        
        
    i = 2;
    cout<<"\nPhase "<<i+1<<":\n";
        
    for(int j = 0; j < frame_max_cnt[i]; j++)
    {
        int temp = j*T[i] + phase[i] + D[i];
            
        cout<<"("<<j+1<<" - 1)*"<<T[i]<<" + "<<phase[i]<<" + "<<D[i]<<" = "
            <<temp<<" >= "<<f_i_j_3[j]*f<<" = "<<f_i_j_3[j]<<" * 4 \t";
            
        if(temp >= f_i_j_3[j]*f)
            cout<<"TRUE\n";
        else
            cout<<"FALSE\n";
    }

        cout<<endl<<endl;
  
        cout<<"------------------------------------------------------------------------------\n";
        
    i = 3;
    cout<<"\nPhase "<<i+1<<":\n";
        
    for(int j = 0; j < frame_max_cnt[i]; j++)
    {
        int temp = j*T[i] + phase[i] + D[i];
            
        cout<<"("<<j+1<<" - 1)*"<<T[i]<<" + "<<phase[i]<<" + "<<D[i]<<" = "
            <<temp<<" >= "<<f_i_j_4[j]*f<<" = "<<f_i_j_4[j]<<" * 4 \t";
            
        if(temp >= f_i_j_4[j]*f)
            cout<<"TRUE\n";
        else
            cout<<"FALSE\n";
    }

        cout<<endl<<endl;
  
        cout<<"------------------------------------------------------------------------------\n";    
    
    
}

void check_Phase_float(int *T, float *phase, int *D, int f, int *f_i_j_1, int *f_i_j_2, int *f_i_j_3, int *f_i_j_4, int sz, int *frame_max_cnt)
{
    //(j − 1)Ti + Φi + Di ≥ fi,j * f            ∀ i,  1 ≤ j ≤ P/Ti
    
    
    int i = 0;
    
    cout<<"\nPhase "<<i+1<<":\n";
        
    for(int j = 0; j < frame_max_cnt[i]; j++)
    {
        int temp = j*T[i] + phase[i] + D[i];
            
        cout<<"("<<j+1<<" - 1)*"<<T[i]<<" + "<<phase[i]<<" + "<<D[i]<<" = "
            <<temp<<" >= "<<f_i_j_1[j]*f<<" = "<<f_i_j_1[j]<<" * 4 \t";
            
        if(temp >= f_i_j_1[j]*f)
            cout<<"TRUE\n";
        else
            cout<<"FALSE\n";
    }

        cout<<endl<<endl;
  
        cout<<"------------------------------------------------------------------------------\n";
    
    i = 1;
    cout<<"\nPhase "<<i+1<<":\n";
        
    for(int j = 0; j < frame_max_cnt[i]; j++)
    {
        int temp = j*T[i] + phase[i] + D[i];
            
        cout<<"("<<j+1<<" - 1)*"<<T[i]<<" + "<<phase[i]<<" + "<<D[i]<<" = "
            <<temp<<" >= "<<f_i_j_2[j]*f<<" = "<<f_i_j_2[j]<<" * 4 \t";
            
        if(temp >= f_i_j_2[j]*f)
            cout<<"TRUE\n";
        else
            cout<<"FALSE\n";
    }

        cout<<endl<<endl;
  
        cout<<"------------------------------------------------------------------------------\n";
        
        
        
    i = 2;
    cout<<"\nPhase "<<i+1<<":\n";
        
    for(int j = 0; j < frame_max_cnt[i]; j++)
    {
        int temp = j*T[i] + phase[i] + D[i];
            
        cout<<"("<<j+1<<" - 1)*"<<T[i]<<" + "<<phase[i]<<" + "<<D[i]<<" = "
            <<temp<<" >= "<<f_i_j_3[j]*f<<" = "<<f_i_j_3[j]<<" * 4 \t";
            
        if(temp >= f_i_j_3[j]*f)
            cout<<"TRUE\n";
        else
            cout<<"FALSE\n";
    }

        cout<<endl<<endl;
  
        cout<<"------------------------------------------------------------------------------\n";
        
    i = 3;
    cout<<"\nPhase "<<i+1<<":\n";
        
    for(int j = 0; j < frame_max_cnt[i]; j++)
    {
        int temp = j*T[i] + phase[i] + D[i];
            
        cout<<"("<<j+1<<" - 1)*"<<T[i]<<" + "<<phase[i]<<" + "<<D[i]<<" = "
            <<temp<<" >= "<<f_i_j_4[j]*f<<" = "<<f_i_j_4[j]<<" * 4 \t";
            
        if(temp >= f_i_j_4[j]*f)
            cout<<"TRUE\n";
        else
            cout<<"FALSE\n";
    }

        cout<<endl<<endl;
  
        cout<<"------------------------------------------------------------------------------\n";    
    
}