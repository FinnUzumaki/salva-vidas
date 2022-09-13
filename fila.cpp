#include <iostream>
#include <conio.h>
#define TAMANHO 5

typedef struct PILHA
{
    int topo;
    int item[TAMANHO];

} pilha;

int Menu(const char*, const char**, int);

void Inicializar(pilha&);
void Listar(pilha&);
bool Push(pilha&, int);
int Pop(pilha&);
bool Vazia(pilha&);
bool Cheia(pilha&);

int main()
{
    bool b = true;
    int n;
    pilha p;
    Inicializar(p);
    const char *opcoes[] = {"Adicionar","Remover","Listar","Sair"};
    do
    {
        system("cls");
        switch(Menu("Escolha o que fazer:", opcoes, 4))
        {
        case 0:
            std::cout << "Digite o valor: ";
            std::cin >> n;
            std::cout << (Push(p,n) ? "Valor incluido com sucesso." : "Pilha cheia.");
            break;
        case 1:
            n = Pop(p);
            if(n)
                std::cout << "Valor " << n << " removido.";
            else
                std::cout << "Pilha vazia.";
            break;
        case 2:
            Listar(p);
            break;
        case 3:
            b = false;
            break;
        }
        if(b) getch();
    } while (b);
}

void Inicializar(pilha& p)
{
    p.topo = 0;
}

void Listar(pilha& p)
{
    if(Vazia(p))
        std::cout << "Pilha vazia.";
    else
        for(int i = 0; i < p.topo; i++)
            std::cout << p.item[i] << " ";
}

bool Vazia(pilha& p)
{
    return (p.topo == 0);
}

bool Cheia(pilha& p)
{
    return (p.topo == TAMANHO);
}

bool Push(pilha& p, int n)
{
    if(Cheia(p))
    {
        return false;
    }
    else
    {
        p.item[p.topo++] = n;
        return true;
    }
}

int Pop(pilha& p)
{
    if(Vazia(p))
        return 0;
    else
        return p.item[--p.topo];

}

int Menu(const char *frase, const char **opcoes, int size)
{
    char key = 0;
    int escolhido = 0;
    do
    {
        std::cout << frase << std::endl;
        if(key == 'w') escolhido--;
        else if(key == 's') escolhido++;

        if(escolhido < 0) escolhido = size - 1;
        else if (escolhido > size - 1) escolhido = 0;

        for(int i = 0; i < size; i++)
            std::cout <<  opcoes[i] << (i == escolhido ? "<\n": "\n");
        key = getch();
        system("cls");
    } while (key != 13);
    return escolhido;
}
