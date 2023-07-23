#include <iostream>
#include <string>
#include <cassert>

std::string caesarEncrypt(const std::string& input, int shift){
    std::string encrypted = "";
    for(auto ch: input){
        if(isalpha(ch)){
            if(isupper(ch)){
               char temp = (ch-'A'+shift)%26 + 'A';
               encrypted += (temp > 'Z' ? temp-26 : (temp < 'A' ? temp+26 : temp));
            }
            else{
                char temp = (ch-'a'+shift)%26 + 'a';
                encrypted += (temp > 'z' ? temp-26 : (temp < 'a' ? temp+26 : temp));
            }
        }
        else
            encrypted += ch; 
    }
    return encrypted;
}


std::string caesarDecrypt(const std::string& ciphertext, int shift)
{
    std::string decrypted{""};
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base - shift + 26) % 26 + base;
        }
        decrypted += c;
    }
    return decrypted;
}


void test_encrypt(){

    assert(caesarEncrypt("The quick brown fox jumps over the lazy dog", 5) == "Ymj vznhp gwtbs ktc ozrux tajw ymj qfed itl");
    assert(caesarEncrypt("Sphinx of black quartz, judge my vow", 9) == "Byqrwg xo kujlt zdjaci, sdmpn vh exf");
    assert(caesarEncrypt("Pack my box with five dozen liquor jugs", 10) == "Zkmu wi lyh gsdr psfo nyjox vsaeyb teqc");
    assert(caesarEncrypt("How vexingly quick daft zebras jump!", 1) == "Ipx wfyjohmz rvjdl ebgu afcsbt kvnq!");
    assert(caesarEncrypt("Waltz, bad nymph, for quick jigs vex.", 7) == "Dhsag, ihk uftwo, mvy xbpjr qpnz cle.");
    assert(caesarEncrypt("The five boxing wizards jump quickly", 6) == "Znk lobk hudotm cofgxjy pasv waoiqre");
    assert(caesarEncrypt("Cozy lummox gives smart squid who asks for job pen.", 4) == "Gsdc pyqqsb kmziw wqevx wuymh als ewow jsv nsf tir.");
    assert(caesarEncrypt("Jaded zombies acted quaintly but kept driving their oxen forward.", 3) == "Mdghg crpelhv dfwhg txdlqwob exw nhsw gulylqj wkhlu rahq iruzdug.");
    assert(caesarEncrypt("12345", 12) == "12345");
    assert(caesarEncrypt("May the d4ay wit@h yUo0", 8) == "Uig bpm l4ig eqb@p gCw0");
    assert(caesarEncrypt("", 1) == "");

    std::cout << "OK" << std::endl;
}


void test_decrypt(){
    assert(caesarDecrypt("Ymj vznhp gwtbs ktc ozrux tajw ymj qfed itl", 5) == "The quick brown fox jumps over the lazy dog");
    assert(caesarDecrypt("Zkmu wi lyh gsdr psfo nyjox vsaeyb teqc", 10) == "Pack my box with five dozen liquor jugs");
    assert(caesarDecrypt("Uig bpm l4ig eqb@p gCw0", 8) == "May the d4ay wit@h yUo0");
    assert(caesarDecrypt("12345", 5) == "12345");
    assert(caesarDecrypt("", 1) == "");

    std::cout << "OK" << std::endl;
}


int main(){
    test_encrypt();
    test_decrypt();
}