//
// Created by DIALLO on 13/04/2017.
//

#ifndef CRIPTO_CONVERT_H
#define CRIPTO_CONVERT_H

#include <array>

using namespace std;
class convert {
public:
    string to_hex(int);
    int hex_to_int(string);
    string to_bin(int);
    int to_int(string);
    string bin_complement(string);
    string hex_to_bin(const string &);
    string bin_to_hex(const string &);

protected:
    string int_to_bin(int);
    string reverse(string);
};


#endif //CRIPTO_CONVERT_H
