#ifndef UNIQUEVECTOR_H
#define UNIQUEVECTOR_H

template<typename T>
class UniqueVector{
   public:
       //Constructor that Initializes the data members
       UniqueVector(): vectorCapacity(3), vectorSize(0){
           anArray = new T[vectorCapacity];
       }
       //Destructor that deletes the memory allocated to the array
       ~UniqueVector(){
           delete []anArray;
       }
       // Returns the size of the space currently allocated for the vector.
       unsigned int capacity() const{
           return vectorCapacity;
       }
       // Returns the current number of elements in the vector.
       unsigned int size() const{
           return vectorSize;
       }
       // If the vector contains zero elements, returns true; otherwise, returns false
       bool empty();
       // If the vector contains data, returns true; otherwise, returns false.
       bool contains(const T& data);
       // If pos is a valid position, retrieves the element in position pos in the array,
       // stores it in data, and returns true;otherwise, returns false.
       bool at(unsigned int pos, T& data);
       // If the vector does not already contain data, adds a new element, data, to the back of the vector, increases the container size by one, and returns true; otherwise, returns false.
       // If the underlying array is full, creates a new array with double the capacity and copies all of the elements over
       bool insert(const T& data);
       // If the vector does not already contain data, adds a new element, data, to the vector at position pos,increases the container size by one, returns true; otherwise, returns false.
       // If the underlying array is full, creates a new array with double the capacity and copies all of the elements over
       bool insert(const T& data, unsigned int pos);
       // If the vector does not already contain data, adds a new element, data, to the front of the vector,increases the container size by one, and returns true;otherwise, returns false.
       // If the underlying array is full, creates a new array with double the capacity and copies all of the elements over.
       bool push_front(const T& data);
       // If the vector contains data, removes data from the vector, reduces the container size by one, leaves the capacity unchanged,
       // And returns true; otherwise, returns false.
       bool remove(const T& data);
       // If pos is a valid position, removes the element in position pos, stores it in data,
       // Reduces the container size by one, leaves the capacity unchanged, and returns true; otherwise, returns false
       bool remove(unsigned int pos, T& data);
       // If the vector is not empty, removes the last element in the vector, stores it in data, reduces the container size by one
       // Leaves the capacity unchanged, and returns true; otherwise, returns false.
       bool pop_back(T& data);
       // Empties the vector of its elements and resets the capacity to 3
       void clear();
       // Overload	operator == If the vector on the left hand side has the same elements in the same order
       // As the vector on the right hand side, returns true; otherwise, returns false.
       template<typename X>
       friend bool operator== (const UniqueVector<X>& leftSide, const UniqueVector<X>& rightSide);

    private:
      T* anArray;
      unsigned int vectorCapacity;
      unsigned int vectorSize;

      void resize (unsigned int newCapacity);
};

#include "UniqueVector.cpp"
#endif
