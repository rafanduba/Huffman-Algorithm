#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

// Nó da árvore de Huffman
struct HuffmanNode {
    std::string token;  //pode ser uma palavra, caractere, espaço em branco, pontuação, etc
    int freq;           // frequência de ocorrência
    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right;

    HuffmanNode(const std::string& t, int f) : token(t), freq(f), left(nullptr), right(nullptr) {}
};

// Comparador para prioridade em estrutura tipo heap (menor freq tem maior prioridade)
struct CompareNodes {
    bool operator()(const std::shared_ptr<HuffmanNode>& a, const std::shared_ptr<HuffmanNode>& b) const {
        return a->freq > b->freq;  // nó com freq maior tem menor prioridade
    }
};

class Huffman {
public:
    // Constroi a árvore de Huffman a partir de um vetor de pares (token, frequência)
    static std::shared_ptr<HuffmanNode> construirArvore(const std::vector<std::pair<std::string,int>>& tokensFreq);

    // Gera o mapa de códigos binários para cada token, a partir da raiz da árvore
    static std::unordered_map<std::string,std::string> gerarCodigos(const std::shared_ptr<HuffmanNode>& raiz);

    // Comprime uma sequência de tokens usando o mapa de códigos
    static std::string comprimir(const std::vector<std::string>& tokens, const std::unordered_map<std::string,std::string>& codigos);

    // Imprime a estrutura da árvore
    static void imprimirArvore( const std::shared_ptr<HuffmanNode>& raiz, const std::unordered_map<std::string, std::string>& codigos, std::ostream& out);

    // Imprime a tabela de tokens e seus códigos na ordem da frase original
    static void imprimirTabelaNaOrdemDaFrase(const std::vector<std::string>& tokens, const std::unordered_map<std::string, std::string>& codigos, std::ostream& out);

private:
    // Função recursiva que percorre a árvore para gerar os códigos
    static void gerarCodigosRec(
        const std::shared_ptr<HuffmanNode>& nodo, 
        const std::string& codigoAtual, 
        std::unordered_map<std::string,std::string>& mapa);

    // Função recursiva para imprimir a árvore com formatação de prefixo
    static void imprimirArvoreRec(
        const std::shared_ptr<HuffmanNode>& nodo,
        const std::string& prefixo,
        bool isLeft,
        const std::unordered_map<std::string, std::string>& codigos,
        std::ostream& out
    );
};

#endif
