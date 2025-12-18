# Bank Account Management System (C++)

Este projeto consiste num sistema de gestão bancária desenvolvido em C++ para demonstrar aplicação de lógica de negócios e manipulação de dados em memória.

O foco principal foi a utilização de **Programação Orientada a Objetos (POO)** para criar um sistema seguro, onde os dados sensíveis (como saldo) são protegidos e apenas manipulados através de métodos específicos.

## ⚙️ Arquitetura e Conceitos

- **Linguagem:** C++
- **Paradigma:** Orientação a Objetos (Classes, Métodos e Encapsulamento).
- **Estrutura de Dados:** Utilização de `std::vector` (STL) para armazenamento dinâmico de contas, permitindo que o sistema cresça sem tamanho fixo.
- **Ponteiros:** Manipulação de referências para atualizar objetos diretamente na memória.

## 📋 Funcionalidades

1. **Abertura de Conta:** Gera automaticamente um número de conta único.
2. **Depósitos e Saques:** Validações lógicas (ex: impedir saque maior que o saldo ou valores negativos).
3. **Consulta:** Exibição formatada de dados financeiros.

## 🚀 Como compilar e executar

Como o C++ é uma linguagem compilada, é necessário gerar o binário antes de executar.

### Pré-requisitos

- Compilador GCC/G++ instalado (MinGW no Windows ou nativo no Linux/Mac).

### Passo a passo

1. Abra o terminal na pasta do projeto.
2. Compile o código com o seguinte comando:
   ```bash
   g++ main.cpp -o banco
   ```

Execute o programa criado:

Windows: .\banco.exe

Linux/Mac: ./banco


Projeto de estudo desenvolvido por [Danillo] - Estudante de Cibersegurança e Análise e Desenvolvimento de Sistemas
