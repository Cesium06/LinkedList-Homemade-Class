//
//  main.cpp
//  LinkedList
//  Created by Jonathan Cesari on 10/9/15.
//  Copyright © 2015 Jonathan Cesari. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

void printBreakDescription(std::string);

int main(int argc, const char * argv[]) {
    
    LinkedList newList;
    
    printBreakDescription("Empty List");
    newList.displayList();
    

    newList.insert(15);
    newList.append(55);
    newList.append(23);
    newList.append(30);
    newList.append(75);
    newList.append(99);
    newList.append(300);
    
    printBreakDescription("Filled List");
    newList.displayList();
    
    printBreakDescription("Reverse List");
    
    newList.reverse();
    newList.displayList();
    
    
    LinkedList copyList(newList);
    
    
    printBreakDescription("Print Copied List");
    
    copyList.displayList();
    
    
    copyList.deleteNode(30);
    
    printBreakDescription("Remove 30 From Copy");
    
    copyList.displayList();

    printBreakDescription("Search for 30");
    
    copyList.search(30);
    
    printBreakDescription("Search for 99");
    
    copyList.search(99);
    
    printBreakDescription("Search for 15");
    
    copyList.search(15);
    
    copyList.insertAt(10, 3);
    
    printBreakDescription("Add 10 to 4th location");
    
    copyList.displayList();
    
    copyList.insertAt(1, 0);
    
    printBreakDescription("Add 1 to beginning of list");
    
    copyList.displayList();
    
    copyList.insertAt(200, 6);
    
    printBreakDescription("Add 200 to 7th position");
    
    copyList.displayList();
    
    copyList.insertAt(3150, 115);
    
    printBreakDescription("Add 3150 to 116th position, outside range, added to end");
    
    copyList.displayList();
    
    copyList.deleteNode(3150);
    
    printBreakDescription("Deleted 3150 from final position");
    
    copyList.displayList();
    
    
    return 0;
}

void printBreakDescription(std::string input){
    std::cout <<  "-------- " + input + " --------" << std::endl;
}
