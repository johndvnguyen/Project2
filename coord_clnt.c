/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "coord.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

airportList *
coord_1(searchedCity *argp, CLIENT *clnt)
{
	static airportList clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, COORD,
		(xdrproc_t) xdr_searchedCity, (caddr_t) argp,
		(xdrproc_t) xdr_airportList, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
