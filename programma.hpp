#define on true
#define off false

// IMPORTANTE: non mettere zeri inutili prima dei numeri. 
// Se l'orario e' ore 08:00 mettere 8, 00. NON 08, 00.

// IMPORTANT: do NOT place leading zeroes in numbers.
// If the time is 08:00, write 8; NOT 08.

 //  mmmm                                           
 // #"   "  mmm    mmm    mmm    mmm   m mm    mmm  
 // "#mmm  #"  #  "   #  #   "  #" "#  #"  #  #   " 
 //     "# #""""  m"""#   """m  #   #  #   #   """m 
 // "mmm#" "#mm"  "mm"#  "mmm"  "#m#"  #   #  "mmm" 

const unsigned short int nS = 3; // number of seasons


const DMS SEASONS [nS] = {
	{	1,	 1, 	0}, 
	{	5, 	 1, 	1},
	{	10,  1, 	2}
};

 // m        "           #        m   
 // #      mmm     mmmm  # mm   mm#mm 
 // #        #    #" "#  #"  #    #   
 // #        #    #   #  #   #    #   
 // #mmmmm mm#mm  "#m"#  #   #    "mm 
 //                m  #               
 //                 ""                

const unsigned short int nL = 3; //numero cambi luci


const HML LIGHT [][nL] = {		//mancano le stagioni!
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

 // m        "           #        m            mmmm 
 // #      mmm     mmmm  # mm   mm#mm         "   "#
 // #        #    #" "#  #"  #    #               m"
 // #        #    #   #  #   #    #             m"  
 // #mmmmm mm#mm  "#m"#  #   #    "mm         m#mmmm
 //                m  #                             
 //                 ""                          

const unsigned short int nCrep = 3;

const HML LIGHT_2 [][nCrep] = {
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
 
                                                                             
// mmmmmmm                                             m                        
//    #     mmm   mmmmm  mmmm    mmm    m mm   mmm   mm#mm  m   m   m mm   mmm  
//    #    #"  #  # # #  #" "#  #"  #   #"  " "   #    #    #   #   #"  " #"  # 
//    #    #""""  # # #  #   #  #""""   #     m"""#    #    #   #   #     #"""" 
//    #    "#mm"  # # #  ##m#"  "#mm"   #     "mm"#    "mm  "mm"#   #     "#mm" 
//                       #                                                      
//                       "            

// indicata in decimi di grado celsius
// 20 C = 200 dC
// temperature is measured in tenths of a Celsius degree (10^-1 C)

const unsigned short int nT = 4; //numero temperature


unsigned short int dT_sup = 10;
unsigned short int dT_inf = 10;

unsigned short int heat_dT_sup = 3;
unsigned short int heat_dT_inf = 3;
unsigned short int cool_dT_sup = 3;
unsigned short int cool_dT_inf = 3;

const HMT TEMPERATURE[][nT] = {		//mancano le stagioni!
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


const HMH HUMIDITY[][nU] = { //mancano le stagioni!
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


                                   
	// m     m          m                 
	// #  #  #  mmm   mm#mm   mmm    m mm 
	// " #"# # "   #    #    #"  #   #"  "
	//  ## ##" m"""#    #    #""""   #    
	//  #   #  "mm"#    "mm  "#mm"   #    

const unsigned short int nW = 3;		//numero 

const HMW WATER[][nW] = {		//mancano le stagioni!
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




