#include "Lexer.h"

class Parser
{
    
    public:
        Parser(Lexer &lexer):lexer(lexer){}
        void initParser();
    
    private:
        Token token;
        Lexer &lexer;
        void input();
        void stmt_list();
        void p_stmt_list();
        void p_stmt_list_2();
        void declar();
        void pointer();
        void array();
        void size();
        void p_declar();
        void declarvar();
        void value();
        void p_value();
        void p_value_2();
        void declarfn();
        void p_declarfn();
        void whilestmt();
        void forstmt();
        void fordeclar();
        void forassign();
        void ifstmt();
        void elsestmt();
        void p_elsestmt();
        void statement();
        void p_statement();
        void assignOP();
        void op();
        void condicion();
        void p_condicion();
        void opcondi();
        void type();
        void expr();
        void p_expr();
        void term();
        void p_term();
        void factor();
        void parametros();
        void p_parametros();
        void _return();

};



