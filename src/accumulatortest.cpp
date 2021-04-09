#include <iostream>
#include "ap_int.h"
#include "accumulator.h"
#include <stdlib.h>

using namespace std;

#define TEST_NUM  1000


int main(int argc, char *argv[]) {

	ap_uint<3> mode;
	bool pass = 1;
	ap_int<Width> in[Num_reg];
	ap_int<Width + int(log2(Num_reg))> golden;
	ap_int<Width + log2_Num_reg> out;
	for(int i = 0; i < TEST_NUM; ++i) {
		golden = 0;
		cout << "-------test " << i << " -------" << endl;
		for(int j = 0; j < Num_reg; ++j) {
			in[j] = rand();
			cout << "in[" << j <<"]: " << in[j] << endl;
			golden += in[j];
		}
		accumulator(in, &out);
		cout << "your output: " << out << endl;
		if(out != golden) {
			cout << "golden: " << golden << endl;
			pass = 0;
			break;
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
