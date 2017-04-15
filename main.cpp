#include<iostream>
#include<stdlib.h>
#include <time.h>
#include <iterator>
#include <iomanip>
#include <sstream>
#include "Ace/Ace.h"


//using namespace std;
//
//int main(int argc, char **argv){
//    srand (time(NULL));
//
//    Ace ace;
//    convert convertisseur;
//    for (int i = 0; i < 5; ++i) {
//        string pk = ace.generatePrivKey();
//        cout<< "\nRandom Priv key : " << pk;
//        cout<< "\nRandom Public key ---> : " << ace.generatePublicKeyFromPrivKey(pk);
//         pk = "04f7";//ace.generatePrivKey();
//        cout<< "\nRandom Priv key : " << pk;
//        cout<< "\nRandom Public key : " << ace.generatePublicKeyFromPrivKey(pk);
//         pk = "910a";//ace.generatePrivKey();
//        cout<< "\nRandom Priv key : " << pk;
//        cout<< "\nRandom Public key : " << ace.generatePublicKeyFromPrivKey(pk);
//    cout<<convertisseur.bin_complement(
//            convertisseur.hex_to_bin("f7")
//    );

//    }
//
//}


int main() {
    Ace ace;
    convert conv;
    string enc = ace.encryption("","da08");
    cout << enc << endl;
    cout << ace.decryption(enc,"26f8") << endl;
}