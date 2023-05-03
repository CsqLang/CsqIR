#if !defined(AST_H_IR)
#define AST_H_IR

#include "lexer.h"
#include <memory>



enum OptNodeType{
    VARDECL,
    VARASSIGN,
    VALUE,
    BINOP,
    UNARY,
};

//Core node for IR
struct OptNode{
    OptNodeType type;
    OptNode(){}
    OptNode(OptNodeType type_){type = type_;}
};

#define OPTNODE shared_ptr<OptNode>

//Derived node types
struct OptValueNode : OptNode{
    string expr;
    OptValueNode(){type = VALUE; expr = "";}
    OptValueNode(string express){type = VALUE; expr = express;}
};

//BinOP node
struct OptBinNode : OptNode{
    OPTNODE left;
    OPTNODE right;
    string opt;
    OptBinNode(){type = BINOP;}
    OptBinNode(OPTNODE LEFT, OPTNODE RIGHT, string OPERATOR){
        left = LEFT;
        right = RIGHT;
        opt = OPERATOR;
        type = BINOP;
    }  
};




#endif // AST_H_IR
