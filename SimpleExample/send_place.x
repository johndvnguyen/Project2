const MAXLEN = 255;
typedef float latitude;
typedef float longitude;
typedef string placeName<MAXLEN>;

typedef struct searchedCity{
	string cityName,
	string state,
	latitude lat,
	longitude long
}

typedef struct airportList{
	char code[3],
	placeName name,
	char state[2],
	float distance,
	airportList* next
}

typedef struct output{
	searchedCity cityData,
	airportList airports
}

program SEND_PLACE_PROG {
	version SEND_PLACE_VERS {
		airportList PLACE(searchedCity) = 1;
	} = 1;
} = 0x31122172;

