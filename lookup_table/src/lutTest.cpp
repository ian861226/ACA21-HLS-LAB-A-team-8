#include <iostream>
#include <ap_fixed.h>
#include <math.h>
#include "lut.h"
#include <stdlib.h>

using namespace std;

#define TEST_NUM  1000


int main(int argc, char *argv[]) {

	bool pass = 1;
    double pi = 3.1415926535897932384626433832795;

    ap_fixed<WIDTH,2> output;
    ap_fixed<WIDTH,2> golden;

    for(unsigned int i=0;i<NUM_REGS;i++) {
		cout << "-------test " << i << " -------" << endl;
        golden = sin(2*pi*i/(double)NUM_REGS);
        output = lut(i);
		cout << "your output: " << output << endl;

		if(output != golden) {
			cout << "golden: " << golden << endl;
			pass = 0;
			//break;
		}
    }

	cout << "------------------------" << endl;
	if(!pass) {
		cout << ">> Test failed!" << endl;
		return 1;
	}

	cout << ">> Test passed!" << endl;
	cout << "------------------------" << endl;
	return 0;

}
