//
// Created by DIALLO on 13/04/2017.
//

#include "convert.h"
#include "Ace.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <bitset>

string convert::int_to_bin(int number){

    int val = number;
    string result;
    do
    {
        result.push_back((char) ('0' + (val & 1)));
    } while (val >>= 1);
    return reverse(result);
}

string convert::reverse(string to_reverse){
    string result;
    for (int i = to_reverse.length()-1; i >=0 ; i--)
        result += to_reverse[i];
    return result;
}

string convert::to_hex(int to_convert){
    string result;
    stringstream ss;
    ss << hex <<to_convert;
    ss >> result;
    return result;
}

string convert::to_bin(int to_convert){
    return int_to_bin(to_convert);
}

int convert::hex_to_int(string to_int) {
    unsigned int resultat;
    std::stringstream ss;
    ss << hex << to_int;
    ss >> resultat;
    return resultat;
}

string convert::bin_complement(string number) {
    for (int i = number.length(), carry = 1; i-- > 0;) {
        number[i] = (char) ((number[i] ^ 1) + carry); // flip the bit and add the previous carry
        carry = (number[i]&2)>>1;        // save the overflow in the carry variable
        number[i] &= ~2;                 // mask out the overflow
    }
    return number;
}

int convert::to_int(string to_integer) {
    int resultat = 0;
    for(int i= to_integer.length()-1,k=0; i>=0 ;i--,k++){
        if(to_integer[i]=='1'){
            resultat += pow(2, k);
        }
    }
    return resultat;
}

string convert::hex_to_bin(const string &hexaString) {
    stringstream ss;
    ss << hex << hexaString;
    unsigned n;
    ss >> n;
    bitset<maxBits> b(n);

    return b.to_string().substr(32 - 4*(hexaString.length()));
}

string convert::bin_to_hex(const string &binaryString) {
    bitset<maxBits> bs(binaryString);
    unsigned n = bs.to_ulong();
    stringstream ss;
    ss << hex << n;
    return  (binaryString.compare(0,4,"0000") == 0)? "0" + ss.str() : ss.str();
}
