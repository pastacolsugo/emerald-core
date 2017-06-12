
usi findSeason (TIME* req){
	usi res = nS-1;
	
	for (usi i=1; i<nS; i++){
		TIME temporary = { SEASONS[i].month, SEASONS[i].day, 0, 0};
		
		if (compareTIME(req, &temporary) == 1){
			res = SEASONS[i-1].season;
			break;
		}
	}
	return res;
}

bool findLight (TIME* req, usi* stag){
	bool res = LIGHT [*stag][nL-1].state;
	
	for (int i=1; i<nL; i++){
		TIME temporary = {
			req->month, 
			req->day, 
			LIGHT[*stag][i].time.hour, 
			LIGHT[*stag][i].time.minute
		}; //creo un TIME con month, day odierni; hour e minute del programma

		//per poter fare il paragone delle date
		if (compareTIME(req, &temporary) == 1){		
			res = LIGHT[*stag][i-1].state;
			break;
		}
	}
	return res;
}

bool findLight2 (TIME* req, usi* stag){
	bool res = LIGHT_2[*stag][nCrep-1].state;
	
	for (int i=1; i<nCrep; i++){
		TIME temporary = {
			req->month, 
			req->day, 
			LIGHT_2[*stag][i].time.hour,
			LIGHT_2[*stag][i].time.minute
			};	
		//creo un TIME con month e day odierni, hour e minute del programma
		
		//per poter fare il paragone delle date
		if (compareTIME(req, &temporary) == 1){		
			res = LIGHT_2[*stag][i-1].state;
			break;
		}
	}
	return res;
}

bool findWater (TIME* req, usi* stag){
	bool res = WATER[*stag][nW-1].state;

	for (int i=1; i<nW; i++){
		TIME temporary = {
			req->month, 
			req->day, 
			WATER[*stag][i].time.hour, 
			WATER[*stag][i].time.minute
		};

		if (compareTIME(req, &temporary) == 1){
			res = WATER[*stag][i-1].state;
			break;
		}
	}
	return res;
}