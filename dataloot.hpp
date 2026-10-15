#include <vector>
#include <sstream>

struct Out {
    enum Op {
        yesop,
        noop
    };

    Out::Op op;
    std::string data;
};

std::vector<Out> encode(std::stringstream& ss);