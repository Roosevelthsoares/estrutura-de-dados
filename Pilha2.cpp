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
                //delete[]new_vet; //a memória deixa de estar reservada pelo sistema
            } 
            vet[topo++]=e;
        }
        void desempilhar(){
            if (getTopo() == 0)
                cout << "Pilha Vazia" << endl;
            else{
                topo--;
                if(topo == (tam_max/2)){
                    int *new_vet = new int[tam_max/2];
                    for (int i=0; i<=topo;i++){
                        new_vet[i]=vet[i];
                    }
                    delete[]vet;
                    vet = new_vet;
                }
                
            }
                
        }
         
        int getTopo(){
            return topo;
        
        }

        void visualizar(){
            if(getTopo() == 0){
               cout << "Pilha Vazia" << endl;
            }
            else {
                for(int i = topo; i>0; i--)
                    cout << vet[i-1] << endl;
            }
        }
};

int main(){
    Pilha p;

    cout << "Topo: " <<p.getTopo() << endl;
    p.empilhar(10);
    cout << "Topo: " <<p.getTopo() << endl;
    p.empilhar(11);
    cout << "Topo: " <<p.getTopo() << endl;
    p.empilhar(12);
    cout << "Topo: " <<p.getTopo() << endl;
    p.empilhar(13);
    cout << "Topo: " <<p.getTopo() << endl;
    p.empilhar(14);
    cout << "Topo: " <<p.getTopo() << endl;
    p.empilhar(15);
    cout << "Topo: " <<p.getTopo() << endl;
    p.visualizar();
    cout << " "<<endl;
    p.desempilhar();
    cout << "Topo: " <<p.getTopo() << endl;
    p.desempilhar();
    cout << "Topo: " <<p.getTopo() << endl;
    p.desempilhar();
    cout << "Topo: " <<p.getTopo() << endl;
    p.desempilhar();
    cout << "Topo: " <<p.getTopo() << endl;
    p.desempilhar();
    cout << "Topo: " <<p.getTopo() << endl;
    p.desempilhar();
    cout << "Topo: " <<p.getTopo() << endl;
    p.desempilhar();
    p.desempilhar();
    p.desempilhar();
    p.desempilhar();
    p.desempilhar();
    cout << "Topo: " <<p.getTopo() << endl;
    //p.visualizar();
   
    return 0;
}