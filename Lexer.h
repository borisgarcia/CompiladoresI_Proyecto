#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <functional>
#include <deque>

enum class Token : int
{
    //Terminales
    IDENT               = 0,
    kw_INT              = 1,
    kw_CHAR             = 2,
    kw_BOOLEAN          = 3,
    kw_TRUE             = 4,
    kw_FALSE            = 5,
    kw_VOID             = 6,
    kw_IF               = 7,
    kw_ELSE             = 8,
    kw_ELSEIF           = 9,
    kw_WHILE            = 10,
    kw_FOR              = 11,
    
    ASSIGN_OP           = 16,
    INCREMENT_OP        = 17,
    DECREMENT_OP        = 18,

    AND_OP              = 19,
    OR_OP               = 20,
    EQUAL_OP            = 21,
    GREATER_OP          = 22,
    LESS_OP             = 23,
    NOT_EQUAL_OP        = 24,
    LESS_EQUAL_OP       = 25,
    GREATER_EQUAL_OP    = 26,
    SEMICOLON           = 27,
    COMMA               = 28,
    POINTER             = 29,
    MEMORYDIR           = 30,

    CADENA              = 31,
    NUMBER              = 32,
    kw_PRINTF           = 33,
    kw_SCANF            = 34,
    kw_RETURN           = 35,

    OPENPAR             = 36,
    CLOSEPAR            = 37,
    OPENBRACE           = 38,
    CLOSEBRACE          = 39,
    OPENBRACKET         = 40,
    CLOSEBRACKET        = 41,

    ADD_OP              = 42,
    SUB_OP              = 43,
    DIV_OP              = 44,
    MULTI_OP            = 45,
    MOD_OP              = 46,

    CADENA              = 47,
    LETRA               = 48,

    //No Term

    //Especial
    Top                 = 200,
    Eof                 = 201,
    Unknown             = 202,
    Null                = 203
};

class Lexer
{
    public:
        Lexer(char * path);
        Token getNextToken();
        void getToken();
        std::string getText();

    private:
        std::ifstream file;
        void initLexer();
        int currCh;
        void ungetChar();
        int getNextChar();
        
        std::string getSequence(std::function<bool(char)>func)
        {
            std::string temp; 
            
            while(func(currCh))
            {
                temp += char(currCh);
                currCh = getNextChar();
            }
            return temp;
        }
    
        std::string tk;
        
};