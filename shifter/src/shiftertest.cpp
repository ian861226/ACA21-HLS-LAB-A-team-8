#include <iostream>
#include "ap_int.h"
#include "shifter.h"
#include <stdlib.h>

using namespace std;

#define TEST_NUM  1000


int main(int argc, char *argv[]) {

	ap_uint<3> mode;
	bool pass = 1;
	ap_uint<CTRL_BITS> s;
	for(int i = 0; i < TEST_NUM; ++i) {
		cout << "-------test " << i << " -------" << endl;
		mode = rand() % 8;
		cout << "mode: " << mode << endl;
		s = rand();
		cout << "s: " << s << endl;
		if(mode < 2) {
			//arithmetic
			ap_int<NUM_BITS> input = rand();
			ap_uint<NUM_BITS> output;
			ap_int<NUM_BITS> signed_out;
			shifter(mode, input, s, &output);
			signed_out = output;
			cout << input << endl;
			cout << signed_out << endl;
			if(mode == 0) {
				if(signed_out != input << s) {
					pass = 0;
					break;
				}
			}
			else if(mode == 1) {
				if(signed_out != input >> s) {
					pass = 0;
					break;
				}
			}

		}
		else {
			ap_uint<NUM_BITS> input = rand();
			ap_uint<NUM_BITS> output;
			shifter(mode, input, s, &output);
			cout << "input: " <<input << endl;
			cout << "your output: " <<output << endl;
			if(mode == 2) {
				if(output != (input >> (s%NUM_BITS) | (input << (NUM_BITS-(s%NUM_BITS))))) {
					cout << "golden: " << (input >> (s%NUM_BITS) | (input << (NUM_BITS-(s%NUM_BITS)))) << endl;
					pass = 0;
					break;
				}
			}
			else if(mode == 3) {
				if(output != input << s) {
					cout << "golden: " << (input << s) << endl;
					pass = 0;
					break;
				}
			}
			else if(mode == 4) {
				if(output != input >> s) {
					cout << "golden: " << (input >> s) << endl;
					pass = 0;
					break;
				}
			}
			else if(mode == 5) {
				if(s == 1) {
					if(output != (input >> 1)) {
						cout << "golden: " << (input >> 1) << endl;
						pass = 0;
						break;
					}
				}
				else if(s == 5) {
					if(output != input >> 5) {
						cout << "golden: " << (input >> 5) << endl;
						pass = 0;
						break;
					}
				}
				else if (output != input) {
					cout << "golden: " << input << endl;
					pass = 0;
					break;
				}
			}
			else if(mode == 6 || mode == 7) {
				ap_uint<NUM_BITS> acc = 0;
				for(int i = 0; i < NUM_BITS; ++i)
					acc += (input >> i) & 1;
				if(acc != output) {
					cout << "golden: " << acc << endl;
					pass = 0;
					break;
				}
			}

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
