#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <string>
#include <vector>

//Retorna os blocos de texto lidos do input.dat
class InputReader {
public:
    std::vector<std::string> lerTextos(const std::string& caminhoArquivo);
};

#endif
