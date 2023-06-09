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
    FLOAT,
    INTEGER,
};

struct OptNode {
    OptNodeType type;
    OptNode() {}
    OptNode(OptNodeType type_) { type = type_; }
};

#define OPTNODE shared_ptr<OptNode>

struct OptValueNode : OptNode {
    string expr;
    OptValueType val_type;
    OptValueNode() { type = VALUE; expr = ""; }
    OptValueNode(string express, OptValueType type_) {
        type = VALUE;
        val_type = type_;
        expr = express;
    }
};

struct OptBinNode : OptNode {
    OPTNODE left;
    OPTNODE right;
    string opt;
    OptBinNode() { type = BINOP; }
    OptBinNode(OPTNODE left_, OPTNODE right_, string operator_) {
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
    else if(static_pointer_cast<OptValueNode>(node->left)->val_type == FLOAT){
        if(static_pointer_cast<OptValueNode>(node->right)->val_type == FLOAT){
            double leftValue = stod(visit(static_pointer_cast<OptValueNode>(node->left)));
            double rightValue = stod(visit(static_pointer_cast<OptValueNode>(node->right)));
            if (node->opt == "+") {
                return to_string(leftValue + rightValue);
            }
            else if (node->opt == "-") {
                return to_string(leftValue - rightValue);
            }
            else if (node->opt == "*") {
                return to_string(leftValue * rightValue);
            }
            else if (node->opt == "/") {
                return to_string(leftValue / rightValue);
            }
            else if (node->opt == "%") {
                error("Invalid operands of types float and float to binary operator %.");
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
    else if(static_pointer_cast<OptValueNode>(node->left)->val_type == INTEGER){
        if(static_pointer_cast<OptValueNode>(node->right)->val_type == INTEGER || static_pointer_cast<OptValueNode>(node->right)->val_type == FLOAT){
            long long int leftValue = stoi(visit(static_pointer_cast<OptValueNode>(node->left)));
            long long int rightValue = stoi(visit(static_pointer_cast<OptValueNode>(node->right)));
            if (node->opt == "+") {
                return to_string(leftValue + rightValue);
            }
            else if (node->opt == "-") {
                return to_string(leftValue - rightValue);
            }
            else if (node->opt == "*") {
                return to_string(leftValue * rightValue);
            }
            else if (node->opt == "/") {
                return to_string(leftValue / rightValue);
            }
            else if (node->opt == "%") {
                return to_string(leftValue % rightValue);
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
    return "";
}

string visit(shared_ptr<OptBinNode> expr) {
    return evaluateBinaryExpr(expr);
}


OPTNODE addNode(OptValueNode val){
    auto node = make_shared<OptValueNode>();
    node->expr = val.expr;
    node->val_type = val.val_type;
    return static_pointer_cast<OptNode>(node);
}
OPTNODE addNode(OptBinNode val){
    auto node = make_shared<OptBinNode>();
    node->left = val.left;
    node->right = val.right;
    node->opt = val.opt;
    return static_pointer_cast<OptNode>(node);
}
