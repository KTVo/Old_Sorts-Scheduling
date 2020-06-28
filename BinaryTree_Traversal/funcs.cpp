/*
 * Name: Kevin Vo
 * ID: 006316930
 * Professor: Dr. Yan Zhang
 * Assignment: Assignment#3 - Problem 4
 * Purpose: This program will construct the given binary tree as it prints the
 *          binary tree in preorder, inorder, and level-order traversal 
 *          non-recursively with the use for stacks with pre- and in- while
 *          level-order uses a queue.
 * Date: 5/19/19
*/

// funcs.cpp
#include<iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;
template <typename T>
struct BinaryNode
{
    T data;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(const T & d = T()):data(d),left(nullptr),right(nullptr)
    { }
};

/*Purpose: Prints the elements of binary tree in preorder non-recursively using
 *         Stacks  as a starting point.
 * 
 *Parameters: Takes in the root node which is a pointer from the BinaryNode 
 *            structure.  
 */
template <typename T>
void preorder(BinaryNode<T>* root)
{
    Stack<BinaryNode<T>*> s;    //Declares object for Stack class 
                                //Stack will store nodes as BinaryNode<T> 
                                //pointers from class BinaryNode<T> 
    
    s.push(root);   //Stack will store the root node first
    
    //while-loop will continue to push and pop nodes so that all values of the
    //Binary Tree can be printed in pre-order non-recursively
    while(!s.empty())
    {
        BinaryNode<T>* cur = s.top();   //sets ptr cur to top of stack
        s.pop();                        //pops the top of stack and reset top
        cout<<cur->data<<" ";    //prints out the top of stack prior to popping
        
        //push the RIGHT child node of cur unless its null/node is non-existent
        if(cur->right != nullptr)   
            s.push(cur->right);
        
        //push the LEFT child node of cur unless its null/node is non-existent
        if(cur->left != nullptr)
            s.push(cur->left);
    }
}

/*Purpose: Prints the elements of binary tree in inorder non-recursively using
 *         Stacks.
 * 
 *Parameters: Takes in the root node which is a pointer from the BinaryNode 
 *            structure as a starting point.  
 */
template <typename T>
void inorder(BinaryNode<T>* root)
{
    Stack<BinaryNode<T>*> s;    //Declares object for Stack class
    BinaryNode<T>* cur = root;  //set cur ptr to root of Binary Tree
    
    //while-loop will continue to push and pop nodes so that all values of the
    //Binary Tree can be printed in in-order non-recursively
    while(cur != nullptr || !s.empty())
    {
        //pushes left child nodes until it hits nullptr
        while(cur != nullptr)
        {
            s.push(cur);
            cur = cur->left;
        }
        
        //sets cur ptr to the top of the stack
        cur = s.top();
        
        //pops the top of stack and reset the top ptr
        s.pop();
        
        //prints out the value of the node that was on top of the stack prior
        //to popping
        cout<<cur->data<<" ";
        
        //Sets cur to the right child of it for while-loop to continue/halt
        cur = cur->right;
    }
    
}

/*Purpose: Prints the elements of binary tree in level order non-recursively 
 *         using Stacks.
 * 
 *Parameters: Takes in the root node which is a pointer from the BinaryNode 
 *            structure as a starting point.  
 */
template <typename T>
void levelorder (BinaryNode<T>* root)
{
    Queue<BinaryNode<T>*> q;    //Declare object for Queue class
    
    //push root onto the queue as long as there is a root
    if (root != nullptr)
        q.enqueue(root);
    
    
    //loops until queue is empty as values from the binary tree is enqueue,
    // dequeued, or printed
    while (!q.empty())
    {
        BinaryNode<T>* cur = q.front_element(); //sets cur to top of queue
        q.dequeue();    //dequeues from stack
        cout<<cur->data<<" ";  //prints out the front of queue (FIFO) prior to
                                //dequeuing

        //Pushes on left child of node cur is pointing to unless there is none
        if (cur->left != nullptr)
            q.enqueue(cur->left);
        
        
        //Pushes on left child of node cur is pointing to unless there is none
        if (cur->right != nullptr)
            q.enqueue(cur->right);
        
    }
    
}