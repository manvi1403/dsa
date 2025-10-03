#include "crc.h"
using namespace std;

/**
 * Perform modulo-2 division of `data` by `generator` and return the remainder.
 * `data` is expected to be (message + k zeros) where k = generator.size() - 1
 */
string modulo2Division(string data, const string &generator) {
    // You can assume data.size() >= generator.size()
    // TODO
    int length=data.size();
    int r=generator.size();
    for(int i=0;i<=length-r;i++){
        if(data[i]-'0'==0)continue;
        for(int j=i,k=0;j<(i+r);j++,k++){
            int num=data[j]-'0';
            int g=generator[k]-'0';
            if((num == 0 && g == 1) || (num==1 && g==0)){
                data[j]='1';
            }
            else{
                data[j]='0';
            }
        }
    }
    return data.substr(r-1);
}

/**
 * Compute the CRC codeword by appending remainder to `message`.
 */
string generateCRC(const string &message, const string &generator) {
    // TODO:
    // 1) Append generator.size() - 1 zeros to message
    // 2) find remainder using above function
    // 3) return message + rem
    string s=message;
    int n=generator.size() -1;
    s.append(n,'0');
    string rem=modulo2Division(s, generator);
    return message+rem;
}

/**
 * Verify if `received` is error-free under given `generator`.
 * Returns true if remainder is all zeros, false otherwise.
 */
bool checkCRC(const string &received, const string &generator) {
    // TODO:
    // Compute remainder of `received` by `generator`.
    // If remainder is all '0', return true, else false.
    string s="";
    s.append(generator.size()-1, '0');
    if(modulo2Division(received, generator).compare(s) == 0)return true;
    return false;
}
