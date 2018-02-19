//File reading for places

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float latitude;

typedef float longitude;

typedef struct placeNode {
	char *city[255];
	char *state[2];
	latitude lat;
	longitude lon;
} placeNode;


void trimCity(char *city){
	//printf("this is the city %s \n", city);
	char *pos = strstr(city,"  ");
	//printf ("this is the position of the double space: %d \n", pos);
	if (pos)
		city[(int)(pos-city)] = '\0';
	//printf("this is the trimmed city: %s;endline\n", city);
	// now trim the last word
	//printf("this is the city %s \n", city);
	pos = strrchr(city,' ');
	//printf ("this is the position of the last space: %d \n", pos-city);
	if (pos)
		city[(int)(pos-city)] = '\0';
	return ;
}


void readFile(){
FILE * fp;
fp = fopen("./places2k.txt","r");
char line[255];
char state[3];
char city[63];
char locationtemp[9];
latitude lat;
longitude lon;
placeNode * start;
while(1){
	//struct placeNode * newNode = (struct placeNode*)malloc(sizeof(struct placeNode));
	//check node was created successfully if fail

	if (fgets(line,200,fp)==NULL) break;
	//get the state
	strncpy(state, line, 2);
	state[3]= '\0';
	//get the city
	strncpy(city, &line[9], 62);
	city[63]= '\0';
	trimCity(city);
	//get latitude
	strncpy(locationtemp, &line[143], 9);
	lat = atof(locationtemp);

	//get longitude
		strncpy(locationtemp, &line[153], 9);
		lon = atof(locationtemp);

		printf("state: %s, city: %s, lat: %f lon: %f \n", state,city,lat,lon);
	}


	fclose(fp);
}


int
main (int argc, char *argv[])
{
readFile();
exit(0);
}