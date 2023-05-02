#if !defined(LEXER_IR)
#define LEXER_IR

#include "token.h"
#include "stack.h"

struct OptToken{
    string token;
    IR_TokenType type;
};

typedef vector<OptToken> OptTokenStream;
typedef vector<string> OptStringStream;

/*

a = 46+564 -> LOADVAR a 46 ADD 564

*/

#define NUMBER_CHECK(token) token[0] == '0' || token[0] == '1' || token[0] == '2' || token[0] == '3' || token[0] == '4' || token[0] == '5' || token[0] == '6' || token[0] == '7' || token[0] == '8' || token[0] == '9'

OptTokenStream tokenizeOptCode(vector<OptStringStream> code){
    OptTokenStream tokens;
    for(OptStringStream stream : code){
        for(string token : stream){
            if(token == "LOADVAR" || token == "ASSIGN" || token == "LOADFUN" ||
               token == "ADD" || token == "MUL" || token == "SUB" || token == "DIV"
            ){
                OptToken token_;
                token_.token = token;
                token_.type = OPT;
                tokens.push_back(token_);
            }
            else if((token[0] == '\"' && token[token.size()-1] == '\"') || (NUMBER_CHECK(token))){
                OptToken token_;
                token_.token = token;
                token_.type = LITERAL;
                tokens.push_back(token_);
            }
            else{
                OptToken token_;
                token_.token = token;
                token_.type = NAME;
                tokens.push_back(token_);
            }
        }
    }
    return tokens;
}

#endif // LEXER_IR
