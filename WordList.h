#ifndef WORDLIST
#define WORDLIST
#include <string>
#include "IntList.h"

using namespace std;

// declaration of class WordList
class WordList
{
private:
   // private attributes contain a struct and an instance of that struct
   struct WordNode
   {
      string word;
      IntList* lineNumList = new IntList;
      WordNode* next = nullptr;
   };
   WordNode* head;
public:
   // constructor and descontructor
   WordList() { head = nullptr; }
   ~WordList();

   // functions to interact with the list 
   void caseInsensitive(string&);
   void insertNode(string, int);
   void displayWordList() const;
};

#endif
