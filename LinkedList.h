//
//  LinkedList.h
//  LinkedList
//
//  Created by Jonathan Cesari on 10/9/15.
//  Copyright © 2015 Jonathan Cesari. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>


class LinkedList{
private:
    struct Node{
        Node * nextPtr;
        int value;
    };
    
    Node * headPtr;
    
public:
    //Constructor
    LinkedList();
    LinkedList(const LinkedList&);
    
    //Destructor
    ~LinkedList();
    
    //Declaring methods
    void append(int);
    void insert(int);
    void insertAt(int, int);
    void deleteNode(int);
    void displayList();
    void search(int);
    void reverse();
   
    
    
};

#endif /* LinkedList_h */
