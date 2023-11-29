#include "TableTranspositionCipher.h"
#include <vector>
TableTranspositionCipher::TableTranspositionCipher(int numColumns) :
    numColumns(numColumns) {}
//std::string TableTranspositionCipher::encrypt(std::string& plaintext)
//{
//std::string ciphertext;
//while(plaintext.size()%numColumns!=0) {
//   plaintext+=" ";
//}
std::string TableTranspositionCipher::encrypt(std::string& plaintext)
{
    std::string ciphertext;
    int numRows = (plaintext.length() + numColumns - 1) / numColumns;
    std::vector<std::string> table(numRows, std::string(numColumns, '*'));
    int index = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = numColumns - 1; j >= 0; j--) {
            if (index < plaintext.length()) {
                table[i][j] = plaintext[index++];
            }
        }
    }
    for (int j = 0; j < numColumns; j++) {
        for (int i = 0; i < numRows; i++) {
            ciphertext += table[i][j];
        }
    }
    return ciphertext;
}
std::string TableTranspositionCipher::decrypt(std::string& ciphertext)
{
    std::string decryptedText;
    int numRows = (ciphertext.length() + numColumns - 1) / numColumns;
    std::vector<std::string> table(numRows, std::string(numColumns, ' '));
    int index = 0;
    for (int j = 0; j < numColumns; j++) {
        for (int i = 0; i < numRows; i++) {
            if (index < ciphertext.length()) {
                table[i][j] = ciphertext[index++];
            }
        }
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            decryptedText += table[i][j];
        }
    }
    return decryptedText;
}
