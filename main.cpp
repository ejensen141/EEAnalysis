//
//  main.cpp
//  EEAnalysis
//
//  Created by ejensen4 on 12/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Solver.h"
#include <fstream>
#include <cmath>
#include "fileprocesses.h"


using namespace std;

int main (int argc, const char * argv[])
{
    ofstream fout;
    ofstream fout2;
    ofstream infile;
    
    int dummy =2;
    double freq = 10.0; //in hz
    double millifreq=0.0;

    // do{
    
   writegnuplot(dummy);
    dummy++;
    
   
    fout.open("plot.txt");
    fout2.open("plot2.txt");
    infile.open("input.txt");
    
    double L = 10.0;        //everything in milli
    double C = 10.0;
    double R = 10.0;
    double R2= 1000000.0;
    
    // in hz   lower limit 1 hz
    millifreq = freq/1000.0;    //  for millisec
    
    infile<<L<<endl;
    infile<<C<<endl;
    infile<<R<<endl;
    infile<<R2<<endl;
    infile<<millifreq<<endl;
    
    infile.close();
    
    double totaltime;   // in millisec 
    totaltime = 1000;
    
    int N=10000;
    
    
     double h = totaltime/double(N);
    cout<<h<<endl;
    double *time = new double[N];
    double *V = new double[N];
    
    V[0] = 0.0;
    
    
      RK2(V, N, h, time);
    
    // euler(V, N, h, time);
    int i =0;
    
    do{
        fout<<time[i]<<"   "<<V[i]<<endl;
        fout2<<time[i]<<"   "<<SquareWave(time[i],millifreq)<<endl;
        i++;
    }while(i<N);    
    
        fout.close();
        fout2.close();
    
      system("gnuplot plot");
    
    
      freq = freq +10.0;
 //   }while(dummy<10);
        
    return 0;
}

