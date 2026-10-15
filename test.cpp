#include "dataloot.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Kullanım: " << argv[0] << " <girdi_dosyası> <çıktı_dosyası>" << std::endl;
        return -1;
    }

    std::ifstream input(argv[1], std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Girdi dosyası açılamadı!" << std::endl;
        return -1;
    }
    
    std::ofstream output(argv[2], std::ios::binary);
    if (!output.is_open()) {
        std::cerr << "Çıktı dosyası açılamadı!" << std::endl;
        return -1;
    }

    std::stringstream ss;
    ss << input.rdbuf();

    std::vector<Out> out = encode(ss);
    for (const auto& [op, data]: out) {
        output << "Veri: " + data + "\nTip:  " + (op == Out::Op::yesop ? "YESOP" : "NOOP") + "\n";
        output << std::endl;
    }

    input.close();
    output.close();
}