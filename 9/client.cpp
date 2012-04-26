#include"soapcalcProxy.h"
#include"calc.nsmap"
#include<iostream>

using namespace std;
main(){
calc c;
double a,b,d;

c.ns__add(1.0,3.2,&d);
cout<<d;
return 0;
}
