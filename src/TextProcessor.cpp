#include "TextProcessor.hpp"
#include <sstream>
#include <algorithm>

std::vector<std::pair<std::string,int>>
TextProcessor::contarPalavras(const std::string& texto)
{
    std::unordered_map<std::string,int> contadorInterno;
    std::vector<std::pair<std::string,int>> ordem;

    std::stringstream streamPalavras(texto);
    std::string palavra;

    while (streamPalavras >> palavra) {

        while (!palavra.empty() && ispunct(palavra.front())) palavra.erase(0, 1);
        while (!palavra.empty() && ispunct(palavra.back()))  palavra.pop_back();
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

        if (palavra.empty()) continue;

        // primeira vez?
        if (contadorInterno[palavra] == 0)
            ordem.push_back({palavra, 1});
        else
            // já existe no vector, precisa achar e atualizar
            for (auto& p : ordem)
                if (p.first == palavra)
                    p.second++;

        contadorInterno[palavra]++;
    }

    return ordem;
}

