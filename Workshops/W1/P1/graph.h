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
//Graph.h
#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H

namespace seneca {
    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples); 
    // Prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max);
    // Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70.
    int findMax(int samples[], int noOfSamples);
    // Prints a graph comparing the sample values visually 
    void printGraph(int samples[], int noOfSamples, const char* label);
    
}

#endif // SENECA_GRAPH_H
