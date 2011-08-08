#include <iostream>
#include <string>
#include <uccppexam.h>

using namespace std;
using namespace uc;

int main(int c, char *v[])
{
	if (c == 2) {
		cout << string(v[1]) << endl;
	}
	return UCCpp::getRoot();
}
