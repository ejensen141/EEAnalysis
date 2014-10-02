//
//  fileprocesses.h
//  EEAnalysis
//
//  Created by ejensen4 on 12/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef EEAnalysis_fileprocesses_h
#define EEAnalysis_fileprocesses_h
#include <fstream>
#include<iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
#include <cstdlib>
using namespace std;


void filein(double *num)
{
    

ifstream indata;
// double num[100000]; 
indata.open("input.txt"); 
if(!indata) { 
    cerr << "Error: file could not be opened" << endl;
    exit(1);
    }
    
    
    int i =0;
    
    int endoffile=0;
    
    while ( !indata.eof() ) 
    { 
        indata >> num[i]; 
        i++;
        
    }
    indata.close();
    
    endoffile = i;

    
    
    
}

void writegnuplot(int dummy)
{
    ofstream fout2;
    fout2.open("plot");
    
    fout2<<"set term pdf \n";
    fout2<<"set output '"<<dummy<<".pdf' \n";
    fout2<< "set ylabel \" V (mv) \"     \n set xlabel \" T (ms) \"  \n ";
    fout2<< "plot \"plot.txt\" with lines, \"plot2.txt\" with lines";
    fout2.close();
}

#endif
