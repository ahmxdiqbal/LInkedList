#include "IntList.h"
#include <iostream>
#include <iomanip>

using namespace std;

// In this function, we delete every element of the list and destroy the object
//
// Inputs:   none
// Outputs:  none
IntList::~IntList()
{
   // setting up iterator
   IntNode* nodePtr;
   IntNode* nextNode;
   nodePtr = headInt;

   // iterating through list, deleting each node and pointing to the next node
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;

      delete nodePtr;

      nodePtr = nextNode;
   }
}

// In this function, we append a node to the end of a list
//
// Inputs:   an int
// Outputs:  none
void IntList::appendNode(int lineNumber)
{
   // creating pointers to walk through the list and to hold new data
   IntNode* nodePtr;
   IntNode* newNode;

   // putting values into the new node
   newNode = new IntNode;
   newNode->lineNumber = lineNumber;
   newNode->next = nullptr;

   // if its the only element, we make it the "head"
   if (headInt == nullptr)
   {
      headInt = newNode;
   }
   // iterating to the end of the list and attaching it there
   else
   {
      // iterating to the end of the list
      nodePtr = headInt;
      while (nodePtr->next)
      nodePtr = nodePtr->next;

      nodePtr->next = newNode;
   }
}

// In this function, we display the elements of the List
//
// Inputs:   none
// Outputs:  none
void IntList::displayIntList() const
{
   // setting up iterator
   IntNode* nodePtr;
   nodePtr = headInt;

   // when end of list is reached, nullptr makes the loop return false and terminates
   while (nodePtr)
   {
      cout << setw(3) << nodePtr->lineNumber << " ";
      nodePtr = nodePtr->next;
   }
}

// In this function, we check whether a word has already occured on a particular line
//
// Inputs:   none
// Outputs:  a bool variable
bool IntList::duplicateNum(int lineNum) const
{
   // setting up iterator
   IntNode* nodePtr;
   nodePtr = headInt;

   // iterating through entire list
   while (nodePtr)
   {
      // returning true if a match is found between two words on the same line
      if (lineNum == nodePtr->lineNumber)
      {
         return true;
      }
      nodePtr = nodePtr->next;
   }
   return false;
}