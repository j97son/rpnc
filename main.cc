#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>

double rpnc(const std::string& expr)
{
    std::istringstream iss(expr);
    std::stack<double> stack;
    std::string token;
    while (iss >> token) {
        double value;
        if (std::istringstream(token) >> value) {
            stack.push(value);
        } else {
            if (stack.size() < 2) {
                std::cerr << "error" << std::endl;
                std::exit(1);
            }
            
            double o2 = stack.top();
            stack.pop();
            double o1 = stack.top();
            stack.pop();

            if (token == "^") {
                stack.push(std::pow(o1, o2));
            } else if (token == "*") {
                stack.push(o1 * o2);
            } else if (token == "/") {
                stack.push(o1 / o2);
            } else if (token == "+") {
                stack.push(o1 + o2);
            } else if (token == "-") {
                stack.push(o1 - o2);
            } else {
                std::cerr << "error" << std::endl;
                std::exit(1);
            }
        }
    }
    if (stack.size() == 1) {
        return stack.top();
    } else {
        std::cerr << "error" << std::endl;
        std::exit(1);
    }
}

int main()
{
    //std::string example = "3 4 2 * 1 5 - 2 3 ^ ^ / +";
    //std::cout << "answer: " << rpnc(example) << std::endl;
    std::string expr;
    std::cout << "expr: ";
    std::getline(std::cin, expr);
    std::cout << "answer: " << rpnc(expr) << std::endl;
    return 0;
}