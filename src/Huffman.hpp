#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

struct HuffmanNode {
    std::string token;
    int freq;
    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right;

    HuffmanNode(const std::string& t, int f) : token(t), freq(f), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(const std::shared_ptr<HuffmanNode>& a, const std::shared_ptr<HuffmanNode>& b) const{
        return a->freq > b->freq;
    }
};

class Huffman {
public:
    static std::shared_ptr<HuffmanNode> construirArvore(const std::vector<std::pair<std::string,int>>& tokensFreq);

    static std::unordered_map<std::string,std::string> gerarCodigos(const std::shared_ptr<HuffmanNode>& raiz);

    static std::string comprimir(const std::vector<std::string>& tokens,const std::unordered_map<std::string,std::string>& codigos);

    static void imprimirArvore(const std::shared_ptr<HuffmanNode>& raiz, std::ostream& out);

private:
    static void gerarCodigosRec(const std::shared_ptr<HuffmanNode>& nodo, const std::string& codigoAtual, std::unordered_map<std::string,std::string>& mapa);

    static void imprimirArvoreRec(const std::shared_ptr<HuffmanNode>& nodo, const std::string& prefixo, bool isLeft, std::ostream& out);
};

#endif
