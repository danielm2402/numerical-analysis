#include <iostream>
#include "falsePosition.h"

int main() {
    double root;
    bool result;
    falsePosition fp([](double x)->double {
        return exp(-x) - log(x);
    },"e^-x -ln(x)");

    result=fp.findRoot(0.5,2.0,1,5,root);
    if(result){
        cout<<"Root:"<<root;
    }else{
        cout<<"Root not found";
    }
    return 0;
}
