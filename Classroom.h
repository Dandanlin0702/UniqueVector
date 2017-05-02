#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "UniqueVector.h"

using namespace std;

class Classroom{
   public:
       // If a student named name is not already on the classroom roster, adds a new student named name to the classroom roster
       // And returns true; otherwise, returns false.
       bool addStudent(const string& name);

       // If a student named name is on the classroom roster, removes the student named name from the classroom roster
       // And returns true; otherwise, returns false.
       bool removeStudent(const string& name);

       // If a student named name is on the classroom roster, returns true; otherwise, returns false.
       bool containsStudent(const string& name);

       // Returns a string containing the names of the students in the classroom, separated by commas.
       string listAllStudents();

       // Removes and returns the student whose name comes lexicographically first on the classroom roster.
       string removeAlphabeticallyFirst();

       // Removes and returns the student whose name comes lexicographically last on the classroom roster.
       string removeAlphabeticallyLast();

       // Adds all of the student names on otherClass’ roster onto the roster of the Classroom
       // Calling this function and leaves otherClass unchanged.
       void combineClasses(Classroom& otherClass);

    private:
      UniqueVector<string> classRoster;
};

#endif
