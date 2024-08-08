//
//  ContiguousSequence.hpp
//  Project 3
//
//  Created by Ricardo Gonzalez on 11/9/23.
//

#ifndef ContiguousSequence_hpp
#define ContiguousSequence_hpp

#include <stdio.h>
#include <iostream>

using namespace std;;

#endif


class ContiguousSequence {
private:
    int* sequence;
    int capacity;
    int start, end;

    void grow();
    void fill_gap(int pivot);
    void shift_left(int pivot);
    void shift_right(int pivot);

public:
    ContiguousSequence();
    ContiguousSequence(const ContiguousSequence& other);
    ContiguousSequence(int initialElement);
    ~ContiguousSequence();

    int basicSize() const;
    int size() const;
    int& operator[](int index);
    const int& operator[](int index) const;
    ContiguousSequence& insertAt(int index, int value);
    int find(int value) const;
    ContiguousSequence& removeAt(int index);
    ContiguousSequence& iterate(int (*fn)(int));
    ContiguousSequence& operator=(const ContiguousSequence& other);
    
    /*
     * The following functions are for debugging purposes
     */
    int get_start() {
        return start;
    }
    
    int get_end() {
        return end;
    }
    
    void print_entire_allocated_space() {
        cout << "Entire allocated memory space:" << endl;
        cout << "(";
        for (int i = 0; i < capacity; i++) {
            cout << sequence[i];
            if (i < capacity - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }

    void print_List() {
        cout << "List:" << endl;
        cout << "(";
        for (int i = start; i <= end; i++) {
            cout << sequence[i];
            if (i < end) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
        
        
    }

};
