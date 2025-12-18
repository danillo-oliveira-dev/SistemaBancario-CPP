#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Biblioteca para formatação monetária

// Utilização do namespace standard para evitar repetição de 'std::'
using namespace std;

// CLASSE ContaBancaria
// Representa a entidade 'Conta' com encapsulamento dos dados sensíveis.
class ContaBancaria
{
private:
    // Atributos privados: Apenas métodos da própria classe podem modificá-los.
    // Isso garante a integridade dos dados (Princípio de Encapsulamento).
    int numeroConta;
    string nomeTitular;
    double saldo;

public:
    // Construtor: Inicializa o objeto quando uma nova conta é criada.
    ContaBancaria(int numero, string nome, double saldoInicial)
    {
        numeroConta = numero;
        nomeTitular = nome;
        saldo = saldoInicial;
    }

    // Método Getter para obter o número da conta (leitura apenas)
    int getNumeroConta()
    {
        return numeroConta;
    }

    // Método para exibir os detalhes da conta
    void exibirDetalhes()
    {
        cout << "-----------------------------------" << endl;
        cout << "Conta: " << numeroConta << endl;
        cout << "Titular: " << nomeTitular << endl;
        // fixed e setprecision garantem 2 casas decimais
        cout << "Saldo: R$ " << fixed << setprecision(2) << saldo << endl;
        cout << "-----------------------------------" << endl;
    }

    // Método para Depósito
    void depositar(double valor)
    {
        if (valor > 0)
        {
            saldo += valor;
            cout << "\n[Sucesso] Deposito de R$ " << valor << " realizado." << endl;
        }
        else
        {
            cout << "\n[Erro] O valor do deposito deve ser positivo." << endl;
        }
    }

    // Método para Saque (Levantamento)
    // Inclui validação de lógica de negócio: não permite saldo negativo.
    void sacar(double valor)
    {
        if (valor > 0 && valor <= saldo)
        {
            saldo -= valor;
            cout << "\n[Sucesso] Saque de R$ " << valor << " realizado." << endl;
        }
        else if (valor > saldo)
        {
            cout << "\n[Erro] Saldo insuficiente para esta transacao." << endl;
        }
        else
        {
            cout << "\n[Erro] Valor invalido." << endl;
        }
    }
};

// --- Funções Auxiliares do Sistema ---

// Busca uma conta no vetor (base de dados em memória) pelo ID
ContaBancaria *encontrarConta(vector<ContaBancaria> &contas, int numero)
{
    for (int i = 0; i < contas.size(); i++)
    {
        if (contas[i].getNumeroConta() == numero)
        {
            return &contas[i]; // Retorna o endereço de memória da conta encontrada
        }
    }
    return nullptr; // Retorna nulo se não encontrar
}

int main()
{
    // Vetor para armazenar dinamicamente as contas criadas
    vector<ContaBancaria> bancoDeDados;
    int opcao;
    int contadorContas = 1001; // Gera números de conta automaticamente

    do
    {
        cout << "\n=== SISTEMA DE GESTAO BANCARIA (C++) ===" << endl;
        cout << "1. Abrir Nova Conta" << endl;
        cout << "2. Consultar Saldo" << endl;
        cout << "3. Depositar" << endl;
        cout << "4. Sacar" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1)
        {
            string nome;
            cout << "Digite o nome do titular: ";
            cin.ignore();       // Limpa o buffer do teclado
            getline(cin, nome); // Permite nomes com espaços

            // Criação do objeto e inserção no vetor
            ContaBancaria novaConta(contadorContas, nome, 0.0);
            bancoDeDados.push_back(novaConta);

            cout << "\n[Sistema] Conta criada com sucesso!" << endl;
            cout << "Anote o numero da sua conta: " << contadorContas << endl;
            contadorContas++;
        }
        else if (opcao == 2 || opcao == 3 || opcao == 4)
        {
            int num;
            cout << "Digite o numero da conta: ";
            cin >> num;

            // Uso de ponteiros para manipular o objeto original no vetor
            ContaBancaria *conta = encontrarConta(bancoDeDados, num);

            if (conta != nullptr)
            {
                if (opcao == 2)
                {
                    conta->exibirDetalhes();
                }
                else if (opcao == 3)
                {
                    double valor;
                    cout << "Valor para deposito: ";
                    cin >> valor;
                    conta->depositar(valor);
                }
                else if (opcao == 4)
                {
                    double valor;
                    cout << "Valor para saque: ";
                    cin >> valor;
                    conta->sacar(valor);
                }
            }
            else
            {
                cout << "\n[Erro] Conta nao encontrada!" << endl;
            }
        }

    } while (opcao != 5);

    cout << "\nEncerrando sistema..." << endl;
    return 0;
}