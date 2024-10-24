//#include "DynamicArr.h"
//#include <iostream>
//
//// Resizes the dynamic array to double its capacity
//void DynamicArray::resize()
//{
//    this->capacity = this->capacity * 2;
//    TElem* array = new TElem[this->capacity];
//    for (int i = 0; i < this->size; i++) {
//        array[i] = this->elements[i];
//    }
//    delete[] this->elements;
//    this->elements = array;
//}
//
//
//// Constructor initializes the dynamic array with a given capacity
//DynamicArray::DynamicArray(int capacity)
//{
//    this->capacity = capacity;
//    this->size = 0;
//    this->elements = new TElem[capacity];
//}
//
//
//// Copy constructor creates a new dynamic array as a copy of another dynamic array
//DynamicArray::DynamicArray(const DynamicArray& arr)
//{
//    this->capacity = arr.capacity;
//    this->size = arr.size;
//    this->elements = new TElem[this->capacity];
//    for (int i = 0; i < arr.size; i++)
//        this->elements[i] = arr.elements[i];
//}
//
//
//// Assignment operator assigns the contents of one dynamic array to another
//DynamicArray& DynamicArray::operator=(const DynamicArray& arr)
//{
//    delete[] elements;
//    this->capacity = arr.capacity;
//    this->size = arr.size;
//    this->elements = new TElem[this->capacity];
//    for (int i = 0; i < arr.size; i++)
//        this->elements[i] = arr.elements[i];
//    return *this;
//}
//
//// Destructor deallocates memory used by the dynamic array
//DynamicArray::~DynamicArray()
//{
//    delete[] this->elements;
//}
//
//// Adds an element to the end of the dynamic array
//void DynamicArray::add(TElem element)
//{
//    if (this->size == this->capacity)
//    {
//        this->resize();
//    }
//    this->elements[this->size] = element;
//    this->size++;
//}
//
//// Removes an element at a specified index from the dynamic array
//void DynamicArray::remove(int index)
//{
//    for (int i = index; i < this->size - 1; i++)
//    {
//        this->elements[i] = this->elements[i + 1];
//    }
//    this->size--;
//}
//
//// Updates an element at a specified index in the dynamic array
//void DynamicArray::update(TElem element, int index)
//{
//    this->elements[index] = element;
//}
//
//// Increases the quantity of an element at a specified index
//void DynamicArray::inc(int index)
//{
//
//     this->elements[index].inc();
//
//
//}
//
//// Decreases the quantity of an element at a specified index
//void DynamicArray::dec(int index) {
//
//    this -> elements[index].dec();
//}
//
//// Returns the current size of the dynamic array
//int DynamicArray::get_size()
//{
//    return this->size;
//}
//
//// Returns the current capacity of the dynamic array
//int DynamicArray::get_capacity()
//{
//    return this->capacity;
//}
//
//// Returns the element at a specified index in the dynamic array
//TElem DynamicArray::get_elem(int index)
//{
//    return this->elements[index];
//}
//
//
//// Returns a pointer to the underlying array of elements
//TElem* DynamicArray::get_elements()
//{
//    return this->elements;
//}
//
