#include <iostream>
#include <vector>
#include <string>
#include "InputReader.hpp"
#include "TextProcessor.hpp"

int main() {
    InputReader reader;

    std::vector<std::string> textos = reader.lerTextos("../data/input.dat");

    std::cout << "Total de blocos lidos: " << textos.size() << "\n\n";

    for (size_t i = 0; i < textos.size(); i++) {
        std::cout << "=== Bloco " << i+1 << " ===\n";
        std::cout << textos[i] << "\n\n";
        auto frequencia = TextProcessor::contarPalavras(textos[i]);
        
        std::cout << "Frequência de palavras:\n";
        for (const auto& par : frequencia) {
            std::cout << par.first << ": " << par.second << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}
