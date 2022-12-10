#include "expression_conversions.h"
#include "Stack.h"
#include "StackImplementation.h"
#include <iostream>

std::string getInfixExpression()
{
    std::cout << "Please enter a infix expression :";
    std::string infix{};
    std::getline(std::cin, infix);
    return infix;
}

std::string convert_infix_to_prefix(std::string infix_expression)
{
    /*Stack of Operands*/
    myLib::Stack<std::string> operand_stack{10};
    /*Stack of Operator*/
    myLib::Stack<char> operator_stack{10};

    size_t idx = 0;

    /*Traverse the Infix Expression*/
    while (infix_expression.length() != idx)
    {
        char symbol = infix_expression.at(idx);
        /*If the Symbol is a Space skip the symbol*/
        if (isspace(symbol))
        {
            ++idx;
            continue;
        }
        /*If the element from infix expression is an Operand*/
        if (!is_operator(symbol))
        {
            operand_stack.push(std::string(1, symbol));
            ++idx;
            continue;
        }

        /*If the element from infix expression is an operator
          If the operator stack is empty or the operator is '(';
          push the operator in the operator stack
        */
        if (operator_stack.isEmpty() || symbol == '(')
        {
            operator_stack.push(symbol);
            ++idx;
            continue;
        }

        /*If the operator is ')';
          pop from the operand stack till the '(' operator is encountered*/
        if (symbol == ')')
        {
            char operator_from_stack = operator_stack.pop();
            while (operator_from_stack != '(')
            {
                create_prefix_expression(operand_stack, operator_from_stack);
                operator_from_stack = operator_stack.pop();
            }
            idx++;
            continue;
        }
        /*
         *if the operator is not ')' and the operator stack is not empty;
         * Then check the priority of the operator from infix expression with the priority
         * of the operator from stack
         */
        while (!operator_stack.isEmpty())
        {
            char operator_from_stack = operator_stack.peek();
            if (priority(symbol) > priority(operator_from_stack))
            {
                operator_stack.push(symbol);
                idx++;
                break;
            }
            operator_from_stack = operator_stack.pop();
            create_prefix_expression(operand_stack, operator_from_stack);
        }
    }
    while (!operator_stack.isEmpty())
    {
        char operator_from_stack = operator_stack.pop();
        create_prefix_expression(operand_stack, operator_from_stack);
    }
    return operand_stack.pop();
}

std::string convert_infix_to_postfix(std::string infix_expression)
{
    myLib::Stack<std::string> operand_stack{10};
    myLib::Stack<char> operator_stack{10};

    size_t idx{0};

    while (idx < infix_expression.length())
    {
        char symbol = infix_expression.at(idx);

        if (isspace(symbol))
        {
            idx++;
            continue;
        }

        if (!is_operator(symbol))
        {
            operand_stack.push(std::string(1, symbol));
            idx++;
            continue;
        }
        if (operator_stack.isEmpty() || symbol == '(')
        {
            operator_stack.push(symbol);
            idx++;
            continue;
        }
        char operator_from_stack = operator_stack.peek();
        if (symbol == ')')
        {
            operator_from_stack = operator_stack.pop();
            while (operator_from_stack != '(')
            {
                create_postfix_expression(operand_stack, operator_from_stack);
                operator_from_stack = operator_stack.pop();
            }
            ++idx;
            continue;
        }
        if (priority(symbol) > priority(operator_from_stack))
        {
            operator_stack.push(symbol);
            idx++;
        }
        else
        {
            operator_from_stack = operator_stack.pop();
            create_postfix_expression(operand_stack, operator_from_stack);
        }
    }
    while (!operator_stack.isEmpty())
    {
        char operator_from_stack = operator_stack.pop();
        create_postfix_expression(operand_stack, operator_from_stack);
    }
    return operand_stack.pop();
}
bool is_operator(char symbol)
{
    /* Currently we are supporting only the following opertors*/
    std::string supported_operators{"+-*/^%()"};
    if (!isalpha(symbol))
    {
        return supported_operators.find(symbol, 0) != std::string::npos;
    }
    return false; // if it is an alphabet
}

void create_prefix_expression(myLib::Stack<std::string> &operand_stack, char operator_from_stack)
{
    std::string operand2 = operand_stack.pop();
    std::string operand1 = operand_stack.pop();
    std::string resultant_expression = operator_from_stack + operand1 + operand2;
    operand_stack.push(resultant_expression);
}

void create_postfix_expression(myLib::Stack<std::string> &operand_stack, char operator_from_stack)
{
    std::string operand2 = operand_stack.pop();
    std::string operand1 = operand_stack.pop();
    std::string resultant_expression = operand1 + operand2 + operator_from_stack;
    operand_stack.push(resultant_expression);
}

size_t priority(char operator_symbol)
{
    switch (operator_symbol)
    {
    case '*':
    case '/':
    case '%':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
    case ')':
        return 1;
    default:
        return 0;
    }
}

void get_operand_values(std::string prefix_expr, std::map<char, float> &operand_values_map)
{
    for (size_t idx = 0; idx < prefix_expr.size(); idx++)
    {
        char symbol = prefix_expr.at(idx);
        if (!is_operator(symbol))
        {
            /*If operand is not present in the map then accept it's value*/
            if (operand_values_map.find(symbol) == operand_values_map.end())
            {
                float value{};
                std::cout << "Please Enter the value of operand " << symbol << " : ";
                std::cin >> value;
                operand_values_map.insert(std::make_pair(symbol, value));
            }
        }
    }
    // std::cout << "map size : " << operand_values_map.size();

    // std::cout << std::endl;
    // for (const auto &element : operand_values_map)
    // {

    //     std::cout << element.first << ":" << element.second << "\n";
    // }
}

float evaluate_prefix_expr(std::string prefix_expr)
{
    if (prefix_expr.empty())
    {
        throw std::invalid_argument("Expression is empty!");
    }
    myLib::Stack<float> stack_of_operand{10};
    int idx = prefix_expr.size() - 1;

    /*Array to store the values of the operands in the expression*/
    std::map<char, float> operand_values_map;
    get_operand_values(prefix_expr, operand_values_map);
    
    while (idx >= 0)
    {
        char symbol = prefix_expr.at(idx);
        if (isspace(symbol))
        {
            idx++;
            continue;
        }
        if (!is_operator(symbol))
        {
            stack_of_operand.push(operand_values_map[symbol]);
        }
        else
        {
            float operand1 = stack_of_operand.pop();
            float operand2 = stack_of_operand.pop();
            float result = calculate(operand1, operand2, symbol);
            stack_of_operand.push(result);
        }
        idx--;
    }
    return stack_of_operand.pop();
}

float calculate(float operand1, float operand2, char sign)
{
    switch (sign)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;

    case '*':

        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    case '%':
        return static_cast<int>(operand1) % static_cast<int>(operand2);
    }
    return 0.0f;
}

float evaluate_postfix_expr(std::string postfix_expr)
{
    myLib::Stack<float> stack_of_operand{10};
    size_t idx = 0;

    /*Array to store the values of the operands in the expression*/
    std::map<char, float> operand_values_map;
    get_operand_values(postfix_expr, operand_values_map);

    while (idx < postfix_expr.size())
    {
        char symbol = postfix_expr.at(idx);

        if (isspace(symbol))
        {
            idx++;
            continue;
        }
        if (!is_operator(symbol))
        {
            stack_of_operand.push(operand_values_map[symbol]);
        }
        else
        {
            float operand2 = stack_of_operand.pop();
            float operand1 = stack_of_operand.pop();
            float result = calculate(operand1, operand2, symbol);
            stack_of_operand.push(result);
        }
        idx++;
    }
    return stack_of_operand.pop();
}