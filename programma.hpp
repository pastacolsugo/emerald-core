

 //  mmmm mmmmmmm   mm     mmm  mmmmm   mmmm  mm   m mmmmm 
 // #"   "   #      ##   m"   "   #    m"  "m #"m  #   #   
 // "#mmm    #     #  #  #   mm   #    #    # # #m #   #   
 //     "#   #     #mm#  #    #   #    #    # #  # #   #   
 // "mmm#"   #    #    #  "mmm" mm#mm   #mm#  #   ## mm#mm 


const unsigned short int nS = 3; // numero delle stagioni


const GMS STAGIONI[nS] = {
	{	1,	 1, 	0}, 
	{	5, 	 1, 	1},
	{	10,  1, 	2}
};

 // m      m    m   mmm  mmmmm 
 // #      #    # m"   "   #   
 // #      #    # #        #   
 // #      #    # #        #   
 // #mmmmm "mmmm"  "mmm" mm#mm 

const unsigned short int nL = 3; //numero cambi luci


const HML LUCI [][nL] = {		//mancano le stagioni!
	{
		{ { 0,  0}, 	off},
		{ { 8,  0}, 	on },
		{ {19,  0}, 	off}
	}, 
	{
		{ { 0,  0}, 	off},
		{ { 8,  0}, 	on },
		{ {19,  0}, 	off}
	}, 
	{
		{ { 0,  0}, 	off},
		{ { 8,  0}, 	on },
		{ {19,  0}, 	off}
	}	
};

 //   mmm  mmmmm  mmmmmm mmmmm  m    m  mmmm    mmm   mmmm  m       mmmm 
 // m"   " #   "# #      #   "# #    # #"   " m"   " m"  "m #      m"  "m
 // #      #mmmm" #mmmmm #mmm#" #    # "#mmm  #      #    # #      #    #
 // #      #   "m #      #      #    #     "# #      #    # #      #    #
 //  "mmm" #    " #mmmmm #      "mmmm" "mmm#"  "mmm"  #mm#  #mmmmm  #mm# 

const unsigned short int nCrep = 3;

const HML CREPUSCOLO[][nCrep] = {
	{
		{ {0, 0}, 	off},
		{ {6, 0}, 	on},
		{ {20, 0},	off}
	},
	{
		{ {0, 0}, 	off},
		{ {6, 0}, 	on},
		{ {20, 0},	off}
	},
	{
		{ {0, 0}, 	off},
		{ {6, 0}, 	on},
		{ {20, 0},	off}
	}
};

 
// mmmmmmm mmmmmm m    m mmmmm  mmmmmm mmmmm    mm  mmmmmmm m    m mmmmm    mm  
//    #    #      ##  ## #   "# #      #   "#   ##     #    #    # #   "#   ##  
//    #    #mmmmm # ## # #mmm#" #mmmmm #mmmm"  #  #    #    #    # #mmmm"  #  # 
//    #    #      # "" # #      #      #   "m  #mm#    #    #    # #   "m  #mm# 
//    #    #mmmmm #    # #      #mmmmm #    " #    #   #    "mmmm" #    " #    #


// indicata in decimi di grado celsius
// 20 C = 200 dC

const unsigned short int nT = 4; //numero temperature


unsigned short int dT_sup = 10;
unsigned short int dT_inf = 10;

unsigned short int heat_dT_sup = 3;
unsigned short int heat_dT_inf = 3;
unsigned short int cool_dT_sup = 3;
unsigned short int cool_dT_inf = 3;

const HMT TEMPERATURA[][nT] = {		//mancano le stagioni!
	{
		{{ 0,  0},	150},
		{{ 8,  0},	180},
		{{ 13, 0},	200},
		{{ 22, 0},	170}
	},
	{
		{{ 0,  0},	150},
		{{ 8,  0},	180},
		{{ 13, 0},	200},
		{{ 22, 0},	170}
	},
		{
		{{ 0,  0},	150},
		{{ 8,  0},	180},
		{{ 13, 0},	200},
		{{ 22, 0},	170}
	}
};

 // m    m m    m mmmmm  mmmm   mmmmm mmmmmmm   mm  
 // #    # ##  ##   #    #   "m   #      #      ##  
 // #    # # ## #   #    #    #   #      #     #  # 
 // #    # # "" #   #    #    #   #      #     #mm# 
 // "mmmm" #    # mm#mm  #mmm"  mm#mm    #    #    #


const unsigned short int nU = 4;

const unsigned short int dU_sup = 10;
const unsigned short int dU_inf = 10;

const unsigned short int hum_dU_inf = 3;
const unsigned short int hum_dU_sup = 3;
const unsigned short int dehum_dU_inf = 3;
const unsigned short int dehum_dU_sup = 3;


const HMU HUMIDITY[][nU] = { //mancano le stagioni!
	{
		{{0,  0}, 	600},
		{{10, 0}, 	300},
		{{15, 0}, 	400},
		{{19, 0}, 	800}
	},
	{
		{{0,  0}, 	600},
		{{10, 0}, 	300},
		{{15, 0}, 	400},
		{{19, 0}, 	800}
	},
	{
		{{0,  0}, 	600},
		{{10, 0}, 	300},
		{{15, 0}, 	400},
		{{19, 0}, 	800}
	}
};


