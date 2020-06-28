#include <iostream>
#include <cstdlib>

using namespace std;

int L_lateness(const int f, const int d)
{
    return f - d;
}

int E_Tardiness(const int l)
{
    if(l > 0)
        return l;
    else
        return 0;
}

int X_Laxity(const int d, const int a, const int C)
{
    return d - a - C;
}


int main(int argc, char** argv) {
  //Inputs      
  const int r1 = 0, 
            r2 = 5,
            f1 = 19,
            f2 = 29,
            d1 = 22,
            d2 = 28;
                
  
        int L1,
            L2,
            E1,
            E2,
            X1,
            X2;
        
        int C1 = (6 - 0) + (19-15);
        int C2 = (15-6) + (29-25);
        
/*******************************************************************************
 * 
 *                           changes STOP here
 * 
 ******************************************************************************/

        L1 = L_lateness(f1, d1);
        L2 = L_lateness(f2, d2);
        
        E1 = E_Tardiness(L1);
        E2 = E_Tardiness(L2);
        
        X1 = X_Laxity(d1, r1, C1);
        X2 = X_Laxity(d2, r2, C2);
        
        
        cout<<endl<<"r1 = a1 = "<<r1;
        cout<<endl<<"r2 = a2 = "<<r2;
        cout<<endl<<"f1 = finish time 1 = "<<f1;
        cout<<endl<<"f2 = finish time 2 = "<<f2;
        cout<<endl<<"d1 = deadline 1 = "<<d1;
        cout<<endl<<"d2 = deadline 2 = "<<d2;
        
        cout<<endl<<"L1 = Lateness 1 = "<<L1;
        cout<<endl<<"L2 = Lateness 2 = "<<L2;
        
        cout<<endl<<"E1 = Tardiness 1 = "<<E1;
        cout<<endl<<"E2 = Tardiness 2 = "<<E2;
        
        cout<<endl<<"X1 = Laxity 1 = "<<X1;
        cout<<endl<<"X2 = Laxity 2 = "<<X2;
        
        cout<<endl;
    return 0;
}

