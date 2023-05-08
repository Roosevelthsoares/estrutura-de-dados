#include <iostream>


using namespace std;

class Pilha{
    private:
        int *vet;
        int tam_max; //tamanho do vetor-1
        int topo;
    public:
        Pilha(){
            vet = new int[100];
            tam_max = 99;
            topo = -1;
        }
        ~Pilha(){
            delete[] vet;
        }
        void empilhar(int e){
            if(topo == tam_max)
                cout << "Pilha cheia" << endl;
            else{
                vet[++topo]=e;
            }
        }

        void desempilhar(){
            if (topo == -1)
                cout << "Pilha Vazia" << endl;
            else{
                //delete vet(topo);
                topo--;               
            }
        }

        int getTopo(){
            if (topo != -1)
                return vet[topo]; //ATENÇÃO! retorna o elemento que está no topo
            return -1;
        }

        int vazia(){
            return (topo == -1);
        }
        void visualizar(){
            for(int i=topo; i>=0; i--)
                cout << vet[i] << endl;
        }
};

int main(){
    Pilha p;

    cout << "Pilha Vazia: " << p.vazia() << endl;
    cout << "Topo: " << p.getTopo() << endl;

    p.empilhar(10);
    p.empilhar(11);
    p.empilhar(12);

    p.visualizar();
    p.visualizar();

    return 0;
}