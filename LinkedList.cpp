//
//  LinkedList.cpp
//  LinkedList
//  Created by Jonathan Cesari on 10/9/15.
//  Copyright © 2015 Jonathan Cesari. All rights reserved.
//

#include "LinkedList.h"
#include <iostream>


//Default constructor definition
LinkedList::LinkedList(){
    headPtr = nullptr;
}

//Constructor
LinkedList::LinkedList (const LinkedList &copyList){
    headPtr = nullptr;
    
    Node * listCopy = copyList.headPtr; //points to the front of the list to copy
    
    //While listCopy is not nullptr
    while (listCopy != nullptr){
        append(listCopy->value);    //use our created function to add to the list
        listCopy = listCopy->nextPtr;   //progress the list to the next value
    }
    
}

////////////////////////////
/////////Destructor/////////
////////////////////////////

LinkedList::~LinkedList(){
    Node *nodePtr; // To traverse the list
    Node *nextNode; // To point to the next node
    
    // Position nodePtr at the head of the list.
    nodePtr = headPtr;
    
    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr){
        // Save a pointer to the next node.
        nextNode = nodePtr->nextPtr;
        // Delete the current node.
        delete nodePtr;
        
        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

////////////////////////////
////Method Definitions/////
////////////////////////////


void LinkedList::append(int number){
    Node *newNode;  // To point to a new node
    Node *nodePtr;  //To move through the list
    
    //Allocate a new node and store number there
    //Set its nextPtr to nullptr
    newNode = new Node;
    newNode->value = number;
    newNode->nextPtr = nullptr;
    
    // If there are no nodes in the list
    // make newNode the first node.
    // Used to set up initial list
    if (!headPtr)
        headPtr = newNode;
    else    //Otherwise insert at the end of the list
    {
        // Initialize nodePtr to head of list.
        nodePtr = headPtr;  // at front of list
        
        //while starting from a the head
        //a nextPtr exists
        while (nodePtr->nextPtr)
            //set the location of nodePtr
            //to the next Node structure
            nodePtr = nodePtr->nextPtr;
        
        //when this is false (aka, nextPtr is nullptr)
        //set the nullptr to the newNode created above
        nodePtr->nextPtr = newNode;
    }
    
    //Head points to the first node
    
}

void LinkedList::deleteNode(int value){
    Node *prevNode = nullptr;  // To point to previous node
    Node *nodePtr = nullptr;  //To move through the list
 
    
    if (!headPtr)
        return;
    if (headPtr->value == value)
    {
        nodePtr = headPtr->nextPtr;
        delete headPtr;
        headPtr = nodePtr;
    }
    else
    //intalize nodePtr to head of the list
        nodePtr = headPtr;
    
    //skip all nodes whose value member is
    // not equal to value
    while (nodePtr != nullptr && nodePtr->value != value)
    {
        prevNode = nodePtr;
        nodePtr = nodePtr->nextPtr;
    }
    // If nodePtr is not at the end of the list,
    // link the previous node to the node after
    // nodePtr, then delete nodePtr.
    if (nodePtr){
        prevNode->nextPtr = nodePtr->nextPtr;
        delete nodePtr;
    }
}

void LinkedList::insert(int number){
    Node *prevNode = nullptr;   //holds the previous node for connecting the nextPtr
    Node *nodePtr = nullptr;  //used to transverse the list
    Node *newNode;  //creates new node to be added
    newNode = new Node; //allocate space in memory
    
    newNode->value = number;
    
    
    if (!headPtr){
        headPtr = newNode;
        newNode->nextPtr = nullptr;
    }
    else{
        //point nodePtr to front of the list
        nodePtr = headPtr;
        
        while (nodePtr != nullptr && nodePtr->value < number)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->nextPtr;
        }
        // If the new node is to be the 1st in the list
        // insert it before all other nodes.
        if (prevNode == nullptr){
            headPtr = newNode;
            newNode->nextPtr = nodePtr;
        }
        else    //otherwise insert after the prev node
            prevNode->nextPtr = newNode;
            newNode->nextPtr = nodePtr;
        
    }
}

void LinkedList::displayList(){
    
    Node *nodePtr;
    
    nodePtr = headPtr;
    
    if (!headPtr)
        std::cout << "Linked list is empty!" << std::endl;
    else
    
    while (nodePtr){
        //Output value
        std::cout << nodePtr->value << std::endl;
        
        //Move to next pointer
        nodePtr = nodePtr->nextPtr;
        
    }
    
}



void LinkedList::reverse(){
    
    if (!headPtr)
        return;
    
    Node *prevPtr = NULL, *currentPtr = NULL, *nextPtr = NULL;
    currentPtr = headPtr;
    while (currentPtr != NULL){
       
        nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr = prevPtr;
        prevPtr = currentPtr;
        currentPtr = nextPtr;
            
        }
    headPtr = prevPtr;
}


void LinkedList::search(int number){
    //Locate number in the list
    //start a temporary Node at the head
    //move through Node temporary = temp->nextPtr
    //increment local variable
    //if temp.value == number
    
    Node *transList;
    int counter = 0;
    transList = headPtr;    //points to the head
    
    if (transList == nullptr)
        return;
    else{
        while (transList != nullptr){
            if (transList->value != number){
                transList = transList->nextPtr;
                counter++;
            }
            else{
                std::cout << "The value is: " << transList->value << " at location " << counter << std::endl;
                transList = transList->nextPtr;
            }
        }
        std::cout << "End of the search!" << std::endl;
    }
}

void LinkedList::insertAt(int number, int position){
    //repeat the process of transversing the list
    //when position == counter
    int counter = 0;
    bool added = false;
    Node *transList;
    Node *nextNode;
    Node *prevNode = nullptr;
    Node *newNode;
    newNode = new Node;
    
    //This will be equal to the nextNode to link the list
    newNode->nextPtr = nullptr;
    newNode->value = number;
    
    transList = headPtr;    //points to the head, 0 location
    
    if(transList == nullptr){
        headPtr = newNode;
        added = true;
    }
    else if(position == 0){
        headPtr = newNode;
        newNode->nextPtr = transList;
        added = true;
    }
    else{
        //end of the list
        while (transList != nullptr){
            
            //set prevNode to trans list prior to moving translist
            prevNode = transList;
            counter++;  //increment on each loop
            
            if (counter == position){
                nextNode = transList->nextPtr;  //sets the nextNode, 1 after trans
                newNode->nextPtr = nextNode;    //sets the newNode's pointer to nextNode
                prevNode->nextPtr = newNode;    //sets the previousNode to our nextpOINTER
                newNode = transList;    //sets the newNode to the current location in the list
                transList = transList->nextPtr; //increment spot in the list
                added = true;
            }
            else{
                transList = transList->nextPtr;
            }
        }
        
        
        //If the item was never added to the list because it exceeded the current range
        while (added == false){
            
            //If the transList does not exist because it exceeded range
            if (!transList){
                //set transList to one before exceeded range
                transList = prevNode;
                //set the nextPtr to our new node
                transList->nextPtr = newNode;
                //set our newNode's pointer to a null
                newNode->nextPtr = nullptr;
                //break the while loop
                added = true;
            }
            //transverse list until we exceed the end, preserving the final existing location
            else{
                prevNode = transList;
                transList=transList->nextPtr;

            }
        }
    }
}