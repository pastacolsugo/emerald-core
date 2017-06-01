#include <cstdio>

int main(){
	for (int target=-100; target<=400; target++){
		for (int inside=-100; inside<=400; inside++){
			for (int outside=-100; outside<=400; outside++){
				printf("%i %i %i\n", target, inside, outside);
			}
		}
	}
}