#include <iostream>

using namespace std;

class Pilha{
    private:
        int topo;
        int tam_max;
        int *vet;
    public:
        Pilha():
            topo(0),tam_max(2),vet(new int[tam_max]){
        }
        Pilha(Pilha &p):
            topo(p.topo),tam_max(p.tam_max),vet(new int[tam_max]){
                for(int i=0;i<=tam_max;i++)
                    vet[i] = p.vet[i];
        }
        ~Pilha(){
            delete[]vet;
        }

        void empilhar(int e){
            if(topo == tam_max){
                tam_max = 2 * tam_max; //dobrar o tamanho, para inserção ser O(log n)
                int *new_vet = new int[tam_max];
                for(int i=0;i<topo;i++){
                    new_vet[i] = vet[i];
                }
                delete[]vet; //a memória deixa de estar reservada pelo sistema
                vet = new_vet; // vet passa a apontar para o endereço de memória de new_vet
            } 
            vet[topo++]=e;
        }
        void desempilhar(){
            if (topo == 0)
                cout << "Pilha Vazia" << endl;
            else{
                topo--;
                delete vet(topo);

            }
                
        }
        int vazia(){
           // if (topo != -1)
           //     return 1;
           // return -1;
           return (topo == -1); //VERDADE = 1
        }
        int getTopo(){
            if(topo != -1)
                return vet[topo];
            return -1; //caso contrario retornara o lixo da memoria
        }
        void visualizar(){
            for(int i = topo; i>=0; i--)
                cout << vet[i] << endl;
        }
};

int main(){
    Pilha p;
    //p.getTopo();
    cout << "Topo: " << p.getTopo()<<endl;
    cout << "Fila Vazia: " << p.vazia()<<endl;
    //p.vazia();
    p.empilhar(10);
    p.empilhar(11);
    p.empilhar(12);
    p.visualizar();
    p.desempilhar();
    p.visualizar();
    cout << "Topo: " << p.getTopo()<<endl;
    cout << "Fila Vazia: " << p.vazia()<<endl;
    return 0;
}