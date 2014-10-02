//
//  Sources.h
//  EEAnalysis
//
//  Created by ejensen4 on 12/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef EEAnalysis_Sources_h
#define EEAnalysis_Sources_h
#include<iostream>
#include<cmath>
#define PI 3.141592

using namespace std;



double SquareWave(double t, double freq)
{
    
    
    
    double T = 1/freq;
    
    if ( int(t)%int(T)<(T/2)) 
    {
        //cout << 1<<endl;
        return 1.0;
    }
    else if ( int(t)%int(T)>=(T/2) ) 
    {
        //cout <<-1<<endl;
        return -1.0;
    }
    else 
        return 0.0;
    
    
}




double UnitStep(double t,double t0)
{
    if(t<t0)
    {return 0.0;
    }
    else
        return 1.0;
}



#endif
