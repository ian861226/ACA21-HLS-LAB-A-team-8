
#include <iostream>
#include "Automatic_tree_balancing.h"

using namespace std;

int main(int argc, char *argv[])
{
	int i, j;
	int pass = 1;
	int n32Multip;

	cout << ">> Start test!" << endl;

	for(i = 1; i < 10; i++) {
		cout << "------------------------" << endl;
		ap_int<WIDTH> a[NUM_REGS];
		for(j = 0; j < NUM_REGS; j++) {
			a[j] = ap_int<WIDTH> ( i + j );
		}

		ap_int<WIDTH_OUT> out = adder_tree_balanced(a);

		int ans = 0;
		for(j = 0; j < NUM_REGS; j++) {
			ans += a[j];
		}
		cout << "i: " << i << endl;
		cout << "ans: " << ans << endl;
		cout << "out: " << out << endl;
		if(out != ans) {
			pass = false;
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
