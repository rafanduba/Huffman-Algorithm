#include "InputReader.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Remove espaços no começo e fim
static inline std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

std::vector<std::string> InputReader::lerTextos(const std::string& caminhoArquivo) {
    std::vector<std::string> textos;
    std::ifstream in(caminhoArquivo);
    if (!in.is_open()) {
        return textos;
    }

    std::string linha;
    std::ostringstream bloco;
    bool blocoVazio = true;

    while (std::getline(in, linha)) {
        std::string tl = trim(linha);
        if (tl.empty()) {
            if (!blocoVazio) {
                textos.push_back(bloco.str());
                bloco.str(""); bloco.clear();
                blocoVazio = true;
            }
        } else {
            bloco << (blocoVazio ? "" : "\n") << tl;
            blocoVazio = false;
        }
    }

    if (!blocoVazio) textos.push_back(bloco.str());

    return textos;
}

