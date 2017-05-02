/****************************************
Filename: UniqueVector.cpp
Author: Dandan Lin
*****************************************/


#ifndef CLASSROOM_CPP
#define CLASSROOM_CPP

#include "Classroom.h"
#include <iostream>
#include <string>

using namespace std;

bool Classroom::addStudent(const string& name){
   if (classRoster.contains(name) == false){
      classRoster.insert(name);
      return true;
   }
   else{
      return false;
   }
}

bool Classroom::removeStudent(const string& name){
   if (classRoster.contains(name) == true){
      classRoster.remove(name);
      return true;
   }
   else{
      return false;
   }
}

bool Classroom::containsStudent(const string& name){
   return (classRoster.contains(name));
}

string Classroom::listAllStudents(){
   if (classRoster.empty()) {
      return "";
   }

   string studentNames = "", currentStudent = "";
   for (unsigned int i = 0; i < classRoster.size(); i++){
      classRoster.at(i, currentStudent);
      // Append the student into the studentNames string separated by commas
      if (currentStudent != ""){
         // When currentStudent holds the last studnet's info do not append the comma
         if (i == classRoster.size() - 1){
            studentNames += currentStudent;
         }
         else{
            studentNames += currentStudent + ",";
         }
         currentStudent = "";
      }
   }
   return studentNames;
}

string Classroom::removeAlphabeticallyFirst(){
   if (classRoster.empty()) {
      return "";
   }

   string alphabeticallyFirst, names;
   classRoster.at(0, alphabeticallyFirst);
   // Use a for loop to find and Store the AlphabeticallyFirst student in variable AlphabeticallyFirst
   for (unsigned int i = 1; i < classRoster.size(); i++){
      classRoster.at(i, names);
      if (names < alphabeticallyFirst){
         alphabeticallyFirst = names;
      }
   }
   // Remove the student who is the AlphabeticallyFirst
   classRoster.remove(alphabeticallyFirst);
   return alphabeticallyFirst;
}

string Classroom::removeAlphabeticallyLast(){
   if (classRoster.empty()) {
      return "";
   }

   string alphabeticallyLast, names;
   classRoster.at(0, alphabeticallyLast);
   // Use a for loop to find and Store the AlphabeticallyFirst student in AlphabeticallyLast
   for (unsigned int i = 1; i < classRoster.size(); i++){
      classRoster.at(i, names);
      if (names > alphabeticallyLast){
         alphabeticallyLast = names;
      }
   }
   // Remove the student who is in the AlphabeticallyLast
   classRoster.remove(alphabeticallyLast);
   return alphabeticallyLast;
}

void Classroom::combineClasses(Classroom& otherClass){
   string newStudent;
   for (unsigned int i = 0; i < sizeof(otherClass) ; i++){
      for (unsigned int j = 0; j < classRoster.size(); j++){
         otherClass.classRoster.at(i, newStudent);
         classRoster.insert(newStudent, classRoster.size()+j);
      }
   }
}

#endif
