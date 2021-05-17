#include "WordList.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// In this function, we delete every element of the list and destroy the object
//
// Inputs:   none
// Outputs:  none
WordList::~WordList()
{
   // setting up iterator
   WordNode* nodePtr;
   WordNode* nextNode;
   nodePtr = head;

   // iterating through list, deleting each node and pointing to the next node
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;

      delete nodePtr;

      nodePtr = nextNode;
   }
}

// In this function, we delete every element of the list and destroy the object
//
// Inputs:   a string passed by reference
// Outputs:  none
void WordList::caseInsensitive(string& rawStr)
{
   // iterating through string and setting all elements to lowercase
   for (int ix = 0; ix < rawStr.length(); ix++)
   {
      rawStr[ix] = tolower(rawStr[ix]);
   }
}

// In this function, we insert a node in its proper place alphabetically
//
// Inputs:   a string, an int
// Outputs:  none
void WordList::insertNode(string word, int lineNumber)
{
   // setting up iterator and node to hold value to be inserted
   WordNode* nodePtr;
   WordNode* newNode;
   WordNode* previousNode = nullptr;

   if (!head)
   {
      // setting up iterator and node to hold value to be inserted
      newNode = new WordNode;
      newNode->word = word;
      newNode->lineNumList->appendNode(lineNumber);
      // setting node as the "head" if it is the only node in the list
      head = newNode;
      newNode->next = nullptr;
   }
   else
   {
      // setting up pointers to walk through the list and insert nodes
      nodePtr = head;
      previousNode = nullptr;

      // making words case insensitive
      caseInsensitive(nodePtr->word);
      caseInsensitive(word);

      // iterating through list, skipping over value smaller than value to be inserted
      while ((nodePtr != nullptr) && (nodePtr->word < word ))
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // checking whether a word matches one we already have in the list
      if (nodePtr!=nullptr && nodePtr->word == word)
      {
         // making sure we don't add duplicate line numbers under the same word
         if(!(nodePtr->lineNumList->duplicateNum(lineNumber)))
         {
            nodePtr->lineNumList->appendNode(lineNumber);
         }
      }
      else if (previousNode == nullptr)
      {
         // setting up node to hold value to be inserted
         newNode = new WordNode;
         newNode->word = word;
         newNode->lineNumList->appendNode(lineNumber);

         // inserting node at the very beginning
         head = newNode;
         newNode->next = nodePtr;
      }
      else
      {
         // setting up node to hold value to be inserted
         newNode = new WordNode;
         newNode->word = word;
         newNode->lineNumList->appendNode(lineNumber);

         // inserting node either at the very end or between 2 other nodes (sorted of course)
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

// In this function, we display the elements of the List
//
// Inputs:   none
// Outputs:  none
void WordList::displayWordList() const
{
   // setting up iterator
   WordNode* nodePtr;
   nodePtr = head;

   // when end of list is reached, nullptr makes the loop return false and terminates
   while (nodePtr)
   {
      cout << setw(15) << nodePtr->word;
      // calling member function of IntList object to print its contents
      nodePtr->lineNumList->displayIntList();
      cout << endl;
      nodePtr = nodePtr->next;
   }
}
