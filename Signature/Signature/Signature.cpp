//
// Created by DIALLO on 13/04/2017.
//

#include <sstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Signature.h"


string Signature::generatePublicKeyFromPrivKey(string privKey) {
	string resultat;
	for (unsigned int i = 0; i < privKey.size(); i += 2) {
		//get 8 bites or 2 char hexa
		resultat += convertisseur.bin_to_hex(
			convertisseur.bin_complement(
				convertisseur.hex_to_bin(privKey.substr(i, i + 2))
			)
		);
	}
	transform(resultat.begin(), resultat.end(), resultat.begin(), ::toupper);
	return resultat;
}

string Signature::generatePrivKey() {

	const char *hex_digits = "0123456789ABCDEF";
	//    int randomValue = rand()+;
	string resultat;

	do {
		//        resultat  = convertisseur.to_hex(randomValue);
		resultat += hex_digits[(rand() % 16)];
	} while (resultat.size() != 4);

	return resultat;
}

string Signature::transformeTexteToAsciiHex(string texte, char const *_separateur) {
	ostringstream result;
	result << setw(2) << setfill('0') << hex << uppercase;
	copy(texte.begin(), texte.end(), ostream_iterator<unsigned int>(result, _separateur));
	return result.str();
}

unsigned int Signature::split(const string &texte, vector<string> &resultat, char _separateur) {
	unsigned int pos = texte.find(_separateur);
	unsigned int initialPos = 0;
	resultat.clear();
	// Decompose statement
	while (pos != string::npos) {
		resultat.push_back(texte.substr(initialPos, pos - initialPos + 1));
		initialPos = pos + 1;
		pos = texte.find(_separateur, initialPos);
	}
	// Add the last one
	//    resultat.push_back( texte.substr( initialPos, min( pos, texte.size() ) - initialPos + 1 ) );
	return resultat.size();
}

//string Ace::sommeHex(string u, string v) {
//    return convertisseur.to_hex(convertisseur.hex_to_int(u) + convertisseur.hex_to_int(v));
//}
int Signature::sommeHex(string u, string v) {
	return convertisseur.hex_to_int(u) + convertisseur.hex_to_int(v);
}

string Signature::EncriptPartFile(string partTexte, string partPrivateKey) {
	string resultat = convertisseur.to_hex(sommeHex(partTexte, partPrivateKey) % modulo);
	return resultat.size() == 1 ? '0' + resultat : resultat;
}

string Signature::transformeHexToAsciiTexte(string hexaTexte) {
	int len = hexaTexte.size();
	string resultat, byteRepresentation;
	for (unsigned int i = 0; i< len; i += 2) {
		byteRepresentation = hexaTexte.substr(i, 2);
		char chr = (char)(int)strtol(byteRepresentation.c_str(), NULL, 16);
		resultat.push_back(chr);
	}
	return resultat;
}

bool Signature::generate(string &privateKey, string &publickey) {
	try {
		string pk = generatePrivKey();
		string pbk = generatePublicKeyFromPrivKey(pk);
		privateKey = pk;
		publickey = pbk;

		return true;
	}
	catch (const exception& e) {
		cerr << e.what();
		return false;
	}
}

string Signature::sign(string data, string privKey) {

	vector<std::string> tabSplit;

	string asciiTexte = transformeTexteToAsciiHex(data, " ");
	split(asciiTexte, tabSplit, ' ');
	string resultat, partPrivateKey;
	for (unsigned int i = 0; i < tabSplit.size(); ++i) {
		partPrivateKey = privKey.substr(((i * 2) % privKey.size()), 2);
		resultat += EncriptPartFile(tabSplit.at(i), partPrivateKey);
	}
	return resultat;
}

bool Signature::verify(string data, string signature, string pubKey) {
	string resultat, partPublicKey;
	for (unsigned int i = 0, j = 0; j < signature.size(); ++i, j += 2) {
		partPublicKey = pubKey.substr(((i * 2) % pubKey.size()), 2);
		resultat += EncriptPartFile(signature.substr(j, 2), partPublicKey);
	}
	return 0 == transformeHexToAsciiTexte(resultat).compare(data);
}

