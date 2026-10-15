#include "dataloot.hpp"
#include <vector>
#include <sstream>

static bool isOperator(char& op) {
    const std::vector<char> sytnax_operator = {
        '=',
        ',',
        '{',
        '}'
    };
    bool equal = false;
    for (const char& sytnax : sytnax_operator) if (sytnax == op) { equal = true; break; }
    return equal;
}

std::vector<Out> encode(std::stringstream& ss) {
    std::vector<std::string> encodelayer1;
    std::string token;
    int line = 0;

    std::string kod = ss.str();

    for (size_t size = 0; size < kod.size(); size++) {
        char i = kod[size];

        if (i != ' ' && i != '\n' && i != '\t') token += i;
        else {
            if (!token.empty()) {
                encodelayer1.push_back(token);
                token = "";
            }
        }
    }

    if (!token.empty()) {
        encodelayer1.push_back(token);
        token = "";
        line++;
    }

    std::vector<Out> encodelayer2;

    for (const std::string& i : encodelayer1) {
        Out::Op op = Out::Op::noop;
        std::string k;

        for (size_t idx = 0; idx < i.size(); idx++) {
            Out::Op newtype;
            char j = i[idx];

            if (isOperator(j)) newtype = Out::Op::yesop;
            else newtype = Out::Op::noop;

                if (op != newtype) {
                    if (!k.empty()) {
                        encodelayer2.push_back({.op = op, .data = k});
                        k = "";
                    }
                    op = newtype;
                }

                k += j;
            }

            if (!k.empty()) encodelayer2.push_back({.op = op, .data = k});
        }

    return encodelayer2;
};