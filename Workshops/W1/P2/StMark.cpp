/*****************************************************************************
                  Workshop - #1 (Part - 2)>
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#include "StMark.h"
#include "file.h"
#include "io.h"
#include "graph.h"
#include <iostream>

using namespace std;
namespace seneca {
    // Swaps two StMark objects.
    void manualSwap(StMark& a, StMark& b) {
        StMark temp = a;
        a = b;
        b = temp;
    }
    // Sorts an array of StMark objects in descending order based on their marks.
    void sortStudents(StMark* students, int count) {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (students[j].mark < students[j + 1].mark) {
                    manualSwap(students[j], students[j + 1]);
                }
            }
        }
    }
    // Generates and prints a report of student marks.
    bool printReport(const char* filename) {
        if (!openFile(filename)) {
            return false;
        }

        StMark marks[MAX_NO_RECS];
        // Read marks from file and sort them
        int count = readMarks(marks);
        sortStudents(marks, count);
        // Initialize array to count students in each ten-point mark range
        int rangeCounts[10] = { 0 }; 
        for (int i = 0; i < count; ++i) {
            int rangeIndex = (marks[i].mark - 1) / 10;
            rangeCounts[rangeIndex]++;
        }
        // Find the maximum count for graph scaling
        int maxCount = findMax(rangeCounts, 10);
        cout << "+---Students' mark distribution\n";
        for (int i = 9; i >= 0; --i) {
            // Correct range label
            int label = (i + 1) * 10; 
            // Print the range label directly here
            printInt(label, 3);      
            cout << " ";
            // Call printBar for the bar and count
            printBar(rangeCounts[i], maxCount); 
        }
        cout << "+---------------------------------"
            "--------------------------------------------+\n";

        for (int i = 0; i < count; ++i) {
            // Use printInt with width of 3 for student numbers
            printInt(i + 1, 3);      
            cout << ": [";
            // Use printInt with width of 3 for marks
            printInt(marks[i].mark, 3); 
            cout << "] " << marks[i].name << " " << marks[i].surname << "\n";
        }
        cout << "----------------------------------------\n";

        closeFile();
        return true;
    }
}