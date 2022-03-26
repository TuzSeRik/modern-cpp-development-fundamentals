#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
// Adding multiplication and division. Not difficult, just a little bit more code
class FunctionPart {
public:
    FunctionPart(char newOperation, double newValue) {
        operation = newOperation;
        value = newValue;
    }

    double Apply(double incomingValue) const {
        if (operation == '+')
            return incomingValue + value;

        if (operation == '-')
            return incomingValue - value;

        if (operation == '*')
            return incomingValue * value;

        if (operation == '/')
            return  incomingValue / value;

        return incomingValue;
    }

    void Invert() {
        if (operation == '+') {
            operation = '-';
            return;
        }

        if (operation == '-') {
            operation = '+';
            return;
        }

        if (operation == '*') {
            operation = '/';
            return;
        }

        if (operation == '/') {
            operation = '*';
            return;
        }
    }

private:
    char operation;
    double value;
};

class Function {
public:
    double Apply(const double& incomingValue) const {
        double value = incomingValue;
        for (auto part : parts)
            value = part.Apply(value);
        return value;
    }

    void Invert() {
        for (auto& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }

    void AddPart(char operation, double value) {
        parts.push_back({operation, value});
    }

private:
    vector<FunctionPart> parts;
};
