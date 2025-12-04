#ifndef TEXT_PROCESSOR_HPP
#define TEXT_PROCESSOR_HPP

#include <string>
#include <vector>
#include <unordered_map>

class TextProcessor {
public:
    // Conta quantas vezes cada token aparece no texto.
    // Retorna pares (token, frequência) para facilitar a construção da árvore.
    static std::vector<std::pair<std::string,int>> contarPalavras(const std::string& texto);

    // Separa o texto em tokens preservando palavras, espaços e pontuação.
    static std::vector<std::string> tokenizar(const std::string& texto);
};

#endif
