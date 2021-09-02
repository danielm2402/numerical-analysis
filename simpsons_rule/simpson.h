//
// Created by User on 30/08/2021.
//

#ifndef SIMPSONS_RULE_SIMPSON_H
#define SIMPSONS_RULE_SIMPSON_H
#include <functional>
#include <utility>

using std::function;
using std::cout;
using std::endl;

class simpson{
public:
    simpson(function<double(double)> p_f, double p_a, double p_b):f(p_f), a(p_a), b(p_b){};

    double un_tercio(int n){
        double resultado {0.0f};
        double x = a ;
        double h = (b-a)/n;
        double s_impares = 0.0f;
        double s_pares = 0.0f;
        int cont;

        for(x= a + h, cont = 1; cont <n;cont++){
            double y = f(x);
            if(cont%2==0){
                s_pares +=y;
            }else{
                s_impares +=y;
            }
            x += h;
        }
        resultado = (h/3)*(f(a)+(4*s_impares)+(2*s_pares)+f(b));
        return  resultado;
    }
    double tres_octavos(int n){

        double h = (b-a)/n;
        double x = a;
        double y = f(x);
        double s1 = 0;
        double s2 = 0;

        for (int i = 1; i < n; ++i) {
            x = x + h;
            y = f(x);

            if(i%3==0){
                s1 = s1+y;
            }else{
                s2 = s2 +y;
            }
        }

        double resultado = (3*h/8)*(f(a)+(3*s2)+(2*s1)+f(b));
        return resultado;
    }
private:
    function<double(double)> f;
    double a;
    double b;
};

#endif //SIMPSONS_RULE_SIMPSON_H
