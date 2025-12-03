#ifndef TEXT_PROCESSOR_HPP
#define TEXT_PROCESSOR_HPP

#include <string>
#include <vector>
#include <unordered_map>

class TextProcessor {
public:
    static std::vector<std::pair<std::string,int>> contarPalavras(const std::string& texto);
    static std::vector<std::string> tokenizar(const std::string& texto);
};

#endif
