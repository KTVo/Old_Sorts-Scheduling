/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SLinked.h
 * Author: Kevin
 *
 * Created on August 29, 2019, 1:27 PM
 */

#ifndef SLINKED_H
#define SLINKED_H
#include <iostream>
#include <cstdlib>

using namespace std;
class SLinked
{
    int count;
    struct Node
    {
        int data;
        Node *next;
    };
    
    Node *head, *tail;
public:
    SLinked()
    {
        head = new Node;
        tail = head;
        count = 0;
    };
    
    
    ~SLinked()
    {
        while(head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    
public:
    void insert(const int data);
    void display();
    void deleteVal(const int);
    void deleteNode(const int);
};

void SLinked::insert(const int data)
{

        Node *y = new Node;
        
        y->data = data;
                
        tail->next = y;
        tail = y;
        
        count++;
}

void SLinked::display()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
}


void SLinked::deleteVal(const int x)
{
    Node *temp = head;
    bool found = false;
    while(!found && temp->next != NULL)
    {
        if(temp->next->data == x)
        {  
            Node *t = temp->next;
            temp->next = temp->next->next;
            delete t;
            found = true;
            count--;
        }
    }
}

    void SLinked::deleteNode(const int x)
    {
        if(count >= x)
        {
            Node *temp = head;
            for(int i = 0; i < x-1; i++)
                temp = temp->next;
            Node *t = temp ->next;
            temp = temp->next->next;
            delete t;
            count--;
        }
    }
#endif /* SLINKED_H */

