#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cctype>

enum TokenType {
    RETURN,
    INTEGER,
    SEMICOLON,
    IDENTIFIER,
    ASSIGN,
    INT_TYPE,
    STRING_TYPE,
    CHAR_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

Token tokenize(const std::string& sourceCode) {
    Token token;
    token.type = UNKNOWN;
    token.value.clear();

    // Tokenization logic for other token types
    // ...

    // Variable Declaration or Assignment
    size_t colonPos = sourceCode.find(':');
    size_t assignPos = sourceCode.find('=');
    if (colonPos != std::string::npos && assignPos != std::string::npos &&
        colonPos < assignPos) {
        token.type = IDENTIFIER;
        token.value = sourceCode.substr(4, colonPos - 4); // Extract variable name
        token.type = ASSIGN;
        token.value = sourceCode.substr(assignPos + 1); // Extract assigned value
    }

    return token;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    // Check if the file has the .fa extension
    if (filename.find(".fa") == std::string::npos) {
        std::cerr << "Error: The file must have a .fa extension." << std::endl;
        return 1;
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return 1;
    }

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::string delimiter = " \t;\n\r";
    size_t pos = 0;
    std::string token;
    while ((pos = fileContent.find_first_of(delimiter)) != std::string::npos) {
        token = fileContent.substr(0, pos);
        fileContent.erase(0, pos + 1); // Erase the token and the delimiter from fileContent
        Token currentToken = tokenize(token);

        switch (currentToken.type) {
            case INT_TYPE:
                std::cout << "Variable Type: INT, Name: " << currentToken.value << std::endl;
                break;
            case STRING_TYPE:
                std::cout << "Variable Type: STRING, Name: " << currentToken.value << std::endl;
                break;
            case CHAR_TYPE:
                std::cout << "Variable Type: CHAR, Name: " << currentToken.value << std::endl;
                break;
            case FLOAT_TYPE:
                std::cout << "Variable Type: FLOAT, Name: " << currentToken.value << std::endl;
                break;
            case DOUBLE_TYPE:
                std::cout << "Variable Type: DOUBLE, Name: " << currentToken.value << std::endl;
                break;
            case IDENTIFIER:
                std::cout << "Variable Declaration: " << currentToken.value << std::endl;
                break;
            case ASSIGN:
                std::cout << "Assignment: " << currentToken.value << std::endl;
                break;
            default:
                std::cout << "Token Type: UNKNOWN, Value: " << currentToken.value << std::endl;
                break;
        }
    }

    return 0;
}