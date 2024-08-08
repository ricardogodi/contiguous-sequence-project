/*
 * Author: Ricardo Gonzalez
 *
 * The ContiguousSequence class is designed to store a sequence of integers
 * in a dynamically allocated, contiguous block of memory. This class
 * combines the direct element access benefits of arrays with the dynamic
 * resizing capability of linked lists. The sequence supports insertion,
 * deletion, and access operations, and automatically resizes as needed.
 *
 * Nov 9 2023
 *
 */

#include "ContiguousSequence.h"
#include <iostream>

using namespace std;

/*
 * Doubles the capacity of the internal array used to store the sequence's elements.
 */
void ContiguousSequence::grow() {
  
    int new_capacity = capacity * 2;   // Calculate the new capacity as double the current capacity
    int* new_seq = new int[new_capacity];
    
    // Calculate the start index in the new array to center the elements
    int new_seq_start_index = capacity / 2;
    int num_of_els_being_copied = capacity;

    // Copy the elements from the old array to the new array, starting from
    // the calculated start index in the new array
    for (int i = 0; i < num_of_els_being_copied; i++) {
        new_seq[new_seq_start_index + i] = sequence[start + i];
    }
    delete[] sequence;   // Release the memory allocated for the old array
   
    sequence = new_seq;    
    // Update instance variables
    start = new_seq_start_index;
    end = new_seq_start_index + num_of_els_being_copied - 1;
    capacity = new_capacity;
}

/*
 * Default Constructor
 */
ContiguousSequence::ContiguousSequence() {
    sequence = new int[8];
    capacity = 8;
    start = 3;
    end = 2;
}

/*
 * Copy Constructor
 */
ContiguousSequence::ContiguousSequence(const ContiguousSequence& other) {
    // Initialize with the same capacity as 'other'
    capacity = other.basicSize();
    // Allocate new memory
    sequence = new int[capacity];
    
    // Copy start and end from other. This ensures both objects will be exactly the same.
    start = other.start;
    end = other.end;
    
    // Directly copy the elements from 'other'
    for(int i = start; i <= end; i++) {
        sequence[i] = other.sequence[i];
    }
}

/*
 * Constructor that takes one first element
 */
ContiguousSequence::ContiguousSequence(int initialElement) {
    sequence = new int[8];
    capacity = 8;
    start = 3;
    end = 2;
    
    insertAt(0, initialElement); // At the beginning we must insert at 0
}

/*
 * Returns the capacity of the current array
 */
int ContiguousSequence::basicSize() const {
    return capacity;
}

/*
 * Returns the number elements in the sequence
 */
int ContiguousSequence::size() const {
    return end - start + 1;
}

/*
 * Provides modifiable access to elements in the sequence.
 */
int& ContiguousSequence::operator[](int index) {
    if (index < 0 || index >= size()) {
        cout << "Index out of bounds. No action taken" << endl;
    }
    return sequence[start + index];
}

/*
 *  Provides read-only access to elements in the sequence
 */
const int& ContiguousSequence::operator[](int index) const {
    if (index < 0 || index >= size()) {
        cout << "Index out of bounds. No action taken" << endl;
    }
    return sequence[start + index];
}

/*
 * Helper function to shift elements left
 */
void ContiguousSequence::shift_left(int pivot) {
    for (int i = start; i <= pivot; i++) {
        sequence[i - 1] = sequence[i];
    }
}

/*
 * Helper function to shift elements right
 */
void ContiguousSequence::shift_right(int pivot) {
    for (int i = end; i >= pivot; i--) {
        sequence[i + 1] = sequence[i];
    }
}

/*
 * Inserts a given value into the sequence at the specified index.
 */
ContiguousSequence& ContiguousSequence::insertAt(int index, int value) {
    
    if (index < 0 || index > size()) {
        cout << "Index out of bounds, no action taken." << endl;
        return *this;
    }
    
    if (size() == capacity) {  // Our allocated memory is full, we must double its size
        grow();
    }
    
    if (index == 0) { // User wants to add to the beginning
        
        // Check for space first
        if (start == 0) { // There is no room to the left
            // Then shift to the right. We are guaranteed there is space.
            shift_right(0);
            end++;
        } else { // There is room to the left
            start--;
        }
        
        index = 0;
        
    } else if (index == size()) { // User wants to add to the end (AFTER THE LAST OCCUPIED SPOT)
        
        if (end == capacity - 1) { // There is no room to the right
            // Then shift to the left. We are guaranteed there is space.
            shift_left(capacity - 1);
            start--;
        } else { // There is room to the right
            end++;
        }
        
        index = size() - 1;

    } else { // User wants to add in the middle OR at the last occupied spot
        
        if (end == capacity - 1) { // There is no room to the right
            // Then shift to the left. We are guaranteed there is space.
            shift_left(start + index);
            start--;
        } else { // There is room to the right
            // Shift right
            shift_right(start + index);
            end++;
        }
    }
    
    sequence[start + index] = value;
    return *this;
}

/*
 * Searches for the first occurrence of a specified value within the sequence
 */
int ContiguousSequence::find(int value) const {
    
    for (int i = start; i <= end; i++) {
        if (sequence[i] == value) { // Check if the current element matches 'value'
            return i - start;
        }
    }
    return -1; // Return -1 if 'value' is not found in the sequence
}

/*
 * This helper function shifts elements from left to right
 */
void ContiguousSequence::fill_gap(int pivot) {
    for (int i = start + pivot; i <= end; i++) {
            sequence[i] = sequence[i + 1];
        } // Note: This will leave a duplicate of the last element at the end
          // which will be ignored in future operations due to 'end' being decremented
          // after removal.
}

/*
 * This function removes an element from a specified index
 */
ContiguousSequence& ContiguousSequence::removeAt(int index) {
    
    if (index < 0 || index >= size()) {
        cout << "Index out of bounds, no action taken." << endl;
        return *this;
    }
    
    if (index == 0) { // User wants to remove from the beginning
        sequence[start] = 0;
        start++; // Note that we don't bother actually modifying the array
    } else if (index == size() - 1) { // User wants to remove from the end
        sequence[end] = 0;
        end--; // Note that we don't bother actually modifying the array
    } else { // User wants to remove from the middle
        fill_gap(index);
        end--;
    }
    
    return *this;
}

/*
 * This function applies a given function to each element in the sequence.
 */
ContiguousSequence& ContiguousSequence::iterate(int (*fn)(int)) {
    for (int i = start; i <= end; i++) {
        sequence[i] = fn(sequence[i]);
    }
    return *this;
}

/*
 * Assigment operator: assigns the content of 'other' to this instance.
 */
ContiguousSequence& ContiguousSequence::operator=(const ContiguousSequence& other) {
    
    if (this != &other) { // Protect against self-assignment

        delete[] sequence; // Release current memory resources

        // Copy capacity, start, and end from 'other'
        capacity = other.basicSize();
        start = other.start;
        end = other.end;

        // Allocate new memory and copy the elements from 'other'
        sequence = new int[capacity];
        for (int i = start; i <= end; i++) {
            sequence[i] = other.sequence[i];
        }
    }
    return *this; // Return a reference to the current object
}

/*
 * Destructor: Deallocates the dynamic memory used by the instance to avoid memory leaks.
 */
ContiguousSequence::~ContiguousSequence() {
    delete[] sequence; // Free the dynamically allocated memory
    sequence = nullptr; // Set the pointer to nullptr to avoid dangling pointer
}
