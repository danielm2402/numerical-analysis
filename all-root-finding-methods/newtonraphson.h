#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

#include<functional>
#include<iomanip>
#include<iostream>
#include <string>
#include<cmath>

using std::function;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;

struct resultado_newRap{
  bool encontrada;
  double raiz;
  int iteraciones;
};

class newtonraphson{
public:
	newtonraphson(
	   function<double(double)> p_func,
	   function<double(double)> p_dfunc,
	   string p_sfunc
	   ):
		func(p_func),
		dfunc(p_dfunc),
		sfunc(p_sfunc){
		}
	
	double f(double x){
		return func(x);
	}
		
	double df(double x){
		return dfunc(x);
	}
	string str(){
		return sfunc;
	}
				
  resultado_newRap encontrarRaiz(double p0,
                     int max_iter, 
                     double tolerancia){

    resultado_newRap sol;
    
    sol.encontrada = false;
    int iter = 1;
  //imprimir tabla
  
  cout
    <<setw(10)
    <<"p"
    <<setw(10)
    <<"f(p)"
    <<endl;
    
    cout
    << setw(10)
    << p0
    << setw(10)
    << f(p0)
    <<endl;
    
	
	double p = 0.0;
					
			//implementacion del metodo
	while(iter <= max_iter){
		
    p = p0 -(f(p0)/df(p0));
		double er = fabs((p - p0)/p);
    
    cout
      << setw(10)
      << p
      << setw(10)
      << f(p0)
      << setw(15)
      <<er
      <<endl;
						
		if(fabs(er) < tolerancia){
			sol.raiz = p;
      sol.encontrada = true;
      sol.iteraciones = iter;
			return sol;
		}
			p0 = p;
			iter ++;
		}
					
			return sol;
  }
					
					
private:
	function<double(double)> func;
	function<double(double)> dfunc;
	string sfunc;
						
};

#endif
