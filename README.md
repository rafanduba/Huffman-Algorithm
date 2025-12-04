# Huffman Algorithm

## 📘 Sobre o projeto
Este repositório contém uma implementação do algoritmo de Huffman, um dos métodos clássicos para compressão de dados sem perda de informação.
O objetivo é ler textos, analisar a frequência dos caracteres e gerar uma versão comprimida usando códigos binários mais curtos para símbolos frequentes.

## 🧠 Funcionamento do Algoritmo
- Lê um número n de frases do arquivo input.dat, presente na pasta "data"
- Transforma palavras e pontuação em tokens
- Calcula a frequência em que cada token aparece em cada uma das frases
- Monta uma árvore de Huffman baseado nas frequências
- Gera códigos binários para cada um dos tokens (curtos para os mais comuns, longos para os que aparecem menos)
- Comprime o texto, substituindo tokens por seu equivalente em binário
- Para cada frase, é impresso a frequência de seus tokens, a estrutura correspondente da árvore de Huffman, a tabela de códigos de cada token e o texto final comprimido no arquivo output.dat, presente na pasta "data"

## 📂 Estrutura do projeto

```
/data -> arquivos de entrada e saída
/src -> códigos em C++
README.md
```

## 🚀 Como usar

### Importar projeto
```
git clone 
```
No terminal:
### Compilar
```
cd src
g++ main.cpp InputReader.cpp Huffman.cpp TextProcessor.cpp -o main
```
### Rodar
```
./main
```
