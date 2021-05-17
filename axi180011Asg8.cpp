/*******************************************************************************************************
* Linked List Cross Reference
*
* This program gets and opens a file entered by the user. It then reads the file line by line. It then
* decomposes each line into indiviual words. It then adds that words to a list. Repeats of words are 
* not stored individually; 1 node holds all repeats and keeps track of the lines they occured on. 
*
* It then prints the contents of the list, deletes it, then asks the user to enter another file. It 
* exits this loop when a single asterick is entered.
*
* Written by Ahmed Iqbal for CS1337.009, assignment 8, starting May 8, 2021.
* NetID: axi180011
*******************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "WordList.h"

using namespace std;

// declaring protoypes
int extract(string, string&, int);
void openFile(ifstream&);

int main()
{
   // while true loop iterates until * is entered
   while (true) 
   {
      ifstream inFile;
      // calling function to open file
      openFile(inFile);

      int lineNumber = 1;
      string sentence, decompWord;
      // dynamically allocating list
      WordList* list = new WordList;

      // reads in an entire in from the opened file
      while (getline(inFile, sentence))
      {
         int index = 0;
         bool moreExtraction = true;

         // loop makes sure we have extracted every word from the sentence
         while (moreExtraction)
         {
            index = extract(sentence, decompWord, index);
            // if statement accounts for punctutation and whitespace back to back
            if (sentence[index - 2] != ' ' && sentence[index - 2] != '.' && sentence[index - 2] != ',')
               list->insertNode(decompWord, lineNumber);

            // setting loop control to false if we had read enough characters so we don't have an out of bounds error
            if (index >= sentence.length())
               moreExtraction = false;
         }
         lineNumber++;
      }

      // displaying and then deleting list
      list->displayWordList();
      list->~WordList();

      cout << endl;

      inFile.close();
   }
   
   return 0;
}

// In this function, decompose a sentence into words, one word at a time (we call this for every word)
//
// Inputs:   a string, a string passed by reference, an int
// Outputs:  an int
int extract(string sentence, string& temp, int index)
{
   temp = "";

   // when an invalid character is not encountered and we are with the bounds of the sentence, we append to a temp string using a loop.
   while (sentence[index] != ' ' && sentence[index] != '.' && sentence[index] != ',' && index < sentence.length())
   {
      temp.append(sentence, index, 1);
      index++;
   }
   // adding 1 to overcome whitespace/punctuation
   return index + 1;
}

// In this function, we opena  file and verify it opened correctly
//
// Inputs:   an ifstream object passed by reference
// Outputs:  none
void openFile(ifstream& inFile)
{
   // getting intial input
   string fileName, error = "Please";
   cout << error << " enter a file name (enter * to exit)" << endl;
   getline(cin, fileName);

   // if * is entered, exiting
   if (fileName == "*")
      exit(0);

   inFile.open(fileName);

   while (!inFile)
   {
      // printing error message and getting input again if error occurs
      error = "Error. Please";
      cout << error << " enter a file name (enter * to exit)" << endl;
      getline(cin, fileName);

      // if * is entered, exiting
      if (fileName == "*")
         exit(0);

      inFile.open(fileName);
   }
   cout << endl;
}