//
//  Solver.h
//  EEAnalysis
//
//  Created by ejensen4 on 12/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef EEAnalysis_Solver_h
#define EEAnalysis_Solver_h
#include<iostream>
#include<cmath>
#include "Sources.h"
#include "fileprocesses.h"
#define PI 3.141592

using namespace std;


double Source(double t)
{double *num = new double[20];
    filein(num);
    
    double freq = num[4];
    
    //return 1.0*sin(freq*t);
   // return 0.0;
    // return UnitStep(t,100.0);
    
      return SquareWave(t, freq);    
}


void init(double *L,double *C,double *R,double *R2)
{
    double *num = new double[20];
    
    filein(num);
    
    *L = num[0];
    *C = num[1];
    *R = num[2];
    *R2= num[3];
    
    
    
}

void sum(double V,double t,double h,double *G)
{
    double sum =0.0;
    
    sum = V*h;
    
    *G = *G+sum;
}






double function(double V,double t, double h,double *G)
{
    double output,L,C,R,R2,Vs;
    
    init(&L, &C, &R, &R2);
    
    Vs = Source(t);
    
    sum(V,t,h,G);

    // output = (1.0/C)*( (-1.0/double(L))*(*G) -(V/R2) - ((V-Vs)/R));
    output = (1/C)*(-1*(V/R2) - ((V-Vs)/R));
    
    return output;
}




void euler(double *OUTPUT,int N, double h,double *time)
{
    
    double t = time[0];
    double G =0.0;
    
    
    for(int i =0; i<N; i++)
    {
        
        OUTPUT[i+1] = OUTPUT[i] + h*function(OUTPUT[i],t,h,&G);
        t = t+h;
        time[i+1] = t;
    }
    
}


void RK2(double *OUTPUT,int N, double h,double *time)
{
    
    double t = time[0];
    double G =0.0,Ghold=0.0;
    double k1 =0.0; double k2 = 0.0;
    
    
    
    for(int i =0; i<N; i++)
    {
        Ghold = G;
        k1 = function(OUTPUT[i], t, h, &G);
        G = Ghold;
        k2 = function(OUTPUT[i]+0.6666666*h*k1, t+0.666666*h, h, &G);
        
        OUTPUT[i+1] = OUTPUT[i] + h*(0.25*k1 + 0.75*k2);
        
        t = t+h;
        time[i+1] = t;
    }

    
    
    
    
}







#endif









