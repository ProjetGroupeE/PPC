#include<iostream>
#include<stdlib.h>
#include <time.h>
#include "Ace/Ace.h"


using namespace std;
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
    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        string pk = ace.generatePrivKey();
        string pbk = ace.generatePublicKeyFromPrivKey(pk);
        cout << "\nRandom Priv key : " << pk;
        cout << "\n Public key --> : " << pbk<<endl;
        string enc = ace.encryption
                ("je suis gallou et je vais devenir madame "
                         "sapo equilibre avec un equilibriste"
                         " de renome ", pk);
        cout << enc << endl;
        cout << ace.decryption(enc, pbk) << endl;
    }
    return 0;
}