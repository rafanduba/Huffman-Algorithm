#include "TextProcessor.hpp"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <vector>

static bool is_common_punctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';' ||
           c == '"' || c == '\'' || c == '(' || c == ')' || c == '[' || c == ']' ||
           c == '{' || c == '}';
}

std::vector<std::pair<std::string,int>>
TextProcessor::contarPalavras(const std::string& texto)
{
    std::unordered_map<std::string, int> contadorInterno;
    std::vector<std::string> sequenciaTokens;

    std::string tokenAtual;

    for (char c : texto) {

        if (std::isspace(static_cast<unsigned char>(c))) {
            if (!tokenAtual.empty()) {
                sequenciaTokens.push_back(tokenAtual);
                tokenAtual.clear();
            }
            sequenciaTokens.push_back(" ");
            continue;
        }

        if (is_common_punctuation(c)) {
            if (!tokenAtual.empty()) {
                sequenciaTokens.push_back(tokenAtual);
                tokenAtual.clear();
            }
            sequenciaTokens.push_back(std::string(1, c));
        } 
        else {
            tokenAtual += c;
        }
    }

    if (!tokenAtual.empty())
        sequenciaTokens.push_back(tokenAtual);

    std::vector<std::pair<std::string,int>> ordemResultado;

    for (const std::string& token : sequenciaTokens) {

        contadorInterno[token]++;

        if (contadorInterno[token] == 1) {
            ordemResultado.push_back({token, 1});
        }
    }
    
    for (auto& p : ordemResultado) {
        p.second = contadorInterno[p.first];
    }

    return ordemResultado;
}

std::vector<std::string>
TextProcessor::tokenizar(const std::string& texto)
{
    std::vector<std::string> tokens;
    std::string tokenAtual;

    for (char c : texto) {

        if (std::isspace(static_cast<unsigned char>(c))) {
            if (!tokenAtual.empty()) {
                tokens.push_back(tokenAtual);
                tokenAtual.clear();
            }
            tokens.push_back(" ");
            continue;
        }

        if (is_common_punctuation(c)) {
            if (!tokenAtual.empty()) {
                tokens.push_back(tokenAtual);
                tokenAtual.clear();
            }
            tokens.push_back(std::string(1, c));
        }
        else {
            tokenAtual += c;
        }
    }

    if (!tokenAtual.empty())
        tokens.push_back(tokenAtual);

    return tokens;
}
