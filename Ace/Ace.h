//
// Created by DIALLO on 13/04/2017.
//

#ifndef CRIPTO_ACE_H
#define CRIPTO_ACE_H

#include <vector>
#include "convert.h"

const unsigned maxBits = 32;
const unsigned modulo = 256;

class Ace {
protected:
    convert convertisseur;

public:
    string generatePrivKey();
    string generatePublicKeyFromPrivKey(string privKey);
    string encryption(string,string);
    string decryption(string,string);

private:
//    string sommeHex(string,string);
    int sommeHex(string,string);
    string transformeTexteToAsciiHex(string, char const *);
    string transformeHexToAsciiTexte(string);
    string EncriptPartFile(string,string);
    unsigned int split(const string &texte,
                       vector<string> &resultat,
                       char _separateur);
};


#endif //CRIPTO_ACE_H
