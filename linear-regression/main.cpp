#include <iostream>
#include <vector>
#include "linearRegression.h"

using std::cout;
using std::endl;
using std::vector;

int main() {
   vector<point>datos={
           {1.0, 0.5},
           {2.0, 2.5},
           {3.0, 2.0},
           {4.0, 4.0},
           {5.0, 3.5},
           {6.0, 6.0},
           {7.0, 5.5},
   };
   regresion_lineal r1(datos);
   result r =r1.calculate();
   cout<<"Regression line: y="<<r.b1<<"x "<< ((r.b0>0)?"+":"")<<r.b0<<endl;
   cout<<"standard deviation: "<<r.sy<<endl;
   cout<<"Approximation error: "<<r.syx<<endl;
   if(r.syx<r.sy){
       cout<<"The approximation is acceptable";
   }else{
       cout<<"The approximation is not acceptable";
   }
    return 0;
}
