#ifndef BYBLIK_H
#define BYBLIK_H

#include <string>

class byblik {
public:
    byblik(int numColumns);

    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);

private:
    int numColumns;
};

#endif
