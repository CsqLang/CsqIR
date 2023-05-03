#include <memory>
#include "lexer.h"
#include "error.h"

enum OptNodeType {
    VARDECL,
    VARASSIGN,
    VALUE,
    BINOP,
    UNARY,
};

enum OptValueType {
    STR,
    NUM,
};

struct OptNode {
    OptNodeType type;
    OptNode() {}
    OptNode(OptNodeType type_) { type = type_; }
};

#define OPTNODE std::shared_ptr<OptNode>

struct OptValueNode : OptNode {
    std::string expr;
    OptValueType val_type;
    OptValueNode() { type = VALUE; expr = ""; }
    OptValueNode(std::string express, OptValueType type_) {
        type = VALUE;
        val_type = type_;
        expr = express;
    }
};

struct OptBinNode : OptNode {
    OPTNODE left;
    OPTNODE right;
    std::string opt;
    OptBinNode() { type = BINOP; }
    OptBinNode(OPTNODE left_, OPTNODE right_, std::string operator_) {
        left = left_;
        right = right_;
        opt = operator_;
        type = BINOP;
    }
};

string visit(shared_ptr<OptValueNode> value) {
    return value->expr;
}

string evaluateBinaryExpr(shared_ptr<OptBinNode> node) {
    if(static_pointer_cast<OptValueNode>(node->left)->val_type == STR){
        if(static_pointer_cast<OptValueNode>(node->right)->val_type == STR){
            string leftValue = visit(static_pointer_cast<OptValueNode>(node->left));
            string rightValue = visit(static_pointer_cast<OptValueNode>(node->right));
            if (node->opt == "+") {
                return "\"" + leftValue + rightValue + "\"";
            } 
            else {
                error("Unexpected operator " + node->opt + " used between \""+leftValue+"\" and \"" + rightValue + "\".");
                return "";
            }
        }
        else{
            error("Couldn't add operand of type Number and String.");
            return "";
        }
    }
    else if(static_pointer_cast<OptValueNode>(node->left)->val_type == NUM){
        if(static_pointer_cast<OptValueNode>(node->right)->val_type == NUM){
            double leftValue = stod(visit(static_pointer_cast<OptValueNode>(node->left)));
            double rightValue = stod(visit(static_pointer_cast<OptValueNode>(node->right)));
            if (node->opt == "+") {
                return to_string(leftValue + rightValue);
            }
            else {
                error("Unknown token " + node->opt + ".");
                return "";
            }
        }
        else{
            error("Couldn't add operand of type Number and String.");
            return "";
        }
    }
}
OPTNODE addNode(OptValueNode val){
    auto node = make_shared<OptValueNode>();
    node->expr = val.expr;
    node->val_type = val.val_type;
    return static_pointer_cast<OptNode>(node);
}
