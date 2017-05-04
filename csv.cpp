#include <cstdio>

int main (){
	FILE *out;
	out = fopen ("/Users/sugo/Google Drive/serra_mirko/v2/test.csv", "w");
	if (out == NULL){
		return -1;
	}

	fprintf (out, "4,4,4\n");
	fprintf (out, "3,3,3");
}