#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "InputReader.hpp"
#include "TextProcessor.hpp"
#include "Huffman.hpp"

int main() {
    InputReader reader;

    std::vector<std::string> textos = reader.lerTextos("../data/input.dat");

    std::ofstream output_file("../data/output.dat");

    if(!output_file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de saída.\n";
        return 1;
    }

    std::cout << "Total de blocos lidos: " << textos.size() << "\n\n";

    for(size_t i = 0; i < textos.size(); i++) {

        output_file << "=== Bloco " << i+1 << " ===\n";
        output_file << textos[i] << "\n\n";

        auto frequencia = TextProcessor::contarPalavras(textos[i]);

        output_file << "1 - Frequência de tokens:\n";
        for(const auto& par : frequencia) {
            output_file << "'" << par.first << "'" << ": " << par.second << "\n";
        }
        output_file << "\n";

        auto raiz = Huffman::construirArvore(frequencia);
        auto codigos = Huffman::gerarCodigos(raiz);

        output_file << "2 - Estrutura da Árvore de Huffman:\n";
        Huffman::imprimirArvore(raiz, codigos, output_file);
        output_file << "\n";

        std::vector<std::string> tokensSequencia = TextProcessor::tokenizar(textos[i]);

        output_file << "3 - Tabela de códigos (na ordem da frase):\n";
        Huffman::imprimirTabelaNaOrdemDaFrase(tokensSequencia, codigos, output_file);
        output_file << "\n";

        std::string textoComprimido = Huffman::comprimir(tokensSequencia, codigos);

        output_file << "4 - Texto comprimido (bits):\n";
        output_file << textoComprimido << "\n\n";
    }

    output_file.close();
    std::cout << "Resultados escritos em ../data/output.dat\n";

    return 0;
}
