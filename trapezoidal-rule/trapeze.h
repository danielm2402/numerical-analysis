//
// Created by User on 23/08/2021.
//

#ifndef TRAPEZOIDAL_RULE_TRAPEZE_H
#define TRAPEZOIDAL_RULE_TRAPEZE_H

#include "functional"

using std::function;

class trapeze{
public:
    static double integrate(function<double(double)> f, double lower_limit, double upper_limit, int intervals){
        double h =(upper_limit-lower_limit)/intervals;
        double s = 0.0;
        double x;
        int i;
        for(i = 1, x=lower_limit+h; i < intervals;i++,x+=h){
            s += f(x);
        }

        double sum = f(lower_limit)+(2*s)+f(upper_limit);
        double result = ((upper_limit-lower_limit)*sum)/(2*intervals);
        return result;
    };
};
#endif //TRAPEZOIDAL_RULE_TRAPEZE_H
