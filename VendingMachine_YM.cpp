#include <iostream>
//Biblioteca utilizada para mostrar dois números na casa decimal (ex 0.00):
#include <iomanip> 
//quantidade máxima de produtos da máquina:
#define Q 30 
using namespace std;

//Estrutura para cada produto
typedef struct Produto {
  string nome;
  int cod;
  int quant_dispon;
  double valor;
  int quant_vendida; 
  double faturamento;
  double pode_faturar;
} produto;

//Função para listar produtos
void estoque_2023(produto p[Q]){
  string name[Q] = {"Suco de Laranja", "Lata Coca-Cola","Lata Guaraná","Lata Fanta Laranja","Lata Pepsi", "Água", "Água com Gás", "Cookies Toddy","Bolacha Passatempo","Doritos","Ruffles","Fandangos","Azedinho Uva","Azedinho Morango", "Halls Extra Forte","Halls Menta","Halls Melancia","Cappuccino Pronto","Café com Leite Pronto","Bebida Alpino","Barra Chocolate ao Leite","Barra Chocolate Branco","Barra de Cereal","Barra de Proteína Chocolate","Chips Saudável","Chocolate Trento Branco-Dark","Chocolate Trento Avelãs","Chocolate Trento Torta de Limão","Kit Kat Tradicional","Bis Xtra Original"};

  int quant[Q] = {10, 10, 10, 10, 10, 10, 10, 5, 5, 10, 10, 10, 15, 15, 15, 15, 15, 10, 10, 10, 6, 6, 15, 15, 10, 15, 15, 15, 15, 15};
  
  double valor[Q] = {4, 5, 5, 4.5, 4.5, 3.5, 3.5, 9, 3.5, 6, 6, 5.5, 2.5, 2.5, 3, 3, 3, 9, 9, 9, 5, 5, 3.5, 9, 6, 4, 4, 4, 5, 4.5};
  
  
  for (int i = 0; i < Q; i++){
    p[i].nome = name[i];
    p[i].cod = i;
    p[i].quant_dispon = quant[i];
    p[i].quant_vendida = 0;
    p[i].valor = valor[i];
  }

};

//Função para listagem de produtos - ADM
void listagem_prod(produto p[Q]){
  //Representa a função que é ativada a partir do comando 1 na op_adm 
  cout << "\n---- PRODUTOS E UNIDADES DISPONÍVEIS ----\n";
  for (int i = 0; i < Q; i++){
          cout << "Produto " << p[i].nome << "(cod " << p[i].cod << "): " 
                << p[i].quant_dispon << " unidades\n";
        }
};

//Função para reposição de produtos
void repor_prod(produto p[Q]){
  //Representa a função que é ativada a partir do comando 2 na op_adm 
  int choice, cod, repor;
  do{
  cout << "\n---- REPOSIÇÃO ----";
  cout << "\n[1] Exibição todos os produtos \n[2] Exibição apenas zero estoque";
  cout << "\nAcessar: ";
  cin >> choice;

  switch (choice){
    case 1:
      {
         cout << "\n---- PRODUTOS E UNIDADES DISPONÍVEIS ----\n";
          for (int i = 0; i < Q; i++){
            cout << "Produto " << p[i].nome << "(cod " << p[i].cod << "): " 
                  << p[i].quant_dispon << " unidades\n";
          };
        break;
      }
    
    case 2:
      {
        for (int i = 0; i < Q; i++){
          if (p[i].quant_dispon == 0){
            cout << "Produto " << p[i].nome << "(cod " << p[i].cod << "): " 
                  << p[i].quant_dispon << " unidades\n";
          };
        }; 
        break;
      }
    
    default:
      cout << "\nOPÇÃO INSERIDA É INVÁLIDA!!!\n";
    }
  } while (choice < 1 || choice > 2);

  
  do {
    do {
      //Reposição dos produtos
      cout << "\nInsira o código do produto que deseja repor: ";
      cin >> cod;
      if (cod < 30){
        cout << "\nInsira a quantidade reposta: ";
        cin >> repor;
        p[cod].quant_dispon += repor;
      }
      else {
        cout << "O código inserido não foi encontrado. ";
      };
    } while (cod >= 30);
    
    cout << "\nDeseja repor mais produtos?";
    cout << "\n[1] Sim \n[2] Não";
    cout << "\nEscolha: ";
    cin >> choice;
    switch (choice) {
      case 1: 
        break;
      case 2: 
        break;
      default:
        cout << "\nOPÇÃO INSERIDA É INVÁLIDA!!!\n";
    };
  } while (choice == 1);
};

//Função de faturamento
void faturamento(produto p[Q]){
  //Representa a função que é ativada a partir do comando 3 na op_adm 
  double total_faturar = 0, total_pode_faturar = 0;
  int choice;
  
  for (int i = 0; i < Q; i++){
    //Cálculo de cada produto 
    p[i].faturamento = p[i].valor * p[i].quant_vendida;
    p[i].pode_faturar = p[i].faturamento + (p[i].valor*p[i].quant_dispon);

    //Cálculo valor total 
    total_faturar = total_faturar + p[i].faturamento;
    total_pode_faturar = total_pode_faturar + p[i].pode_faturar;
  }

   do{
  cout << "\n---- FATURAMENTO ----";
  cout << "\n[1] Exibição detalhada \n[2] Exibição Resumida";
  cout << "\nAcessar: ";
  cin >> choice;

  switch (choice){
    case 1:
      {
        cout << "\nPRODUTO || FATURADO || PODE FATURAR\n";
        for (int i = 0; i < Q; i++){
          cout << "Produto " << p[i].nome << "(cod " << p[i].cod << "): R$ " 
                << p[i].faturamento << " | R$ " << std::setprecision(2) 
                << std::fixed<< p[i].pode_faturar << "\n";
        }
        cout << "\nTOTAL FATURADO: R$ " 
              << std::setprecision(2) << std::fixed << total_faturar;
        cout << "\nPODE FATURAR:   R$ " 
              << std::setprecision(2) << std::fixed << total_pode_faturar << "\n";
        break;
      }
    
    case 2:
      {
        cout << "\nTOTAL FATURADO: R$ " 
              << std::setprecision(2) << std::fixed << total_faturar;
        cout << "\nPODE FATURAR:   R$ " 
              << std::setprecision(2) << std::fixed << total_pode_faturar << "\n";
        break;
      }
    
    default:
      cout << "\nOPÇÃO INSERIDA É INVÁLIDA!!!\n";
    }
  } while (choice < 1 || choice > 2);
  
};

//Função para listagem de produtos - USER
void listagem_para_compra(produto p[Q]){
  cout << "\n---- PRODUTOS ----\n";
  for (int i = 0; i < Q; i++){
    cout << p[i].nome << " (cod " << p[i].cod << "): "
         << "R$" << std::setprecision(2) << std::fixed << p[i].valor << "\n";
  }
}

//Função para a tela do usuário
void op_user(produto p[Q]){
  int cod_prod;
  double valor_a_pagar;
  listagem_para_compra(p);
  do{
  cout << "\nQual produto você deseja comprar?\n";
  cout << "Insira o código do produto: ";
  cin >> cod_prod;
  if (cod_prod < 30 and cod_prod >= 0){
    if (p[cod_prod].quant_dispon > 0){
      do{
        cout << "\n---- PAGAMENTO ----";
        cout << "\nO valor é R$" << p[cod_prod].valor;
        cout << "\nQual o valor que você irá pagar?\n";
        cout << "R$";
        cin >> valor_a_pagar;
        if (valor_a_pagar > p[cod_prod].valor){
          cout << "\nSeu troco será de R$" << valor_a_pagar - p[cod_prod].valor;
          cout << "\nO troco será disponibilizado no compartimento à direita.";
          cout << "\nAguarde a liberação do produto...\n";
          p[cod_prod].quant_dispon = p[cod_prod].quant_dispon - 1;
          p[cod_prod].quant_vendida = p[cod_prod].quant_vendida + 1;
          break;
        }
        else if (valor_a_pagar == p[cod_prod].valor){
          cout << "\nAguarde a liberação do produto...\n";
          p[cod_prod].quant_dispon = p[cod_prod].quant_dispon - 1;
          p[cod_prod].quant_vendida = p[cod_prod].quant_vendida + 1;
          break;
        } 
        else {
            cout << "\nValor insuficiente!\n";
        }
      } while (valor_a_pagar < p[cod_prod].valor);
    }  
    else{
      cout << "\nProduto sem estoque!!!\n";
      break;
    }
  } else
      cout << "\nEsse código não existe!!!\n";
      break;
  } while (valor_a_pagar > p[cod_prod].valor);
};

//Função para tela do adminstrador 
void op_adm(produto p[Q]){
  int choice, cont = 0;
  //Lista de aviso dos produtos que precisam de reposição urgente
  cout << "\n! AVISOS !\n";
  for (int i = 0; i < Q; i++){
    if (p[i].quant_dispon == 0){
      cout << "O produto " << p[i].nome << "(cod " << p[i].cod << ") ACABOU!\n";
      cont += 1;
    };
  }; 

  for (int i = 0; i < Q; i++){
    if (p[i].quant_dispon == 1){
      cout << "O produto " << p[i].nome << "(cod " << p[i].cod << ") está com 1 UNIDADE RESTANTE!\n";
      cont += 1;
    };
  }; 

  //Para caso não precise repor estoque de nenhum produto
  if (cont == 0){
    cout << "Tudo sob controle.\n\n";
  };
  
  //Tela do adm para acessar comandos: 
   do{
  cout << "\n---- ADMINISTRADOR ----";
  cout << "\n[1] Listagem de Produtos \n[2] Reposição de Produtos \n[3] Faturamento";
  cout << "\nAcessar: ";
  cin >> choice;

  switch (choice){
    case 1:
      {
        listagem_prod(p);
        break;
      }
    
    case 2:
      {
        repor_prod(p);
        break;
      }
    case 3:
      {
        faturamento(p);
        break;
      }
    default:
      cout << "\nOPÇÃO INSERIDA É INVÁLIDA!!!\n";
    }
  } while (choice < 1 || choice > 3);
 
};

//Função para a tela inicial 
void inicio(produto p[Q]){
  int choice;
  do{
  cout << "\n---- AZAD VENDING ----";
  cout << "\n[1] Usuário \n[2] Administrador";
  cout << "\nEscolha o modo de acesso: ";
  cin >> choice;

  switch (choice){
    case 1:
      {
        op_user(p);
        break;
      }
    
    case 2:
      {
        int senha = 1234; //senha padrão para acesso ao modo Administrador
        int verif;
        do {
          cout << "Digite sua senha de acesso: ";
          cin >> verif;
          if (verif != senha)
          {
            cout << "Senha de acesso incorreta. Tente novamente!\n";
          }
        } while (verif != senha);
        op_adm(p);
        break;
      }
    default:
      cout << "\nOPÇÃO INSERIDA É INVÁLIDA!!!\n";
    }
  } while (choice != 1 && choice !=2);
};

//INT MAIN:
int main() {
  int choice;
  produto prod[Q];

  estoque_2023(prod);
  
  //Acessando tela inicial
  do {
    inicio(prod);

    //Função para perguntar se deseja voltar ao inicio 
    do {
    cout << "\nDeseja retornar ao início? ";
    cout << "\n[1] Sim \n[2] Encerrar\n";
    cout << "Escolha: ";
    cin >> choice;

    switch (choice){
      case 1:
        cout << "\nVoltando... \n";
        break;
      case 2: 
        {
          cout << "\nEncerrando... \n";
          return 0;
        }
      default:
        cout << "\nOPÇÃO INSERIDA É INVÁLIDA!!!\n";
      }
    } while (choice != 1 && choice != 2); 
  } while (choice == 1);
  
  return 0;
}