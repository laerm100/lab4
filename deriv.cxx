#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void fillarray(double* p, const int N, const double dx, const double xmin){
  
  for (int i=0; i<N; i++){
    p[i]=exp(-(i*dx+xmin)*(i*dx+xmin)); //f(x_i)=exp(-x_i^2);
    }
 }
 
 void deriv(double* p, const int N, const double dx, const double xmin){
   
  double ftemp=0, f;

   for (int i=0; i<N-1; i++){
     f=p[i]; // alter Funktionswert f_i wird als f gespeichert
     
      p[i]=(p[i+1]-ftemp)/(2*dx);
     
     ftemp=f;
  }
 
 p[N-1]=(0-ftemp)/(2*dx);
}
  
int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  fillarray(p, N, dx, xmin);// call to function which fills array p here
  deriv(p, N, dx, xmin);  // call to functio which calculates the derivative
  
  print(p,N,dx,xmin);

  return 0;
}
