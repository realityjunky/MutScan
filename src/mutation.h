#ifndef MUTATION_H
#define MUTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "read.h"
#include <vector>
#include "match.h"
#include <iostream>
#include <fstream>

using namespace std;

class Mutation{
public:
    Mutation(string name, string left, string center, string right);

    //search this mutation in a read, and return the matchment info
    //by default, Q20 is required, and distance should be <=2
    //return NULL if not found
    Match* searchInRead(Read* r, int distanceReq = 2, int qualReq=20);
    static vector<Mutation> parseFile(string filename);
    static vector<Mutation> parseBuiltIn();
    void print();
    void printHtml(ofstream& file);

public:
    string mLeft;
    string mCenter;
    string mRight;
    string mPattern;
    string mName;

    int mShift;
};


#endif
