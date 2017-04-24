#include <iostream>
#include "../Signature/Signature.h"

using namespace std;

int main(void) {
	
	Signature ace;
	string data = "je suis gallou et je vais dévenir ' % # @ */-51 madame "
		"sapo equilibre avec un equilibriste de renomer haha ";;

	string privkey1;
	string pubkey1;

	string privkey2;
	string pubkey2;

	cout << ace.generate(privkey1, pubkey1) << endl;
	cout << ace.generate(privkey2, pubkey2) << endl;

	string signature = ace.sign(data, privkey1);

	cout << ace.verify(data, signature, pubkey1) << endl;

	cout << ace.verify(data, signature, pubkey2) << endl;
	return 0;

}
