/*****************************************************************************
                  Workshop - #1 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
    Email : hkarimi9@myseneca.ca
    Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
//main
#include <iostream>
#include "io.h"
#include "graph.h"
const int MAX_NO_OF_SAMPLES = 20;
const int GRAPH_WIDTH = 65;

using namespace std;
using namespace seneca;
// prints samples error message
void samplesFirst() {
    cout << "Number of Samples must be set first!" << endl;
}
// SeneGraph program
int main() {
    int noOfSamples = 0;
    int samples[MAX_NO_OF_SAMPLES] = { 0 };
    bool done = false;
    labelLine(33, "Welcome to SeneGraph");
    while (!done) {
        switch (menu(noOfSamples)) {
        case 1:
            cout << "Enter number of available samples: ";
            noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
            break;
        case 2:
            if (noOfSamples == 0) {
                samplesFirst();
            }
            else {
                cout << "Please enter the sample values: " << endl;
                getSamples(samples, noOfSamples);
            }
            break;
        case 3:
            if (noOfSamples == 0) {
                samplesFirst();
            }
            else if (samples[0] == 0) {
                cout << "Samples missing. Please enter the sample values!" << endl;
            }
            else {
                printGraph(samples, noOfSamples, " SeneGraph ");
            }
            break;
        case 0:
            cout << "Thanks for using SeneGraph" << endl;
            done = true;
        }
    }
    return 0;
}



