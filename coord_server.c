/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "coord.h"

airportList *
coord_1_svc(searchedCity *argp, struct svc_req *rqstp)
{
	static airportList  result;
	printf("got to the server function");

	searchedCity theCity = *argp;

	sprintf((*result).name,"The city lat is :%f \n", theCity.lat);
	/*
	 * insert server code here
	 */

	return &result;
}
