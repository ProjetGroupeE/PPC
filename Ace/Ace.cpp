//
// Created by DIALLO on 13/04/2017.
//

#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Ace.h"


string Ace::generatePublicKeyFromPrivKey(string privKey) {
    string resultat;
    for (unsigned int i = 0; i < privKey.size(); i+= 2) {
        //get 8 bites or 2 char hexa
        resultat += convertisseur.bin_to_hex(
                convertisseur.bin_complement(
                        convertisseur.hex_to_bin(privKey.substr (i , i + 2))
                )
        );
    }
    transform(resultat.begin(), resultat.end(), resultat.begin(), ::toupper);
    return resultat;
}

string Ace::generatePrivKey() {

    const char *hex_digits = "0123456789ABCDEF";
//    int randomValue = rand()+;
    string resultat;

    do{
//        resultat  = convertisseur.to_hex(randomValue);
        resultat  += hex_digits[ ( rand() % 16 ) ];
    }while (resultat.size() != 4);

    return resultat;
}

string Ace::transformeTexteToAsciiHex(string texte, char const *_separateur) {
    ostringstream result;
    result << setw(2) << setfill('0') << hex << uppercase;
    copy(texte.begin(), texte.end(), ostream_iterator<unsigned int>(result, _separateur));
    return result.str() ;
}

unsigned int Ace::split(const string &texte, vector<string> &resultat, char _separateur) {
    unsigned int pos = texte.find( _separateur );
    unsigned int initialPos = 0;
    resultat.clear();
    // Decompose statement
    while( pos != string::npos ) {
        resultat.push_back( texte.substr( initialPos, pos - initialPos + 1 ) );
        initialPos = pos + 1;
        pos = texte.find( _separateur, initialPos );
    }
    // Add the last one
//    resultat.push_back( texte.substr( initialPos, min( pos, texte.size() ) - initialPos + 1 ) );
    return resultat.size();
}

//string Ace::sommeHex(string u, string v) {
//    return convertisseur.to_hex(convertisseur.hex_to_int(u) + convertisseur.hex_to_int(v));
//}
int Ace::sommeHex(string u, string v) {
    return convertisseur.hex_to_int(u) + convertisseur.hex_to_int(v);
}

string Ace::EncriptPartFile(string partTexte, string partPrivateKey) {
    string resultat = convertisseur.to_hex(sommeHex(partTexte , partPrivateKey) % modulo);
    return resultat.size() == 1 ? '0' + resultat : resultat;
}

string Ace::encryption(string texte, string privateKey) {

    vector<std::string> tabSplit;

    string asciiTexte = transformeTexteToAsciiHex(texte, " ");
    split(asciiTexte , tabSplit, ' ');
    string resultat, partPrivateKey;
    for (unsigned int i = 0; i < tabSplit.size(); ++i) {
        partPrivateKey = privateKey.substr(( (i*2 )% privateKey.size()), 2);
        resultat += EncriptPartFile(tabSplit.at(i), partPrivateKey);
    }
    return resultat;
}

string Ace::decryption(string texte, string publicKey) {

    string resultat, partPublicKey;
    for (unsigned int i = 0, j=0; j < texte.size(); ++i,j+=2) {
        partPublicKey = publicKey.substr(( (i*2 )% publicKey.size()), 2);
        resultat +=EncriptPartFile(texte.substr(j,2), partPublicKey);
    }
    return transformeHexToAsciiTexte(resultat);
}

string Ace::transformeHexToAsciiTexte(string hexaTexte){
    int len = hexaTexte.size();
    string resultat, byteRepresentation;
    for(unsigned int i=0; i< len; i+=2) {
        byteRepresentation = hexaTexte.substr(i, 2);
        char chr = (char) (int)strtol(byteRepresentation.c_str(), NULL, 16);
        resultat.push_back(chr);
    }
    return resultat;
}
