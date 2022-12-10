#include <iostream>
#include <stdexcept>
#include <string>
#include "Stack.h"
#include "expression_conversions.h"
#include "expression_conversions.cpp"

int main()
{

    std::string infix = getInfixExpression();
    std::cout << "Infix Expression is :" << infix << std::endl;
    std::string prefix = convert_infix_to_prefix(infix);
    std::cout << "The prefix form is :" << prefix << std::endl;
    std::string postfix = convert_infix_to_postfix(infix);
    std::cout << "The postfix form is :" << postfix << std::endl;
    std::cout << "Evaluation of Prefix is : " << evaluate_prefix_expr(prefix) << std::endl;
    std::cout << "Evaluation of Postfix is : " << evaluate_postfix_expr(postfix) << std::endl;
    return 0;
}
