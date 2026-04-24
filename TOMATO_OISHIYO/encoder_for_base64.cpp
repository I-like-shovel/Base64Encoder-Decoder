#include <iostream>
#include <sstream>
#include <string>
#include <openssl/sha.h>
#include <vector>
#define ARRAY_SIZ 5000
static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}


std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
using namespace std;
string ret;

int i = 0;
int j = 0;

unsigned char array_3[3];
unsigned char array_4[4];

while (in_len--){
    array_3[i++] = *(bytes_to_encode++);

    if (i == 3) {
    array_4[0] = (array_3[0] & 0xfc) >> 2;
    array_4[1] = ((array_3[0] & 0x03) << 4) + ((array_3[1] & 0xf0) >> 4);
    array_4[2] = ((array_3[1] & 0x0f) << 2) + ((array_3[2] & 0xc0) >> 6);
    array_4[3] = array_3[2] & 0x3f;

for(i = 0; (i <4) ; i++)
        ret += base64_chars[array_4[i]];
        i = 0;
    }
}

if (i){
    for(j = i; j < 3; j++)
    array_3[j] = '\0';

    array_4[0] = (array_3[0] & 0xfc) >> 2;
    array_4[1] = ((array_3[0] & 0x03) << 4) + ((array_3[1] & 0xf0) >> 4);
    array_4[2] = ((array_3[1] & 0x0f) << 2) + ((array_3[2] & 0xc0) >> 6);
    array_4[3] = array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
ret += base64_chars[array_4[j]];

    while((i++ < 3))
ret += '=';

}

  return ret;

}


int main(){
while(true){
    std::cout<<">";
    unsigned char input[ARRAY_SIZ];
    int crash=0;
    std::cin>>input;
    for(int i=0;input[i]!='\0';++i){
        ++crash;
    }
    int len=0;
    len = sizeof(input) / sizeof(input[0]);
    len -= ARRAY_SIZ-crash;

    std::cout <<"input : "<< input << std::endl;
    std::cout <<"encode : "<< base64_encode(input, len)<< std::endl;
}
}