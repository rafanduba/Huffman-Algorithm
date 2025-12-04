#include "Huffman.hpp"
#include <queue>
#include <iostream>
#include <unordered_set>

std::shared_ptr<HuffmanNode>
Huffman::construirArvore(const std::vector<std::pair<std::string,int>>& tokensFreq) {

    std::priority_queue<std::shared_ptr<HuffmanNode>, std::vector<std::shared_ptr<HuffmanNode>>, CompareNodes
    > fila;

    for (const auto& par : tokensFreq) {
        fila.push(std::make_shared<HuffmanNode>(par.first, par.second));
    }

    if (fila.size() == 1) {
        auto unico = fila.top();
        auto raiz = std::make_shared<HuffmanNode>("", unico->freq);
        raiz->left = unico;
        return raiz;
    }

    while (fila.size() > 1) {
        auto a = fila.top(); fila.pop();
        auto b = fila.top(); fila.pop();

        auto novo = std::make_shared<HuffmanNode>("", a->freq + b->freq);
        novo->left = a;
        novo->right = b;
        fila.push(novo);
    }

    return fila.top();
}

//Gera os códigos para cada token
std::unordered_map<std::string,std::string>
Huffman::gerarCodigos(const std::shared_ptr<HuffmanNode>& raiz) {
    std::unordered_map<std::string,std::string> tabela;
    gerarCodigosRec(raiz, "", tabela);
    return tabela;
}

void Huffman::gerarCodigosRec(const std::shared_ptr<HuffmanNode>& nodo, const std::string& codigoAtual, std::unordered_map<std::string,std::string>& mapa)
{
    if (!nodo) return;

    if (!nodo->left && !nodo->right) {
        mapa[nodo->token] = codigoAtual;
        return;
    }

    gerarCodigosRec(nodo->left,  codigoAtual + "0", mapa);
    gerarCodigosRec(nodo->right, codigoAtual + "1", mapa);
}


std::string Huffman::comprimir(const std::vector<std::string>& tokens, const std::unordered_map<std::string,std::string>& codigos)
{
    std::string out;
    out.reserve(tokens.size() * 4);

    for (const auto& tk : tokens)
        out += codigos.at(tk);

    return out;
}


void Huffman::imprimirArvore(
    const std::shared_ptr<HuffmanNode>& raiz,
    const std::unordered_map<std::string, std::string>& codigos, std::ostream& out
){
    imprimirArvoreRec(raiz, "", false, codigos, out);
}

void Huffman::imprimirArvoreRec(const std::shared_ptr<HuffmanNode>& nodo, const std::string& prefixo, bool isLeft, const std::unordered_map<std::string,std::string>& codigos, std::ostream& out
){
    if (!nodo) return;

    out << prefixo;

    out << (isLeft ? "├── " : "└── ");

    if (nodo->left == nullptr && nodo->right == nullptr) {
        auto it = codigos.find(nodo->token);
        std::string codigo = (it != codigos.end()) ? it->second : "N/A";

        out << "'" << nodo->token << "' (freq: " << nodo->freq << ", cod: " << codigo << ")\n";
    } else {
        out << "Interno (freq: " << nodo->freq << ")\n";
    }

    std::string novoPrefixo = prefixo + (isLeft ? "│   " : "    ");

    if (nodo->left)
        imprimirArvoreRec(nodo->left, novoPrefixo, true, codigos, out);

    if (nodo->right)
        imprimirArvoreRec(nodo->right, novoPrefixo, false, codigos, out);
}

void Huffman::imprimirTabelaNaOrdemDaFrase(const std::vector<std::string>& tokens, const std::unordered_map<std::string, std::string>& codigos, std::ostream& out){
    std::unordered_set<std::string> jaImpresso;

    out << "\n=== Tabela de Códigos (na ordem da frase) ===\n";

    for (const auto& tk : tokens) {
        if (jaImpresso.count(tk)) continue;

        auto it = codigos.find(tk);
        if (it != codigos.end()) {
            out << "'" << tk << "' -> " << it->second << "\n";
            jaImpresso.insert(tk);
        }
    }
}
