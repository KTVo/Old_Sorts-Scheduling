#include <iostream>
#include <string>
// Application of circular queue
#include "CircularQueue.h"
// Application of singly linked queue
//#include "LinkedQueue.h" 
// Application of doubly linked queue
//#include "DoublyLinkedQueue.h"

using namespace std;

int main() 
{ 
	Queue<int> int_que;

	int x = 0, k = 0;

	cout << "Enqueue positive numbers (enter -1 to stop): ";
	cin >> x;
	while (x != -1)
	{  
		int_que.enqueue(x);
		cin >> x;		
	}
	cout << endl<< "print queue: ";
	int_que.print(); 
        int_que.myprint();

	cout << "How many numbers to be removed from queue: ";
	cin >> k;
	cout << endl;
	for (int i = 1; i <= k; i++)
	{
		int_que.dequeue();
	}
	cout << endl << "print queue: ";
	int_que.print();
        
        int_que.myprint();
	
	
	Queue<string> string_que;

	string s;

	cout << "Enqueue string (enter exit to stop): ";
	cin >> s;
	while (s != "exit")
	{  
		string_que.enqueue(s);
		cin >> s;		
	}
	cout << endl<< "print queue: ";
	string_que.print(); 
	string_que.myprint();
	cout << "How many strings to be removed from queue: ";
	cin >> k;
	
	for (int i = 1; i <= k; i++)
	{
		string_que.dequeue();
	}
	cout << endl << "print queue: ";
	string_que.print(); 
        string_que.myprint();
  	
	return 0;
}
