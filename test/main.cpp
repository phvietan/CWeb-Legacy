#include "cryptopp/dll.h"  
#include "cryptopp/default.h"
#include "cryptopp/hex.h"
#include <iostream>

using namespace CryptoPP;
using namespace std;

string hexDecode(const string s) {
  string res;
  StringSource hd(s, true /*pumpAll*/,
    new HexDecoder(
      new StringSink(res)
    )
  );
  return res;
}

string hexEncode(const string s) {
  string res;
  StringSource he(s, true /*pumpAll*/,
    new HexEncoder(
      new StringSink(res)
    )
  );
  return res;
}

string getPrf(const string key, const string m) {
  try {
    string res;
    HMAC< SHA256 > hmac((byte*)key.c_str(), key.size());
    StringSource ss2(m, true, 
        new HashFilter(hmac,
            new StringSink(res)
        )   
    );
    return res;
  } catch (const CryptoPP::Exception& e)
  {
      cerr << e.what() << endl;
      exit(1);
  }
}

string get00(const string aesKey, const string prfL, const string word) {
  string trapdoor = getPrf(aesKey, word);
  int n = 32;
  while (n--) trapdoor = getPrf(prfL, trapdoor);
  return hexEncode(trapdoor);
}

int main() {
  string target = hexDecode("360e5289e3898c60a338872e9a01845635292564b52b2f21d217400796ea5143");
  string prfL = hexDecode("0be8f2e1f8a73832a77d22e78bd1715ffef212f49912132ef86737abbb37eb38");
  string aesKey = hexDecode("8b2e094c5f659bdf3a193e2c6dcfc5d9cbe09bd153174598d55a9452a6752403");

  string word = "hello world";
  string t00 = get00(aesKey, prfL, word);

  cout << t00 << endl;

  return 0;
}