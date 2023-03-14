#include <iostream>
/* ATIVIDADE ESTTUTURA DE DADOS GRUPO UNIS-MG
AUTOR: DANILO BELATO
CONTEM 3 FUNÇOES :
UMA PARA CRIA NOVOS No.
OUTRA PARA INSERIR NOVOS VALORES NA ARVORE BINARIA
E UMA PARA BUSCAR UM NUMERO QUE ESTEJA DENTRO DA ARVORE

E ESCREVO ELAS NA TELA EM ORDEM. POS ORDEM E PRE ORDEM.
*/
typedef struct arvore {
    int chave;                  //CRIA UMA ESTRUTURA DE ARVORE COM REF:PAI, FILHO: ESQ E DIR
    struct arvore *esq;
    struct arvore *dir;
    struct arvore *pai;
} Arvore;

// DECLARAÇAO DAS MINHAS FUNÇOES
Arvore *novaArv (int valor);
Arvore *insereArv (Arvore * no,int valor);
Arvore *buscaArv (Arvore * no,int buscar);
void por_ordem( Arvore *no );
void por_pre_ordem( Arvore *no );
void por_pos_ordem( Arvore *no );

Arvore *novaArv (int valor)
{
    arvore * no = new Arvore;  //CRIA UM NOVO NoPARA MINHA ARVORE (CADA No E UMA ARVORE PROPRIA)
    no->chave = valor;
    no->dir = nullptr;
    no->esq = nullptr;
    no->pai = nullptr;

    return no;
}

Arvore *insereArv (Arvore * no,int valor){
    static Arvore *p;

    if( no == nullptr ) {
    Arvore * novo = novaArv(valor);   //COLOCO UM VALOR NO MEU NOVO NO PARA ISSO COMPARO COM A RAIZ SE ELE FOR < ALOCO NA ESQ
    novo->pai = p;                             // CASO CONTRARIO NA DIREITA
    return novo;
    }
    p = no;
    if(valor < no->chave){
        no->esq = insereArv(no->esq, valor);}
    if(valor > no->chave){
        no->dir = insereArv(no->dir,valor);
    }
    return no;
}

  Arvore *buscaArv (Arvore * no,int buscar){

    if(no == nullptr){
        return nullptr;
}
    if (no->chave == buscar){                //BUSCO UM NUMERO NA MINHA ARVORE CASO NÃO EXISTA ELE RETONA NULLPTR
        return no;
    }
        else{
            if( buscar < no->chave ) {
            return buscaArv(no->esq, buscar);
        } else {
            return buscaArv(no->dir, buscar);
                }
            }

        }

void por_ordem( Arvore *no )
{
    if( no == nullptr ) return;

    por_ordem( no->esq );                       //PRINTO NA TELA OS NUMERO EM ORDEM
    std::cout << no->chave << " ";
    por_ordem( no->dir );
}

void por_pre_ordem( Arvore *no )
{
    if( no == nullptr ) return;

    std::cout << no->chave << " ";
    por_pre_ordem( no->esq );              //PRINTO NA TELA OS NUMEROS PRE ORDEM
    por_pre_ordem( no->dir );
}

void por_pos_ordem( Arvore *no )
{
    if( no == nullptr ) return;          // PRINTO NA TELA OS NUMERO POS ORDEM

    por_pos_ordem( no->esq );
    por_pos_ordem( no->dir );
    std::cout << no->chave << " ";
}



int main()
{
    Arvore * raiz = novaArv(30); // DECLARO MINHA RAIZ
    insereArv( raiz,15);
    insereArv( raiz, 25);   // DECLARAÇAO DOS NUMERO QUE IRÃO ENTRAR NA ARVORE
    insereArv( raiz, 35);
    insereArv( raiz, 5);

std::cout << "Arvore:\n - em ordem:\n";   //PRINTA NA TELA EM ORDEM
    por_ordem( raiz );

    std::cout << "\n - pre ordem:\n";      //PRINTA NA TELA EM PRE ORDEM
    por_pre_ordem( raiz );
    std::cout << "\n - pos ordem:\n";      //PRINTA NA TELA EM POS ORDEM
    por_pos_ordem( raiz );
}
