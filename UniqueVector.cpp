/****************************************
Filename: UniqueVector.cpp
Author: Dandan Lin
*****************************************/

#ifndef UNIQUEVECTOR_CPP
#define UNIQUEVECTOR_CPP

#include "UniqueVector.h"
#include <iostream>
using namespace std;

template<typename T>
bool UniqueVector<T>::empty() {
   return (vectorSize == 0);
}

template<typename T>
bool UniqueVector<T>::contains(const T& data) {
   for (unsigned int i = 0; i < vectorSize; i++) {
      if (anArray[i] == data) {
         return true;
      }
   }
   return false;
}

template<typename T>
bool UniqueVector<T>::at(unsigned int pos, T& data) {
   // Check if position pos is a valid position
   if (pos >= 0 && pos < vectorSize) {
      data = anArray[pos];
      return true;
   }
   return false;
}

template<typename T>
bool UniqueVector<T>::insert(const T& data) {
   return insert(data, size());
}

template<typename T>
bool UniqueVector<T>::insert(const T& data, unsigned int pos) {
   // Return false when the data already exists or the pos is not a valid position
   if (contains(data) || pos > size() || pos < 0) {
      return false;
   }
   if (vectorSize == vectorCapacity) {
      resize(vectorCapacity * 2);
   }
   for (unsigned int i = vectorSize; i > pos; i--) {
      anArray[i] = anArray[i-1];
   }
   anArray[pos] = data;
   vectorSize++;

   return true;
}

template<typename T>
bool UniqueVector<T>::push_front(const T& data) {
   return insert(data, 0);
}

template<typename T>
bool UniqueVector<T>::remove(const T& data) {
   if (contains(data)) {
      int tempPosition = 0;
      //  Use for loop to located the data's position and store the position in tempPosition
      for (unsigned int i = 0; i < vectorSize; i++) {
         if (anArray[i] == data) {
            tempPosition = i;
         }
      }
      // Shift the elements one position down from tempPosition and reduce the vectorSize
      for (unsigned int i = tempPosition; i < vectorSize; i++) {
         anArray[i] = anArray[i + 1];
      }

      vectorSize--;
      return true;
   }

   return false;
}

template<typename T>
bool UniqueVector<T>::remove(unsigned int pos, T& data) {
   // When the position pos is valid stores the info in position pos in data and remove
   if (pos >= 0 && pos < vectorSize) {
      data = anArray[pos];
      for (unsigned int i = pos; i < vectorSize; i++) {
         anArray[i] = anArray[i + 1];
      }
      vectorSize--;
      return true;
   }
   return false;
}

template<typename T>
bool UniqueVector<T>::pop_back(T& data) {
   if (!empty()) {
      data = anArray[vectorSize - 1];
      vectorSize--;
      return true;
   }
   return false;
}

template<typename T>
void UniqueVector<T>::clear() {
   vectorSize = 0;
   vectorCapacity = 3;
   anArray = new T[3];
}

template<typename X>
bool operator== (const UniqueVector<X>& leftSide, const UniqueVector<X>& rightSide) {
   if (leftSide.vectorSize != rightSide.vectorSize || leftSide.vectorCapacity != rightSide.vectorCapacity) {
      return false;
   }

   for (unsigned int i = 0; i < leftSide.vectorSize; i++) {
      if (leftSide.anArray[i] != rightSide.anArray[i]) {
         return false;
      }
   }

   return true;
}

template<class T>
void UniqueVector<T>::resize (unsigned int newCapacity) {
   vectorCapacity = newCapacity;
   T* oldArray = anArray;
   anArray = new T[vectorCapacity];
   // Copies the elements over
   for (unsigned int i = 0; i < vectorSize; i++) {
      anArray[i] = oldArray[i];
   }
   delete[] oldArray;
}

#endif
