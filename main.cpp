#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

double f( double x){
    return cos(x)-x;
}

using namespace std;

int main()
{
    double xL, xR, xOld, xNew, xOlder;
    double err, tol;
    int i ;
    Tol = 0.00000001;
    
    cout<< "False position: "<<endl;
    cout<< " Enter the xL"<<endl;
    cin>> xL;
    cout<< " Enter the xR"<<endl;
    cin>> xR;
    
    xOld = xL; // used to calculate the first error
    i=0;
    do {
        xNew = (xL * f(xR) - xR* f(xL)) / (f(xR) - f(xL));
        i++;
        cout<< "i= "<<i << " xNew= "<<setprecision(8)<<xNew<< " xL= "<<xL<<" xR= "<<xR<<endl;
        if((f(xL)*f(xNew))<0.0){
            xR = xNew;
        }
        else{
            xL = xNew;
        }
        err = fabs((xNew - xOld)/ xNew);
        xOld = xNew;
    }while( err > tol);
    
    cout<< "Root found at: "<< setprecision(8)<<xNew<<endl;
    cout<< "Iterations: "<< i<<endl;
    
    
    cout<< " \nSecant: "<<endl;
    cout<< " Enter x_i-1"<<endl;
    cin>> xOlder;
    cout<< " Enter x_i"<<endl;
    cin>> xOld;
    
    i=0;
    do{
        xNew = (xOlder * f(xOld) - xOld * f(xOlder))/( f(xOld) - f(xOlder)); 
        i++;
        err = fabs(( xNew - xOld) / xNew );
        xOlder = xOld;
        xOld = xNew;
        cout<< " i= "<<i<<" xNew= "<<setprecision(8)<<xNew<<endl;
        
    }while(err >tol);
    
    cout<<"Root found at: "<<setprecision(8)<<xNew<<endl;
	cout<<"Iterations: "<<i<<endl;
    
    return 0;
}
