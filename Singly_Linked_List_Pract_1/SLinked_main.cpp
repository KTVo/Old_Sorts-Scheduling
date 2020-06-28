#include <iostream>
#include <cstdlib>
#include "SLinked.h"
using namespace std;


int main(int argc, char** argv) {
    SLinked x;
    
    x.insert(3);
    x.insert(44);
    x.insert(555);
    x.insert(6);
    x.insert(777777);
    
    x.deleteNode(2);
    x.display();
    return 0;
}

