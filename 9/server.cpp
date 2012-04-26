#include"soapH.h"
#include"calc.nsmap"

main(){

int m,s;
struct soap *soap=soap_new();
m= soap_bind(soap,NULL,8000,100);
printf("offerring on port 8000 services of calculator");

while(1){
s=soap_accept(soap);
soap_serve(soap);
soap_end(soap);
}
soap_done(soap);
soap_free(soap);
return 0;
}

int ns__add(soap *soap,double a,double b,double *result){
*result=a+b;
return SOAP_OK;
}
