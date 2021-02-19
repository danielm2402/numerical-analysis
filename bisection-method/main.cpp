#include <iostream>
#include "biseccion.h"
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

int main() {
    double a,b, tolerancia;
    int intervalos, max_iter;
    biseccion bis([](double x)->double {
        return exp(-x) - log(x);
    },"e^-x -ln(x)");
    cout<<"Método de biseccion para la función"
    <<bis.str()
    <<endl;
    cout<<"Ingrese los valores a y b del intervalo para evaluar la función: ";
    cin>>a>>b;
    cout<<"Ingrese el numero de sub intervalos para imprimir la tabla: ";
    cin >> intervalos;
    cout<<"Ingrese la tolerancia:";
    cin>>tolerancia;
    cout<<"Maximo numero de iteraciones";
    cin>>max_iter;
    bis.imprimirTabla(a,b,intervalos);
    double raiz;
    bool resultado=bis.encontrarRaiz(
            a,
            b,tolerancia,
            max_iter,
            raiz
            );
    if(resultado){
        cout<<"Raiz encontrada: "<<raiz<<endl;
    } else{
      cout <<"Raiz no encontrada"<<endl  ;
    }
    return 0;
}

