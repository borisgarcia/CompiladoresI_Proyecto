#include "Parser.h"

void Parser::initParser()
{
    token = lexer.getNextToken();
    input();
    token = lexer.getNextToken();
    if(token != Token::Eof)
    {
        throw std::invalid_argument( "\nNot Eof" );
    }
    std::cout <<'\n'<< "Final" << '\n';
}

void Parser::input()
{
    stmt_list();
}

void Parser::stmt_list()
{
    if(token == Token::kw_VOID || token == Token::kw_INT || token == Token::kw_CHAR || token == Token::kw_BOOLEAN)
    {
        declar();
        stmt_list();
    }
    /*else if(token == Token::kw_FOR)
    {
        forstmt();
        stmt_list();
    }
    else if(token == Token::kw_WHILE)
    {
        whilestmt();
        stmt_list();
    }
    else if(token == Token::kw_IF)
    {
        ifstmt();
        stmt_list();
    }
    else if(token == Token::kw_PRINTF)
    {
        token = lexer.getNextToken();   
    }
    else if(token == Token::kw_SCANF)
    {
        token = lexer.getNextToken();
    }
    else if(token == Token::IDENT)
    {
        token = lexer.getNextToken();
        p_stmt_list();
        stmt_list();
    }*/
}

void Parser::p_stmt_list()
{
    if(token == Token::ASSIGN_OP)
    {
        token = lexer.getNextToken();
        expr();
        p_stmt_list_2();
        if(token != Token::SEMICOLON)
        {
            throw std::invalid_argument( "\np_stmt_list if" );
        }
        token = lexer.getNextToken();
    }
    else if(token == Token::OPENPAR)
    {
        token = lexer.getNextToken();
        if(token == Token::CLOSEPAR)
        {
            token = lexer.getNextToken();
            if(token != Token::SEMICOLON)
            {
                throw std::invalid_argument( "\np_stmt_list else if" );
            }
            token = lexer.getNextToken();
        }
    }
}

void Parser::p_stmt_list_2()
{
    if(token == Token::OPENPAR)
    {
        token = lexer.getNextToken();
        if(token == Token::CLOSEPAR)
        {
            token = lexer.getNextToken();
            if(token != Token::SEMICOLON)
            {
                throw std::invalid_argument( "\np_stmt_list_2" );
            }
            token = lexer.getNextToken();
        }
    }
}

void Parser::declar()
{
    if(token == Token::kw_INT || token == Token::kw_CHAR || token == Token::kw_BOOLEAN)
    {
        type();
        pointer();
        if(token == Token::IDENT);
        {
            token = lexer.getNextToken();
            array();
            p_declar();
            if(token != Token::SEMICOLON)
            {
                std::cout << "Semicolon" << '\n';
                throw std::invalid_argument( "\ndeclar" );
            }
            token = lexer.getNextToken();
        }
    }
    else if (token == Token::kw_VOID)
    {
        token = lexer.getNextToken();
        if(token == Token::IDENT)
        {
            token = lexer.getNextToken();
            declarfn();
        }
        
    }
}

void Parser::pointer()
{
    if (token == Token::MULTI_OP)
    {
        token = lexer.getNextToken();
    }
}

void Parser::array()
{
    if (token == Token::OPENBRACKET)
    {
        token = lexer.getNextToken();
        size();
        if (token != Token::CLOSEBRACKET)
        {
           throw std::invalid_argument( "\narray" );
        }
        token = lexer.getNextToken();
    }
}

void Parser::size()
{
    if (token == Token::NUMBER)
    {
        token = lexer.getNextToken();
    }
}

void Parser::p_declar()
{
    if(token == Token::OPENPAR)
    {
        declarfn();
    }
    else if(token == Token::COMMA || token == Token::ASSIGN_OP)
    {
        declarvar();
    }
}
void Parser::declarvar()
{
    if(token == Token::COMMA)
    {
        token = lexer.getNextToken();
        pointer();
        if(token == Token::IDENT)
        {
            token = lexer.getNextToken();
            array();
            declarvar();
        }
    }
    else if(token == Token::ASSIGN_OP)
    {
        token = lexer.getNextToken();
        value();
        declarvar();
    }
    
}

void Parser::value()
{
    if(token == Token::OPENBRACE)
    {
        token = lexer.getNextToken();
        p_value();
        if(token != Token::CLOSEBRACE)
        {
           throw std::invalid_argument( "\nvalue" );
        }
        token = lexer.getNextToken();
    }
    else
    {
        std::cout << "Else expr" << '\n';
        expr();
    }
}

void Parser::p_value()
{
    expr();
    p_value_2();
}

void Parser::p_value_2()
{
    if(token == Token::COMMA)
    {
        token = lexer.getNextToken();
        p_value();
    }
}

void Parser::declarfn()
{
    token = lexer.getNextToken();
    parametros();
    if(token == Token::CLOSEPAR)
    {
        token = lexer.getNextToken();
        p_declarfn();
    }
}
void Parser::p_declarfn()
{
    if(token == Token::SEMICOLON)
    {
        token = lexer.getNextToken();
    }
    else if(token == Token::OPENBRACE)
    {
        token = lexer.getNextToken();
        p_statement();
        _return();
        if(token != Token::CLOSEBRACE)
        {
           throw std::invalid_argument( "\np_declarfn" );
        }
        token = lexer.getNextToken();
    }
}

void Parser::parametros()
{
    if(token == Token::kw_INT || token == Token::kw_CHAR || token == Token::kw_BOOLEAN)
    {
        type();
        if(token == Token::IDENT)
        {
            token = lexer.getNextToken();
            p_parametros();
        }
    }
}
void Parser::p_parametros()
{
    if(token == Token::COMMA)
    {
        token = lexer.getNextToken();
        parametros();
    }
}

void Parser::whilestmt()
{
    if(token == Token::kw_WHILE)
    {
        token = lexer.getNextToken();
        if(token == Token::OPENPAR)
        {
            token = lexer.getNextToken();
            condicion();
            if(token != Token::CLOSEPAR)
            {
               throw std::invalid_argument( "\nwhilestmt" );
            }
            token = lexer.getNextToken();
            statement();
        }
    }
}
void Parser::forstmt()
{
    if(token == Token::kw_FOR)
    {
        token = lexer.getNextToken();
        if(token == Token::OPENPAR)
        {
            token = lexer.getNextToken();
            fordeclar();
            if(token == Token::SEMICOLON)
            {
                token = lexer.getNextToken();
                condicion();
                if(token == Token::SEMICOLON)
                {
                    token = lexer.getNextToken();
                    forassign();
                    if(token != Token::CLOSEPAR)
                    {
                       throw std::invalid_argument( "\nforstmt" );
                    }
                    token = lexer.getNextToken();
                    statement();
                }
            }           
        }
    }
}
void Parser::fordeclar()
{
    if(token == Token::kw_INT || token == Token::kw_CHAR || token == Token::kw_BOOLEAN)
    {
        type();
        if(token == Token::IDENT)
        {
            token = lexer.getNextToken();
            if(token == Token::ASSIGN_OP)
            {
                token = lexer.getNextToken();
                expr();
            }
        }
    }
    else if(token == Token::IDENT)
    {
        if(token == Token::IDENT)
        {
            token = lexer.getNextToken();
            if(token == Token::ASSIGN_OP)
            {
                token = lexer.getNextToken();
                expr();
            }
        }
    }
}
void Parser::forassign()
{
    op();
    if(token == Token::IDENT)
    {
        token = lexer.getNextToken();
        op();
        assignOP();
    }

}
void Parser::ifstmt()
{
    if(token == Token::kw_IF)
    {
        token = lexer.getNextToken();
        if(token == Token::OPENPAR)
        {
            token = lexer.getNextToken();
            condicion();
            if(token == Token::CLOSEPAR)
            {
                token = lexer.getNextToken();
                statement();
                elsestmt();
            }
        }
    }
}
void Parser::elsestmt()
{
    if(token == Token::kw_ELSE)
    {
        token = lexer.getNextToken();
        statement();
    }
    if(token == Token::kw_ELSEIF)
    {
        token = lexer.getNextToken();
        if(token == Token::OPENPAR)
        {
            token = lexer.getNextToken();
            condicion();
            if(token == Token::CLOSEPAR)
            {
                token = lexer.getNextToken();
                statement();
                elsestmt();
            }
        }
    }
}

void Parser::statement()
{
    if(token == Token::OPENBRACE)
    {
        token = lexer.getNextToken();
        p_statement();
        if(token != Token::CLOSEBRACE)
        {
            throw std::invalid_argument( "\nstatement" );
        }
        token = lexer.getNextToken();
    }
}
void Parser::p_statement()
{
    if(token == Token::kw_FOR)
    {
        forstmt();
        p_statement();
    }
    else if(token == Token::kw_WHILE)
    {
        whilestmt();
        p_statement();
    }
    else if(token == Token::kw_IF)
    {
        ifstmt();
        p_statement();
    }
    else if(token == Token::kw_PRINTF)
    {
        token = lexer.getNextToken();   
    }
    else if(token == Token::kw_SCANF)
    {
        token = lexer.getNextToken();
    }
    else if(token == Token::IDENT)
    {
        token = lexer.getNextToken();
        p_stmt_list();
        p_statement();
    }
    else if(token == Token::kw_INT || token == Token::kw_CHAR || token == Token::kw_BOOLEAN)
    {
        type();
        pointer();
        if(token == Token::IDENT)
        {
            token = lexer.getNextToken();
            array();
            declarvar();
        }
    }
}

void Parser::_return()
{
    if(token == Token::kw_RETURN)
    {
        token = lexer.getNextToken();
        expr();
        if(token != Token::SEMICOLON)
        {
            throw std::invalid_argument( "\nreturn" );
        }
        token = lexer.getNextToken();
    }
}

void Parser::assignOP()
{
    if(token == Token::ASSIGN_OP)
    {
        token = lexer.getNextToken();
        expr();
    }
}
void Parser::op()
{
    if(token == Token::INCREMENT_OP || token == Token::DECREMENT_OP)
    {
        token = lexer.getNextToken();
    }
}
void Parser::condicion()
{
    expr();
    opcondi();
    expr();
    p_condicion();

}
void Parser::p_condicion()
{
    if(token == Token::ADD_OP || token == Token::OR_OP)
    {
        token = lexer.getNextToken();
        condicion();
    }
}
void Parser::opcondi()
{
    if(token == Token::EQUAL_OP || token == Token::GREATER_OP || token == Token::LESS_OP || token == Token::GREATER_EQUAL_OP || token == Token::LESS_EQUAL_OP || token == Token::NOT_EQUAL_OP)
    {
        token = lexer.getNextToken();
    }
}
void Parser::type()
{
    if(token == Token::kw_INT || token == Token::kw_CHAR || token == Token::kw_BOOLEAN)
    {
        token = lexer.getNextToken();
    }
}
void Parser::expr()
{
    term();
    p_expr();
}
void Parser::p_expr()
{
    if(token == Token::ADD_OP || token == Token::SUB_OP)
    {
        token = lexer.getNextToken();
        term();
        p_expr();
    }
}
void Parser::term()
{
    factor();
    p_term();
}
void Parser::p_term()
{
    if(token == Token::ADD_OP || token == Token::SUB_OP)
    {
        token = lexer.getNextToken();
        factor();
        p_term();
    }
}
void Parser::factor()
{
    if(token == Token::IDENT || token == Token::NUMBER || token == Token::kw_TRUE || token == Token::kw_FALSE)
    {
        token = lexer.getNextToken();
    }
    else if(token == Token::OPENPAR)
    {
        token = lexer.getNextToken();
        expr();
        if(token != Token::CLOSEPAR)
        {
           throw std::invalid_argument( "\nfactor" );
        }
        token = lexer.getNextToken();
    }
}