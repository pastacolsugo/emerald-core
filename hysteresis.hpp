// graphed and put into header on 3 may 2017

bool hysteresis (HYS* req){
	// proven working correctly
	// 2 April 2017
	if (req->state == false){
		if (req->value >= req->zero + req->d_sup){
			return 1;
		} else {
			return 0;
		}
	} else {
		if (req->value <= req->zero - req->d_inf){
			return 0;
		} else {
			return 1;
		}
	}
}

bool reverse_hysteresis (HYS* req){
	// proven working correctly
	// 2 April 2017
	if (req->state == true){
		if (req->value >= req->zero + req->d_sup){
			return 0;
		} else {
			return 1;
		}
	} else {
		if (req->value <= req->zero - req->d_inf){
			return 1;
		} else {
			return 0;
		}
	}
}