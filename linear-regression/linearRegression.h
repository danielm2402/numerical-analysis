//
// Created by Daniel Muñoz on 3/19/21.
//

#ifndef LINEAR_REGRESSION_LINEARREGRESSION_H
#define LINEAR_REGRESSION_LINEARREGRESSION_H
#include <vector>
#include "cmath"
using std::vector;
struct point{
    point(double p_x, double p_y):x(p_x),y(p_y){

    }
    double x;
    double y;
};
struct result{
    double b0=0.0;
    double b1=0.0;
    double r2=0.0;
    double sy=0.0;
    double syx=0.0;
};
class regresion_lineal{
public:
    regresion_lineal(vector<point> v_datos):data(v_datos){

    }
    void table(){

    }
    result calculate(){
        double sumx=0.0, sumy=0.0, sumxy=0.0, sumx2=0.0;
        result r;
        int n = data.size();
        if (n==0){
            return r;
        }
        for (int i=0; i<n;i++){
            sumx+=data[i].x;
            sumy+=data[i].y;
            sumx2+=data[i].x *data[i].x;
            sumxy+=data[i].x *data[i].y;
        }
        double x_prom= sumx/n;
        double y_prom= sumy/n;
        r.b1= (sumxy-y_prom*sumx)/(sumx2-x_prom*sumx);
        r.b0=y_prom-r.b1*x_prom;
        double st=0.0, sr=0.0;
        for (int i=0; i<n;i++){
            st+=pow(data[i].y-y_prom,2);
            sr+=pow(data[i].y-r.b0-(r.b1*data[i].x),2);
        }
        r.sy=sqrt(st/(n-1));
        r.syx=sqrt(sr/(n-2));
        r.r2=(st-sr)/st;
        return r;
    }

private:vector<point> data;
};
#endif //LINEAR_REGRESSION_LINEARREGRESSION_H
