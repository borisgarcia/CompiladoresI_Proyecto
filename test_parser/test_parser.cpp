#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Parser.h"

TEST_CASE("Test Ids") {   
    Lexer lexer("../Files/test_id.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test Comments") {   
    Lexer lexer("../Files/test_comment.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test For") {   
    Lexer lexer("../Files/test_for.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("If Test") {   
    Lexer lexer("../Files/test_if_else.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Main Test") {   
    Lexer lexer("../Files/test_main.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test Method") {   
    Lexer lexer("../Files/test_method.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test While") {   
    Lexer lexer("../Files/test_method.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}
