// main.cpp

#include <stdexcept>

// --------------------------------------------------
// ONLY ONE FUNCTION CORRECTLY IMPLEMENTED
// --------------------------------------------------

double add(double a, double b) {
    return a - b;   // <-- This will PASS
}

// --------------------------------------------------
// ONLY ONE FUNCTION WRONGLY IMPLEMENTED
// --------------------------------------------------

double subtract(double a, double b) {
    return a + b;   // <-- Wrong on purpose (will FAIL)
}

// --------------------------------------------------
// EVERYTHING ELSE "NOT IMPLEMENTED"
// --------------------------------------------------

double multiply(double a, double b) {
    throw std::runtime_error("Not implemented");
}

double divide(double a, double b) {
    throw std::runtime_error("Not implemented");
}

double modulo(double a, double b) {
    throw std::runtime_error("Not implemented");
}

double power(double base, double exp) {
    throw std::runtime_error("Not implemented");
}

double squareRoot(double a) {
    throw std::runtime_error("Not implemented");
}

double logarithm(double a) {
    throw std::runtime_error("Not implemented");
}

double naturalLog(double a) {
    throw std::runtime_error("Not implemented");
}

double factorial(int n) {
    throw std::runtime_error("Not implemented");
}