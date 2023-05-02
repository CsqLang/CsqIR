#if !defined(TOKEN_CSQIR)
#define TOKEN_CSQIR

//Token types for IR
//
//
enum IR_TokenType{
    OPT,
    NAME,
    LITERAL
};

enum OPTS{
    LOADVAR,
    LOADFUN,
    ASSIGN,
    ADD,
    SUB,
    MUL,
    DIV,
};

enum LITERALS{
    STRING,
    NUMBER,
    BOOLEAN,
};


#endif // TOKEN_CSQIR
