#ifndef INTLIST
#define INTLIST

using namespace std;

// declaration of class IntList
class IntList
{
private:
   // private attributes contain a struct and an instance of that struct

   struct IntNode
   {
      int lineNumber;
      IntNode* next;
   };
   IntNode* headInt;
   
public:
   // constructor and descontructor
   IntList() { headInt = nullptr; }
   ~IntList();

   // functions to interact with the list 
   void appendNode(int);
   void displayIntList() const;
   bool duplicateNum(int) const;
};

#endif
