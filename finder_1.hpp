
usi findStagione (TIME req){
	usi res = nS-1;
	for (usi i=1; i<nS; i++){
		TIME temp = { STAGIONI[i].mese, STAGIONI[i].giorno, 0, 0};
		if (compareTIME(req, temp) == 1){
			res = STAGIONI[i-1].stagione;
			break;
		}
	}
	return res;
}

bool findLuci (TIME req, usi stag){
	bool res = LUCI[stag][nL-1].stato;
	for (int i=1; i<nL; i++){
		TIME temp = {req.mese, req.giorno, LUCI[stag][i].orario.ore, LUCI[stag][i].orario.minuti};	//creo un TIME con mese e giorno odierni, ore e minuti del programma
		if (compareTIME(req, temp) == 1){		//per poter fare il paragone delle date
			res = LUCI[stag][i-1].stato;
			break;
		}
	}
	return res;
}

bool findCrepuscolo (TIME req, usi stag){
	bool res = CREPUSCOLO[stag][nCrep-1].stato;
	for (int i=1; i<nCrep; i++){
		TIME temp = {req.mese, req.giorno, CREPUSCOLO[stag][i].orario.ore, CREPUSCOLO[stag][i].orario.minuti};	//creo un TIME con mese e giorno odierni, ore e minuti del programma
		if (compareTIME(req, temp) == 1){		//per poter fare il paragone delle date
			res = CREPUSCOLO[stag][i-1].stato;
			break;
		}
	}
	return res;
}