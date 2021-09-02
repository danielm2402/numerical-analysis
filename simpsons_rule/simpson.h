//
// Created by User on 30/08/2021.
//

#ifndef SIMPSONS_RULE_SIMPSON_H
#define SIMPSONS_RULE_SIMPSON_H
#include <functional>

using std::function;

class simpson{
public:
    simpson(function<double(double)> p_f, double p_a, double p_b){
        a = p_a;
    }
    double un_tercio(int n){
        double resultado {0.0f};
        double x = a ;
        double h = (b-a)/n;
        double s_impares = 0.0f;
        double s_pares = 0.0f;
        int cont;

        for(x= a + h, cont = 1; cont <=n;cont++){
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

    }

private:
    function<double(double)> f;
    double a;
    double b;
    int n;
};

#endif //SIMPSONS_RULE_SIMPSON_H
