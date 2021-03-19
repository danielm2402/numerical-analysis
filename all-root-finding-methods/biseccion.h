#ifndef BISECCION_H
#define BISECCION_H
#include <cmath>
#include <functional>
#include <string>

using std::function;
using std::string;

struct resultado_bis{
  bool encontrada;
  double raiz;
  int iteraciones;
};

class biseccion {
public:
  biseccion(
            function<double(double)> p_func,
            string p_str
          ):func(p_func),str_func(p_str) {
  }
  
  string str(){
	  return str_func;
  }
  resultado_bis raiz(double a, 
            double b, 
            int max_iter, 
            double tolerancia) {
    
	  resultado_bis sol_bis;
    sol_bis.encontrada = false;
    int iter = 1;
    //generar tabla
    cout
      <<setw(10)
      <<"p"
      <<setw(10)
      <<"f(p)"
      <<setw(15)
      <<"Er"
      <<endl;
    
    cout
      << setw(10)
      << a
      << setw(10)
      << f(a)
      <<endl;
	  
	  double x_anterior = (a + b)/2;
	  
	  if((f(a) * f(x_anterior)) > 0.0){
		  a = x_anterior;
	  }else{
		  b = x_anterior;
	  }
	  
	  while (iter <= max_iter){
		  
		  double x_nueva = (a + b)/2;
		  double er = fabs((x_nueva - x_anterior) / x_nueva);
      
      cout
        << setw(10)
        << x_nueva
        << setw(10)
        << f(a)
        <<setw(15)
        <<er
        <<endl;
		  
		  if(er < tolerancia){
			  sol_bis.encontrada = true;
        sol_bis.raiz = x_nueva;
        sol_bis.iteraciones = iter;
        return sol_bis;
		  }
		  
		  if((f(a) * f(x_nueva)) > 0.0){
			  a = x_nueva;
		  }else{
			  b = x_nueva;
		  }
		  
		  x_anterior = x_nueva;
		  iter++;
	  }
	  return sol_bis;
  }
  
private:
  function<double(double)> func;
  string str_func;
  
  double f(double x) {
    return func(x);
  }
};

#endif
