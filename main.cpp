//
//  main.cpp
//  Project 3
//
//  Created by Ricardo Gonzalez on 11/9/23.
//

#include <iostream>
#include "ContiguousSequence.h"
using namespace std;

void print_results(ContiguousSequence& cs) {
    
    cs.print_List();
    cs.print_entire_allocated_space();
    cout << "size is: " << cs.size() << endl;
    cout << "basic size is: " << cs.basicSize() << endl;
    cout << "start is: " << cs.get_start() << endl;
    cout << "end is: " << cs.get_end() << endl;
}

// Define a function that doubles an integer
int doubleValue(int x) {
    return 2 * x;
}

int main(int argc, const char * argv[]) {
    
    cout << "Initialize ContiguousSequence with default constructor: " << endl;
    ContiguousSequence csTest;
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 5 at 0: " << endl;
    csTest.insertAt(0, 5);
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 8 at 1: " << endl;
    csTest.insertAt(1, 8);
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 3 at 0: " << endl;
    csTest.insertAt(0, 3);
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 6 at 3: " << endl;
    csTest.insertAt(3, 6);
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 10 at 2 and 19 at 3 USING CASCADING: " << endl;
    csTest.insertAt(2, 10).insertAt(3, 19);
    print_results(csTest);
    cout << endl;
    
    cout << "******************************************************************" << endl << endl;
    
    cout << "TESTING find():" << endl;
    cout << "find(10): " << endl;
    cout << "Number 10 is at: " << csTest.find(10) << endl;
    csTest.print_List();
    csTest.print_entire_allocated_space();
    cout << endl;
    
    cout << "find(3): " << endl;
    cout << "Number 3 is at: " << csTest.find(3) << endl;
    csTest.print_List();
    csTest.print_entire_allocated_space();
    cout << endl;
    
    cout << "find(6): " << endl;
    cout << "Number 6 is at: " << csTest.find(6) << endl;
    csTest.print_List();
    csTest.print_entire_allocated_space();
    cout << endl;
    
    cout << "find(100): " << endl;
    cout << "Number 100 is at: " << csTest.find(100) << endl;
    csTest.print_List();
    csTest.print_entire_allocated_space();
    cout << endl;
    
    cout << "******************************************************************" << endl << endl;

    cout << "Inserting 9999 at -1: (invalid index)" << endl;
    csTest.insertAt(-1, 9999);
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 8888 at 8: (invalid index)" << endl;
    csTest.insertAt(8, 8888);
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 2 at 0: " << endl;
    csTest.insertAt(0, 2);
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 13 at 0: " << endl;
    csTest.insertAt(0, 13);
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 9 at 4: " << endl;
    csTest.insertAt(4, 9);
    print_results(csTest);
    cout << endl;
    
    cout << "Inserting 11 at 5: " << endl;
    csTest.insertAt(5, 11);
    print_results(csTest);
    cout << endl;
    
    
    cout << "Inserting 99 at 0: " << endl;
    csTest.insertAt(0, 99);
    print_results(csTest);
    cout << endl;
    
    cout << "******************************************************************" << endl << endl;
    
    cout << "APPLYING ITERATE WITH FUNCTION: f(x) = 2x" << endl << endl;
    csTest.iterate([](int x) { return x * 2; });
    print_results(csTest);
    cout << endl;
    
    cout << "******************************************************************" << endl << endl;
    
    cout << "TESTING [] OPERATORS" << endl << endl;

    cout << "Testing as r-value:" << endl;
    cout << "cs2[0] is: " << csTest[0] << endl;
    cout << "cs2[1] is: " << csTest[1] << endl;
    cout << "cs2[2] is: " << csTest[2] << endl;
    cout << "cs2[-1] is: " << csTest[-1] << endl;
    cout << "cs2[20] is: " << csTest[20] << endl;
    
    cout << "Testing as l-value:" << endl;
    cout << "csTest[0] = 100;" << endl;
    csTest[0] = 100;
    print_results(csTest);
    cout << endl;
    
    cout << "csTest[4] = " << csTest[4] << endl;
    print_results(csTest);
    cout << endl;

    cout << "******************************************************************" << endl << endl;
    
    
    cout << "NOW WE START REMOVING..." << endl << endl;
    
    cout << "Removing at 3: " << endl;
    csTest.removeAt(3);
    print_results(csTest);
    cout << endl;
    
    cout << "Removing at 0: " << endl;
    csTest.removeAt(0);
    print_results(csTest);
    cout << endl;
    
    cout << "Removing at 0 again: " << endl;
    csTest.removeAt(0);
    print_results(csTest);
    cout << endl;
    
    
    cout << "Removing at 7: (invalid index)" << endl;
    csTest.removeAt(7);
    print_results(csTest);
    cout << endl;
    
    cout << "Removing at 6: (invalid index)" << endl;
    csTest.removeAt(6);
    print_results(csTest);
    cout << endl;
    
    cout << "Removing at 2: (invalid index)" << endl;
    csTest.removeAt(2);
    print_results(csTest);
    cout << endl;
    
    cout << "Removing at 1: (invalid index)" << endl;
    csTest.removeAt(1);
    print_results(csTest);
    cout << endl;
    
    cout << "Removing at 0 using CASCADING until empty" << endl;
    csTest.removeAt(0).removeAt(0).removeAt(0).removeAt(0);
    print_results(csTest);
    cout << endl;
    
    cout << "List is now empty. Attempting to remove at 0. (invalid index)" << endl;
    csTest.removeAt(0);
    print_results(csTest);
    cout << endl;
    
    cout << "******************************************************************" << endl << endl;
    
    cout << "TESTING COPY CONSTRUCTOR" << endl;
    
    ContiguousSequence cs2;
    cs2.insertAt(0, 76);
    cs2.insertAt(1, 5);
    cs2.insertAt(2, 36);
    
    cout << "cs2 is:" << endl;
    print_results(cs2);
    cout << endl;
    
    
    ContiguousSequence copyCs(cs2);
    cout << "copyCs is:" << endl;
    print_results(copyCs);
    cout << endl;
    
    cout << "Inserting 999 to copyCs" << endl;
    copyCs.insertAt(3, 999);
    
    cout << "cs2 is still:" << endl;
    print_results(cs2);
    cout << endl;
    
    cout << "copyCs is now:" << endl;
    print_results(copyCs);
    cout << endl;
    
    cout << "******************************************************************" << endl << endl;
    
    cout << "TESTING ASSIGNMENT(=) CONSTRUCTOR" << endl;
    
    cout << "We initialize a new ContiguousSequence cs3" << endl;
    ContiguousSequence cs3;
    cout << "cs3 = cs2" << endl;
    cs3 = cs2;
    cout << "cs3 is:" << endl;
    print_results(cs3);
    
    cout << "******************************************************************" << endl << endl;
    cout << "We now test our program using assertions:" << endl;
    
    // Test for Constructors
    ContiguousSequence csDefault;
    assert(csDefault.size() == 0); // Expect the sequence to be empty

    ContiguousSequence csWithElement(5);
    assert(csWithElement[0] == 5 && csWithElement.size() == 1); // Expect sequence with one element

    ContiguousSequence csCopy(csWithElement);
    assert(csCopy[0] == 5 && csCopy.size() == 1); // Expect copied sequence to be same as original

    
    // Test for Insertion
    ContiguousSequence cs;
    cs.insertAt(0, 10); // Insert at the beginning
    assert(cs[0] == 10);

    cs.insertAt(1, 20); // Insert at the end
    assert(cs[1] == 20);

    cs.insertAt(1, 15); // Insert in the middle
    assert(cs[1] == 15 && cs[2] == 20);

    
    // Test for Deletion
    ContiguousSequence cs1;
    cs1.insertAt(0, 10);
    cs1.insertAt(1, 20);
    cs1.removeAt(0); // Remove first element
    assert(cs1[0] == 20 && cs1.size() == 1);

    cs1.removeAt(1); // Attempt to remove out-of-bounds
    assert(cs1.size() == 1); // Size should remain unchanged
    
    
    // Test for Access and Find
    ContiguousSequence cs5;
    cs5.insertAt(0, 10);
    assert(cs5[0] == 10);

    const ContiguousSequence csConst(cs5);
    assert(csConst[0] == 10); // Test const version of operator[]

    assert(cs5.find(10) == 0); // Element should be found
    assert(cs5.find(99) == -1); // Element should not be found

    
    //  Test for Iterate
    ContiguousSequence cs6;
    cs6.insertAt(0, 1);
    cs6.insertAt(1, 2);

    cs6.iterate([](int x) { return x * 2; }); // Double each element

    assert(cs6[0] == 2 && cs6[1] == 4);

    
    // Test for Assignment Operator
    ContiguousSequence cs4;
    cs4.insertAt(0, 10);
    ContiguousSequence cs7;
    cs7 = cs4; // Test assignment
    assert(cs7[0] == 10);

    cs7 = cs7; // Test self-assignment
    assert(cs7[0] == 10);
    
    return 0;
}

