#include <iostream>

using namespace std;

class Fila{
    private:
        int fim;
        int tam;
        int inicio;
        int *vet;
    public:
        Fila():
            fim(0), tam(2), inicio(0), vet(new int[tam]){

            }
        Fila(Fila &f):
            fim(f.fim), tam(f.tam), inicio(f.inicio), vet(new int[tam]){
                for(int i=0; i<tam; i++)
                    vet[i]=f.vet[i];
            }
        ~Fila(){
            delete[]vet;
        }

        int getFim(){return fim;}
        int getInicio(){return inicio;}
        int getTam(){return tam;}

        //insere no fim
        void inserir(int e){
            if(fim == tam){
                tam = 2*tam;
                int *new_vet = new int[tam]; 
                for(int i=0; i <= fim; i++){
                    new_vet[i] = vet [i];
                }
                delete[]vet;
                vet = new_vet;
            }
            vet[fim++]=e;
        }

        //remove do inicio
        void remover(){
            inicio++;

            if(fim == inicio){
                cout << "Fila vazia"  << endl;
            } else if(fim == tam/2){
                    int *new_vet = new int[tam/2];
                    for(int i=0; i<= fim; i++){
                        new_vet[i] = vet[i];
                    }
                    delete[]vet;
                    vet = new_vet;
                }
        }

        void visualisar(){
            if(inicio == 0){
                for(int i=inicio; i < fim; i++)
                    cout << "Posicao: " << i+1 << " - " << "Valor: " << vet[i] << endl;
            }else{
                for(int i=0; i < fim-inicio; i++)
                    cout << "Posicao: " << i+1 << " - " << "Valor: " << vet[i+inicio] << endl;  
            }
        }
};

int main(){
    Fila f;

    f.inserir(10);
    f.inserir(20);
    f.inserir(30);
    f.inserir(40);
    f.inserir(50);
    f.inserir(60);
    f.inserir(70);
    f.inserir(80);
    f.visualisar();
    cout << " " << endl;
    f.remover();
    f.remover();
    f.remover();
    f.remover();
    f.visualisar();
   

    return 0;
}