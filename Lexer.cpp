#include "Lexer.h"

Lexer::Lexer(char * path)
{
    file.open(path, std::ifstream::in);
    initLexer();
}

std::string Lexer::getText()
{
    return tk;
}

int Lexer::getNextChar()
{
    return file.get();
}

void Lexer::ungetChar()
{
    file.unget();
}

void Lexer::initLexer()
{
    currCh = getNextChar();
}

void Lexer::getToken()
{
    //std::cout<<"----------Init Lexer----------"<<std::endl;
    while(currCh != EOF )
    {
        Token res = getNextToken();     

        //std::cout<<"Token: "<<tk<<" es de tipo: "<<TokenValue(res)<<std::endl;
    }
    file.close();
}

Token Lexer::getNextToken()
{ 
    tk = "";
    while(1) 
    {
        if(currCh == EOF)
        {
            return Token::Eof;
        }
        else if(currCh == ' ' || currCh == '\t' || currCh == '\n')
        {
            currCh = getNextChar();
            continue;
        }
        else if(currCh == '/')
        {
            currCh = getNextChar();
            tk += char(currCh);

            if(currCh == '/')
            {
                while(currCh != '\n')
                {
                    currCh = getNextChar();
                    if(currCh == EOF)
                        return Token::Eof;
                }   
                continue;
            }
            else if(currCh == '*')
            {
                while(1)
                {
                    currCh = getNextChar();
                    if(currCh == '*')
                    {
                        currCh = getNextChar();
                        if(currCh == '/')
                        {
                            currCh = getNextChar();
                            break;
                        }
                    }
                    if(currCh == EOF)
                        return Token::Eof;
                }   
                continue;
            }
            else if(currCh == '=')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::ASSIGN_OP;
            }
            else   
                return Token::DIV_OP;
        }
        else if(isdigit(currCh))
        {
            tk += char(currCh);
            currCh = getNextChar();
            std::string s = getSequence(isdigit);
            tk += s;
            //std::cout << tk;
            return Token::NUMBER;
            
        }
        else if(isalpha(currCh) || currCh == '_')
        {
            std::string s = getSequence([](char ch){ return ch == '_' || isalpha(ch) || isdigit(ch);});
            tk = s;
            if(s.empty())
                return Token::Unknown;
            
            else if(s == "if")
                return Token::kw_IF;
            
            else if(s == "else")
            {
                int temp = file.tellg();
                currCh = getNextChar();
                std::string s2 = getSequence(isalpha);
                if(s2 == "if")
                {
                    tk += " "+s2;
                    return Token::kw_ELSEIF;
                }
                else
                {
                    file.seekg(temp);
                    return Token::kw_ELSE;
                }
            }
            else if(s == "int")
                return Token::kw_INT;
            
            else if(s == "char")
                return Token::kw_CHAR;
            
            else if(s == "bool")
                return Token::kw_BOOLEAN;
            
            else if(s == "true")
                return Token::kw_TRUE;
            
            else if(s == "false")
                return Token::kw_FALSE;
            
            else if(s == "printf")
                return Token::kw_PRINTF;
            
            else if(s == "scanf")
                return Token::kw_SCANF;
                            
            else if(s == "return")
                return Token::kw_RETURN;
                
            else if(s == "void")
                return Token::kw_VOID;
                
            else if(s == "while")
                return Token::kw_WHILE;
                
            else if(s == "for")
                return Token::kw_FOR;
                
            else
                return Token::IDENT;
            
        }
        else if(currCh == '*')
        {
            tk += char(currCh);
            currCh = getNextChar();
            if(currCh == '=')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::ASSIGN_MUL_OP;
            }
            return Token::MULTI_OP;
        }
        else if(currCh == '+')
        {
            tk += char(currCh);
            currCh = getNextChar();
            if(currCh == '=')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::ASSIGN_ADD_OP;
            }
            else if(currCh == '+')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::INCREMENT_OP;
            }
            return Token::ADD_OP;
        }
        else if(currCh == '-')
        {
            tk += char(currCh);
            currCh = getNextChar();
            if(currCh == '=')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::ASSIGN_SUB_OP;
            }
            else if(currCh == '-')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::DECREMENT_OP;
            }
            return Token::SUB_OP;
        }
        else if(currCh == '=')
        {
            tk += char(currCh);
            currCh = getNextChar();
            if(currCh == '=')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::EQUAL_OP;
            }
            return Token::ASSIGN_OP;
        }
        else if(currCh == '&')
        {
            tk += char(currCh);
            currCh = getNextChar();
            if(currCh == '&')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::AND_OP;
            }
            return Token::MEMORYDIR;
        }
        else if(currCh == '|')
        {
            tk += char(currCh);
            currCh = getNextChar();
            if(currCh == '|')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::OR_OP;
            }
            return Token::Unknown;
        }
        else if(currCh == '>')
        {
            tk += char(currCh);
            currCh = getNextChar();
            if(currCh == '=')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::GREATER_EQUAL_OP;
            }
            return Token::GREATER_OP;
        }
        else if(currCh == '<')
        {
            tk += char(currCh);
            currCh = getNextChar();
            if(currCh == '=')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::LESS_EQUAL_OP;
            }
            return Token::LESS_OP;
        }
        else if(currCh == '!')
        {
            tk += char(currCh);
            currCh = getNextChar();
            if(currCh == '=')
            {
                tk += char(currCh);
                currCh = getNextChar();
                return Token::NOT_EQUAL_OP;
            }
            return Token::Unknown;
        }
        else if(currCh == ';')
        {
            tk += char(currCh);
            currCh = getNextChar();
            return Token::SEMICOLON;
        }
        else if(currCh == ',')
        {
            tk += char(currCh);
            currCh = getNextChar();
            return Token::COMMA;
        }
        else if(currCh == '(')
        {
            tk += char(currCh);
            currCh = getNextChar();
            return Token::OPENPAR;
        }
        else if(currCh == ')')
        {
            tk += char(currCh);
            currCh = getNextChar();
            return Token::CLOSEPAR;
        }
        else if(currCh == '{')
        {
            tk += char(currCh);
            currCh = getNextChar();
            return Token::OPENBRACE;
        }
        else if(currCh == '}')
        {
            tk += char(currCh);
            currCh = getNextChar();
            return Token::CLOSEBRACE;
        }
        else if(currCh == '[')
        {
            tk += char(currCh);
            currCh = getNextChar();
            return Token::OPENBRACKET;
        }
        else if(currCh == ']')
        {
            tk += char(currCh);
            currCh = getNextChar();
            return Token::CLOSEBRACKET;
        }
        else if(currCh == '%')
        {
            tk += char(currCh);
            currCh = getNextChar();
            return Token::MOD_OP;
        }
        else if(currCh == '\"')
        {
            currCh = getNextChar();
            while(currCh != '\"')
            {
                tk += currCh;
                currCh = getNextChar();
            }
            currCh = getNextChar();
            return Token::CADENA;
        }
        else if(currCh == '\'')
        {
            currCh = getNextChar();
            tk += currCh;
            currCh = getNextChar();
            if(currCh == '\"')
            {
                currCh = getNextChar();
                return Token::LETRA;
            }
            else
            {
                return Token::Unknown;
            }
        }
        else
        {
            return Token::Unknown;
        }
    }
}
