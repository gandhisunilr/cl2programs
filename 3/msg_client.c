/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "msg.h"


void
sunil_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	operands  add_1_arg;
	int  *result_2;
	operands  sub_1_arg;

	add_1_arg.a=10;
	sub_1_arg.a=10;
	add_1_arg.b=12;
	sub_1_arg.b=12;
#ifndef	DEBUG
	clnt = clnt_create (host, sunil_prog, sunil_version, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = add_1(&add_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = sub_1(&sub_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	printf("%d",*result_1);
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	sunil_prog_1 (host);
exit (0);
}
