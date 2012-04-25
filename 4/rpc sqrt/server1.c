#include <rpc/rpc.h>
#include "avg1.h"
#include <stdio.h>

static double *sqr;

double* square_1(double *input,
   CLIENT *client) {
	sqr = (double*)malloc(sizeof(double));
    *sqr = ((*input) * (*input));
  
  return(sqr);
}

double* square_1_svc(double *input,
   struct svc_req *svc) {
  CLIENT *client;
  return(square_1(input,client));
}
