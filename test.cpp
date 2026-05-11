// test.cpp
//
// Automated test suite for the calculator application.
//
// PURPOSE:
// - Detect missing functionalities
// - Detect wrongly implemented functionalities
// - Print a detailed report
//
// HOW TO USE:
// 1. Keep this file in the same folder as main.cpp
// 2. Compile:
//
//    g++ main.cpp test.cpp -o test
//
// NOTE:
// If main.cpp already contains a main() function,
// compile like this instead:
//
//    g++ -Dmain=calculator_main main.cpp test.cpp -o test
//
// This renames the original main() temporarily.
//
// ------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <exception>

// ------------------------------------------------------------
// Function declarations from main.cpp
// ------------------------------------------------------------

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double modulo(double a, double b);
double power(double base, double exp);
double squareRoot(double a);
double logarithm(double a);
double naturalLog(double a);
double factorial(int n);

// ------------------------------------------------------------
// Test framework
// ------------------------------------------------------------

struct TestResult {
    std::string functionality;
    bool implemented;
    bool passed;
    std::string message;
};

std::vector<TestResult> results;

const double EPS = 1e-6;

// ------------------------------------------------------------
// Helper Functions
// ------------------------------------------------------------

bool nearlyEqual(double a, double b, double eps = EPS) {
    return std::fabs(a - b) < eps;
}

void addResult(
    const std::string& name,
    bool implemented,
    bool passed,
    const std::string& message
) {
    results.push_back({name, implemented, passed, message});
}

// ------------------------------------------------------------
// Individual Tests
// ------------------------------------------------------------

void testAddition() {
    try {
        double r = add(5, 3);

        if (nearlyEqual(r, 8))
            addResult("Addition", true, true, "Correct");
        else
            addResult("Addition", true, false, "Expected 8");

    } catch (...) {
        addResult("Addition", false, false, "Not implemented");
    }
}

void testSubtraction() {
    try {
        double r = subtract(10, 4);

        if (nearlyEqual(r, 6))
            addResult("Subtraction", true, true, "Correct");
        else
            addResult("Subtraction", true, false, "Expected 6");

    } catch (...) {
        addResult("Subtraction", false, false, "Not implemented");
    }
}

void testMultiplication() {
    try {
        double r = multiply(7, 6);

        if (nearlyEqual(r, 42))
            addResult("Multiplication", true, true, "Correct");
        else
            addResult("Multiplication", true, false, "Expected 42");

    } catch (...) {
        addResult("Multiplication", false, false, "Not implemented");
    }
}

void testDivision() {
    try {
        double r = divide(20, 5);

        if (nearlyEqual(r, 4))
            addResult("Division", true, true, "Correct");
        else
            addResult("Division", true, false, "Expected 4");

    } catch (...) {
        addResult("Division", false, false, "Not implemented");
    }
}

void testDivisionByZero() {
    try {
        divide(5, 0);
        addResult("Division by Zero Handling", true, false,
                  "Exception not thrown");
    }
    catch (const std::runtime_error&) {
        addResult("Division by Zero Handling", true, true,
                  "Correct exception handling");
    }
    catch (...) {
        addResult("Division by Zero Handling", true, false,
                  "Wrong exception type");
    }
}

void testModulo() {
    try {
        double r = modulo(10, 3);

        if (nearlyEqual(r, 1))
            addResult("Modulo", true, true, "Correct");
        else
            addResult("Modulo", true, false, "Expected 1");

    } catch (...) {
        addResult("Modulo", false, false, "Not implemented");
    }
}

void testPower() {
    try {
        double r = power(2, 5);

        if (nearlyEqual(r, 32))
            addResult("Power", true, true, "Correct");
        else
            addResult("Power", true, false, "Expected 32");

    } catch (...) {
        addResult("Power", false, false, "Not implemented");
    }
}

void testSquareRoot() {
    try {
        double r = squareRoot(49);

        if (nearlyEqual(r, 7))
            addResult("Square Root", true, true, "Correct");
        else
            addResult("Square Root", true, false, "Expected 7");

    } catch (...) {
        addResult("Square Root", false, false, "Not implemented");
    }
}

void testNegativeSquareRoot() {
    try {
        squareRoot(-1);

        addResult("Negative Square Root Handling",
                  true,
                  false,
                  "Exception not thrown");
    }
    catch (const std::runtime_error&) {
        addResult("Negative Square Root Handling",
                  true,
                  true,
                  "Correct exception handling");
    }
    catch (...) {
        addResult("Negative Square Root Handling",
                  true,
                  false,
                  "Wrong exception type");
    }
}

void testLogarithm() {
    try {
        double r = logarithm(100);

        if (nearlyEqual(r, 2))
            addResult("Log base 10", true, true, "Correct");
        else
            addResult("Log base 10", true, false, "Expected 2");

    } catch (...) {
        addResult("Log base 10", false, false, "Not implemented");
    }
}

void testNaturalLog() {
    try {
        double r = naturalLog(std::exp(1));

        if (nearlyEqual(r, 1))
            addResult("Natural Log", true, true, "Correct");
        else
            addResult("Natural Log", true, false, "Expected 1");

    } catch (...) {
        addResult("Natural Log", false, false, "Not implemented");
    }
}

void testFactorial() {
    try {
        double r = factorial(5);

        if (nearlyEqual(r, 120))
            addResult("Factorial", true, true, "Correct");
        else
            addResult("Factorial", true, false, "Expected 120");

    } catch (...) {
        addResult("Factorial", false, false, "Not implemented");
    }
}

void testNegativeFactorial() {
    try {
        factorial(-2);

        addResult("Negative Factorial Handling",
                  true,
                  false,
                  "Exception not thrown");
    }
    catch (const std::runtime_error&) {
        addResult("Negative Factorial Handling",
                  true,
                  true,
                  "Correct exception handling");
    }
    catch (...) {
        addResult("Negative Factorial Handling",
                  true,
                  false,
                  "Wrong exception type");
    }
}

void testLargeFactorial() {
    try {
        factorial(25);

        addResult("Large Factorial Limit",
                  true,
                  false,
                  "Exception not thrown");
    }
    catch (const std::runtime_error&) {
        addResult("Large Factorial Limit",
                  true,
                  true,
                  "Correct limit handling");
    }
    catch (...) {
        addResult("Large Factorial Limit",
                  true,
                  false,
                  "Wrong exception type");
    }
}

// ------------------------------------------------------------
// Run All Tests
// ------------------------------------------------------------

void runAllTests() {
    testAddition();
    testSubtraction();
    testMultiplication();
    testDivision();
    testDivisionByZero();
    testModulo();
    testPower();
    testSquareRoot();
    testNegativeSquareRoot();
    testLogarithm();
    testNaturalLog();
    testFactorial();
    testNegativeFactorial();
    testLargeFactorial();
}

// ------------------------------------------------------------
// Report Generator
// ------------------------------------------------------------

void printReport() {

    int implementedCount = 0;
    int nonImplementedCount = 0;
    int wrongCount = 0;
    int correctCount = 0;

    std::cout << "\n";
    std::cout << "====================================================\n";
    std::cout << "              CALCULATOR TEST REPORT                \n";
    std::cout << "====================================================\n\n";

    for (const auto& r : results) {

        std::cout << std::left
                  << std::setw(35)
                  << r.functionality;

        if (!r.implemented) {
            std::cout << "[NOT IMPLEMENTED]";
            nonImplementedCount++;
        }
        else if (r.passed) {
            std::cout << "[PASSED]";
            correctCount++;
            implementedCount++;
        }
        else {
            std::cout << "[FAILED]";
            wrongCount++;
            implementedCount++;
        }

        std::cout << " -> " << r.message << "\n";
    }

    std::cout << "\n====================================================\n";
    std::cout << "SUMMARY\n";
    std::cout << "====================================================\n";

    std::cout << "Total Tests                    : "
              << results.size() << "\n";

    std::cout << "Correct Functionalities        : "
              << correctCount << "\n";

    std::cout << "Wrongly Implemented Functions  : "
              << wrongCount << "\n";

    std::cout << "Non-Implemented Functionalities: "
              << nonImplementedCount << "\n";

    std::cout << "Implemented Functionalities    : "
              << implementedCount << "\n";

    std::cout << "====================================================\n\n";
}

// ------------------------------------------------------------
// Main
// ------------------------------------------------------------

int main() {

    runAllTests();

    printReport();

    return 0;
}