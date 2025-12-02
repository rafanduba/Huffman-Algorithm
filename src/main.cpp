#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "InputReader.hpp"
#include "TextProcessor.hpp"

int main() {
    InputReader reader;

    std::vector<std::string> textos = reader.lerTextos("../data/input.dat");

    std::ofstream output_file("../data/output.dat");

    if(!output_file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de saída.\n";
        return 1;
    }

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

    for(size_t i = 0; i < textos.size(); i++) {
        output_file << "=== Bloco " << i+1 << " ===\n";
        output_file << textos[i] << "\n\n";
        auto frequencia = TextProcessor::contarPalavras(textos[i]);

        output_file << "Frequência de palavras:\n";
        for(const auto& par : frequencia) {
            output_file << par.first << ": " << par.second << "\n";
        }
        output_file << "\n";
    }

    output_file.close();
    std::cout << "Resultados escritos em ../data/output.dat\n";
    return 0;
}
