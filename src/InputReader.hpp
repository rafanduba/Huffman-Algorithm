#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <string>
#include <vector>

// Cada bloco (duas/três frases) será retornado como uma string no vector.
class InputReader {
public:
    std::vector<std::string> lerTextos(const std::string& caminhoArquivo);
};

#endif
