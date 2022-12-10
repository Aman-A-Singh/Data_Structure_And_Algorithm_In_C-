#include<string>
#include<map>

/* returns infix expression */
std::string getInfixExpression();

/*Takes a single string ie an infix expression as its arguments and returns a prefix form of the same expression*/
std::string convert_infix_to_prefix(std::string infix_expression);

/*Takes a single string ie an infix expression as its arguments and returns a postfix form of the same expression*/
std::string convert_infix_to_postfix(std::string infix_expression);

/*Returns true if the character passed is an operator otherwise returns false*/
bool is_operator(char symbol);

/*Return the priority of the operator symbol passed*/
size_t priority(char operator_symbol);


void create_prefix_expression(myLib::Stack<std::string>& operand_stack, char operator_from_stack);

void create_postfix_expression(myLib::Stack<std::string>& operand_stack, char operator_from_stack);

/*gte the values of operand*/
void get_operand_values(std::string prefix_expr, std::map<char, float> & operand_values_map);

/*evaluates a prefix expression returning its result*/
float evaluate_prefix_expr(std::string prefix_expr);

float calculate(float operand1, float operand2, char sign);

/*evaluates a postfix expression returning the result*/
float evaluate_postfix_expr(std::string postfix_expr);