//
// Created by DIALLO on 13/04/2017.
//

#ifdef SIGNATURE_EXPORTS
#define SIGNATURE_INTERFACE __declspec(dllexport)
#else
#define SIGNATURE_INTERFACE __declspec(dllimport)
#endif


#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Utiles.h"

const unsigned maxBits = 32;
const unsigned modulo = 256;

using namespace std;

SIGNATURE_INTERFACE class Signature {
protected:
	Utiles convertisseur;

public:
	Signature() {
		srand(time(NULL));
	}


	SIGNATURE_INTERFACE bool generate(string& privateKey, string& publickey);
	SIGNATURE_INTERFACE string sign(string data, string privKey);
	SIGNATURE_INTERFACE bool verify(string data, string signature, string pubKey);

private:
	string generatePrivKey();
	string generatePublicKeyFromPrivKey(string privKey);
	int sommeHex(string, string);
	string transformeTexteToAsciiHex(string, char const *);
	string transformeHexToAsciiTexte(string);
	string EncriptPartFile(string, string);
	unsigned int split(const string &texte,
		vector<string> &resultat,
		char _separateur);
};

