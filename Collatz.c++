// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------


int cycleLength(int i){
    assert(i > 0);
    int count = 1;
    int num = i;
    while (num > 1) {
        if ((num % 2) == 0)
            num = (num / 2);
        else{
            num = num + (num >> 1) + 1;
            count++;
        }
        count++;
    }
    assert(count > 0);
    return count;
}

int collatz_eval (int i, int j) {
    assert(i > 0 && j > 0);
    int maxLength = -1;
    int max, min;
    if(i > j){
        max = i;
        min = j;
    }
    else if(j > i){
        max = j;
        min = i;
    }
    else if(j == i)
        return cycleLength(i);
    int mid = (max / 2) + 1;
    int start;
    if(min < mid)
        start = mid;
    else
        start = min;
    for(int c = start; c <= max; c++){
        int temp = cycleLength(c);
        if(temp > maxLength)
            maxLength = temp;
    }
    return maxLength;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
