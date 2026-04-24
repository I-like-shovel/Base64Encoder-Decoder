#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#define ARRAY_SIZ 100000

static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_decode(unsigned char const* decoded_string, unsigned int in_len) {
using namespace std;
string ret;

int i = 0;
int j = 0;
int in_ = 0;
unsigned char array_3[3], array_4[4];

while (in_len-- && ( decoded_string[in_] != '=') && is_base64(decoded_string[in_])) {

    array_4[i++] = decoded_string[in_]; in_++;

    if (i ==4) {
        for (i = 0; i <4; i++)
        array_4[i] = base64_chars.find(array_4[i]);

        array_3[0] = (array_4[0] << 2) + ((array_4[1] & 0x30) >> 4);
        array_3[1] = ((array_4[1] & 0xf) << 4) + ((array_4[2] & 0x3c) >> 2);
        array_3[2] = ((array_4[2] & 0x3) << 6) + array_4[3];

        for (i = 0; (i < 3); i++)
            ret += array_3[i];

i = 0;
    }
}

if (i) {
    for (j = i; j <4; j++)
        array_4[j] = 0;

    for (j = 0; j <4; j++)
        array_4[j] = base64_chars.find(array_4[j]);

        array_3[0] = (array_4[0] << 2) + ((array_4[1] & 0x30) >> 4);
        array_3[1] = ((array_4[1] & 0xf) << 4) + ((array_4[2] & 0x3c) >> 2);
        array_3[2] = ((array_4[2] & 0x3) << 6) + array_4[3];

    for (j = 0; (j < i - 1); j++) ret += array_3[j];
}

    return ret;
}

int main(){
while(true){
    unsigned char input[ARRAY_SIZ];
    unsigned char *quit;
    std::cout<<">";
    int crash=0;
    std::cin>>input;
    for(int i=0;input[i]!='\0';++i){
        ++crash;
    }
    int len=0;
    len = sizeof(input) / sizeof(input[0]);
    len -= ARRAY_SIZ-crash;
    std::cout <<"input : "<< input << std::endl;
    std::cout <<"decode : " << base64_decode(input, len)<< std::endl;
}
}