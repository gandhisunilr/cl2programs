/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _IDLESERVER_H_RPCGEN
#define _IDLESERVER_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct twonos {
	int no1;
	int no2;
};
typedef struct twonos twonos;

#define idleserver 10
#define idleserverversion 1

#if defined(__STDC__) || defined(__cplusplus)
#define getcpu 1
extern  float * getcpu_1(void *, CLIENT *);
extern  float * getcpu_1_svc(void *, struct svc_req *);
#define addnos 2
extern  int * addnos_1(twonos *, CLIENT *);
extern  int * addnos_1_svc(twonos *, struct svc_req *);
extern int idleserver_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define getcpu 1
extern  float * getcpu_1();
extern  float * getcpu_1_svc();
#define addnos 2
extern  int * addnos_1();
extern  int * addnos_1_svc();
extern int idleserver_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_twonos (XDR *, twonos*);

#else /* K&R C */
extern bool_t xdr_twonos ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_IDLESERVER_H_RPCGEN */
