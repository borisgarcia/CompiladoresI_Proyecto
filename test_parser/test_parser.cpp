#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Lexer.h"
#include <fstream>

TEST_CASE("Test_Id"){
    Lexer l("../Files/test_id.txt");
    
    //char test_char;
    CHECK(l.getNextToken() == Token::kw_CHAR);
    CHECK(l.getText() == "char");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "test_char");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    //bool ____123___boolllll__12313123;
    CHECK(l.getNextToken() == Token::kw_BOOLEAN);
    CHECK(l.getText() == "bool");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "____123___boolllll__12313123");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    //int _NUMBER_1_234;
    CHECK(l.getNextToken() == Token::kw_INT);
    CHECK(l.getText() == "int");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "_number_1_234");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    //char _;
    CHECK(l.getNextToken() == Token::kw_CHAR);
    CHECK(l.getText() == "char");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "_");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    //int _123;
    CHECK(l.getNextToken() == Token::kw_INT);
    CHECK(l.getText() == "int");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "_123");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    //bool exist;
    CHECK(l.getNextToken() == Token::kw_BOOLEAN);
    CHECK(l.getText() == "bool");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "exist");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    CHECK(l.getNextToken() == Token::Eof);
}

TEST_CASE("Test_For"){
    Lexer l("../Files/test_for.txt");

    //for(int i = 0; i<56; i++){
    CHECK(l.getNextToken() == Token::kw_FOR);
    CHECK(l.getText() == "for");
    CHECK(l.getNextToken() == Token::OPENPAR);
    CHECK(l.getText() == "(");
    CHECK(l.getNextToken() == Token::kw_INT);
    CHECK(l.getText() == "int");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "i");
    CHECK(l.getNextToken() == Token::ASSIGN_OP);
    CHECK(l.getText() == "=");
    CHECK(l.getNextToken() == Token::NUMBER);
    CHECK(l.getText() == "0");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "i");
    CHECK(l.getNextToken() == Token::LESS_OP);
    CHECK(l.getText() == "<");
    CHECK(l.getNextToken() == Token::NUMBER);
    CHECK(l.getText() == "56");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "i");
    CHECK(l.getNextToken() == Token::INCREMENT_OP);
    CHECK(l.getText() == "++");
    CHECK(l.getNextToken() == Token::CLOSEPAR);
    CHECK(l.getText() == ")");
    CHECK(l.getNextToken() == Token::OPENBRACE);
    CHECK(l.getText() == "{");
    //x = 89;
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "x");
    CHECK(l.getNextToken() == Token::ASSIGN_OP);
    CHECK(l.getText() == "=");
    CHECK(l.getNextToken() == Token::NUMBER);
    CHECK(l.getText() == "89");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    //y = 45;
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "y");
    CHECK(l.getNextToken() == Token::ASSIGN_OP);
    CHECK(l.getText() == "=");
    CHECK(l.getNextToken() == Token::NUMBER);
    CHECK(l.getText() == "45");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    CHECK(l.getNextToken() == Token::CLOSEBRACE);
    CHECK(l.getText() == "}");
    CHECK(l.getNextToken() == Token::Eof);
}

TEST_CASE("Test_Comment"){  
    Lexer l("../Files/test_comment.txt");

    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "x");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "y");
    CHECK(l.getNextToken() == Token::ADD_OP);
    CHECK(l.getText() == "+");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "x");
    CHECK(l.getNextToken() == Token::Eof);
}

TEST_CASE("Test_If_Else"){  
    Lexer l("../Files/test_if_else.txt");

    CHECK(l.getNextToken() == Token::kw_IF);
    CHECK(l.getText() == "if");
    CHECK(l.getNextToken() == Token::OPENPAR);
    CHECK(l.getText() == "(");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "x");
    CHECK(l.getNextToken() == Token::EQUAL_OP);
    CHECK(l.getText() == "==");
    CHECK(l.getNextToken() == Token::kw_TRUE);
    CHECK(l.getText() == "true");
    CHECK(l.getNextToken() == Token::AND_OP);
    CHECK(l.getText() == "&&");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "y");
    CHECK(l.getNextToken() == Token::NOT_EQUAL_OP);
    CHECK(l.getText() == "!=");
    CHECK(l.getNextToken() == Token::kw_FALSE);
    CHECK(l.getText() == "false");
    CHECK(l.getNextToken() == Token::CLOSEPAR);
    CHECK(l.getText() == ")");
    CHECK(l.getNextToken() == Token::OPENBRACE);
    CHECK(l.getText() == "{");
    CHECK(l.getNextToken() == Token::CLOSEBRACE);
    CHECK(l.getText() == "}");
    CHECK(l.getNextToken() == Token::kw_ELSEIF);
    CHECK(l.getText() == "else if");
    CHECK(l.getNextToken() == Token::OPENPAR);
    CHECK(l.getText() == "(");
    CHECK(l.getNextToken() == Token::NOT);
    CHECK(l.getText() == "!");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "z");
    CHECK(l.getNextToken() == Token::OR_OP);
    CHECK(l.getText() == "||");
    CHECK(l.getNextToken() == Token::NOT);
    CHECK(l.getText() == "!");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "xy");
    CHECK(l.getNextToken() == Token::CLOSEPAR);
    CHECK(l.getText() == ")");
    CHECK(l.getNextToken() == Token::OPENBRACE);
    CHECK(l.getText() == "{");
    CHECK(l.getNextToken() == Token::CLOSEBRACE);
    CHECK(l.getText() == "}");
    CHECK(l.getNextToken() == Token::kw_ELSE);
    CHECK(l.getText() == "else");
    CHECK(l.getNextToken() == Token::OPENBRACE);
    CHECK(l.getText() == "{");
    CHECK(l.getNextToken() == Token::CLOSEBRACE);
    CHECK(l.getText() == "}");
    CHECK(l.getNextToken() == Token::Eof);
}

TEST_CASE("Test_Main"){      
    Lexer l("../Files/test_main.txt");

    CHECK(l.getNextToken() == Token::kw_INT);
    CHECK(l.getText() == "int");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "main");
    CHECK(l.getNextToken() == Token::OPENPAR);
    CHECK(l.getText() == "(");
    CHECK(l.getNextToken() == Token::CLOSEPAR);
    CHECK(l.getText() == ")");
    CHECK(l.getNextToken() == Token::OPENBRACE);
    CHECK(l.getText() == "{");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "x");
    CHECK(l.getNextToken() == Token::INCREMENT_OP);
    CHECK(l.getText() == "++");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "y");
    CHECK(l.getNextToken() == Token::DECREMENT_OP);
    CHECK(l.getText() == "--");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    CHECK(l.getNextToken() == Token::kw_RETURN);
    CHECK(l.getText() == "return");
    CHECK(l.getNextToken() == Token::NUMBER);
    CHECK(l.getText() == "0");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    CHECK(l.getNextToken() == Token::CLOSEBRACE);
    CHECK(l.getText() == "}");
    CHECK(l.getNextToken() == Token::Eof);
}

TEST_CASE("Test_Method"){
    
    Lexer l("../Files/test_method.txt");

    CHECK(l.getNextToken() == Token::kw_INT);
    CHECK(l.getText() == "int");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "method1");
    CHECK(l.getNextToken() == Token::OPENPAR);
    CHECK(l.getText() == "(");
    CHECK(l.getNextToken() == Token::CLOSEPAR);
    CHECK(l.getText() == ")");
    CHECK(l.getNextToken() == Token::OPENBRACE);
    CHECK(l.getText() == "{");
    CHECK(l.getNextToken() == Token::CLOSEBRACE);
    CHECK(l.getText() == "}");
    CHECK(l.getNextToken() == Token::kw_VOID);
    CHECK(l.getText() == "void");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "method2");
    CHECK(l.getNextToken() == Token::OPENPAR);
    CHECK(l.getText() == "(");
    CHECK(l.getNextToken() == Token::CLOSEPAR);
    CHECK(l.getText() == ")");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    CHECK(l.getNextToken() == Token::kw_CHAR);
    CHECK(l.getText() == "char");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "method3");
    CHECK(l.getNextToken() == Token::OPENPAR);
    CHECK(l.getText() == "(");
    CHECK(l.getNextToken() == Token::kw_BOOLEAN);
    CHECK(l.getText() == "bool");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "b1");
    CHECK(l.getNextToken() == Token::CLOSEPAR);
    CHECK(l.getText() == ")");
    CHECK(l.getNextToken() == Token::OPENBRACE);
    CHECK(l.getText() == "{");
    CHECK(l.getNextToken() == Token::CLOSEBRACE);
    CHECK(l.getText() == "}");
    CHECK(l.getNextToken() == Token::Eof);
}

TEST_CASE("Test_While"){
   
    Lexer l("../Files/test_while.txt");

    CHECK(l.getNextToken() == Token::kw_WHILE);
    CHECK(l.getText() == "while");
    CHECK(l.getNextToken() == Token::OPENPAR);
    CHECK(l.getText() == "(");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "x");
    CHECK(l.getNextToken() == Token::GREATER_OP);
    CHECK(l.getText() == ">");
    CHECK(l.getNextToken() == Token::NUMBER);
    CHECK(l.getText() == "9");
    CHECK(l.getNextToken() == Token::AND_OP);
    CHECK(l.getText() == "&&");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "y");
    CHECK(l.getNextToken() == Token::LESS_OP);
    CHECK(l.getText() == "<");
    CHECK(l.getNextToken() == Token::NUMBER);
    CHECK(l.getText() == "0");
    CHECK(l.getNextToken() == Token::CLOSEPAR);
    CHECK(l.getText() == ")");
    CHECK(l.getNextToken() == Token::OPENBRACE);
    CHECK(l.getText() == "{");
    CHECK(l.getNextToken() == Token::CLOSEBRACE);
    CHECK(l.getText() == "}");
    CHECK(l.getNextToken() == Token::kw_WHILE);
    CHECK(l.getText() == "while");
    CHECK(l.getNextToken() == Token::OPENPAR);
    CHECK(l.getText() == "(");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "z");
    CHECK(l.getNextToken() == Token::GREATER_EQUAL_OP);
    CHECK(l.getText() == ">=");
    CHECK(l.getNextToken() == Token::NUMBER);
    CHECK(l.getText() == "150");
    CHECK(l.getNextToken() == Token::OR_OP);
    CHECK(l.getText() == "||");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "l");
    CHECK(l.getNextToken() == Token::LESS_EQUAL_OP);
    CHECK(l.getText() == "<=");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "j");
    CHECK(l.getNextToken() == Token::CLOSEPAR);
    CHECK(l.getText() == ")");
    CHECK(l.getNextToken() == Token::OPENBRACE);
    CHECK(l.getText() == "{");
    CHECK(l.getNextToken() == Token::kw_INT);
    CHECK(l.getText() == "int");
    CHECK(l.getNextToken() == Token::IDENT);
    CHECK(l.getText() == "i1");
    CHECK(l.getNextToken() == Token::OPENBRACKET);
    CHECK(l.getText() == "[");
    CHECK(l.getNextToken() == Token::NUMBER);
    CHECK(l.getText() == "10");
    CHECK(l.getNextToken() == Token::CLOSEBRACKET);
    CHECK(l.getText() == "]");
    CHECK(l.getNextToken() == Token::SEMICOLON);
    CHECK(l.getText() == ";");
    CHECK(l.getNextToken() == Token::CLOSEBRACE);
    CHECK(l.getText() == "}");
    CHECK(l.getNextToken() == Token::Eof);
}
