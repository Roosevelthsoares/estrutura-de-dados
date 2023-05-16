#include <iostream>
#include <conio.h>
using namespace std;

enum modoDeque {FRENTE, RETAGUARDA};

class Deque{
    private:
        int inicio;
        int fim;
        int tam_max;
        int cp; //capacity
        int *vet;

    public:
        Deque(int tam_max):
            inicio(tam_max-1), fim(0),tam_max(tam_max), cp(0), vet (new int[tam_max]){
                for(int i = 0; i < tam_max; i++)
                    vet[i] = 0;

            }
        Deque(const Deque &d):
            inicio(d.inicio), fim(d.fim), tam_max(d.tam_max), cp(d.cp), vet(new int[tam_max]){
                for(int i=0; i<=tam_max; i++)
                    vet[i] = d.vet[i];
                cout << "Construtor de copia" << endl;

            }
        ~Deque(){
            delete[]vet;
        }

        void getInicio(){cout << "Inicio: " << inicio << endl;}
        void getFim(){cout << "Fim: " << fim << endl;}
        void getTam_max(){cout << "Tam_max: " << tam_max << endl;}
        void getCp(){cout << "Capacity: " << cp << endl;}

        void inserir(modoDeque sentido, int e){
            if(cp == tam_max){
                cout << "impossivel inserir - CHEIO" << endl;
                inicio = tam_max - 1;
                fim = 0;
            }else if(sentido){
                        // if(fim!=(inicio+1)){
                            fim = fim%tam_max;
                            vet[fim++] = e;
                            cp += 1;                 
                        // }else{
                        //     cout << "Deque Cheio pela Retaguarda" << endl;
                        // }
                    }else if(inicio < 0){
                        // if(fim!=inicio){
                            inicio = (tam_max+inicio%tam_max)%tam_max;
                            vet[inicio--] = e;  
                            cp += 1;
                        // }else{
                        //     cout << "Deque Cheio pela Frente" << endl;
                        // }
                            } else{
                                inicio = (inicio)%tam_max;
                                vet[inicio--] = e;  
                                cp += 1;                 
                            }
        }

        void remover(modoDeque sentido){
                if(cp == 0){
                    cout << "impossivel remover - VAZIO" << endl;
                }else   if(sentido){
                            fim=(fim-1)%cp;
                            cp -= 1;                 
                        }else{
                            inicio = (inicio+1)%cp;
                            cp -= 1;                 
                        }
                //caso o deque tenha todos os item removidos - setar para varicaveis iniciais        
                if(cp == 0){
                    inicio = tam_max -1;
                    fim = 0;
                }
            }
        
        void imprimir(){
            //impressão teste
            for(int i = 0; i<tam_max; i++)
            {
                cout << vet[i] << " ";
            }
                cout << endl;

            //da frente para retaguarda    
            for(int i = 1; i<=cp; i++)
            {
                cout << vet[(inicio+i)%tam_max] << " ";
            }
                cout << endl; 
        }
};

class Fila: public Deque{
    public:
        Fila(int tam_max):
            Deque(tam_max){ // ATENÇÃO AO DECLARAR CONSTRUTOR DA HERANÇA - NÃO USAR TIPO NESTE CASO

        }

        void inserir(int valor){
            Deque::inserir(RETAGUARDA, valor);
        }

        void remover(){
            Deque::remover(FRENTE);
        }

        void imprimir(){
            Deque::imprimir();
        }
};

int main(){
    Deque d(4);
    // 30 10 20 40
    d.getInicio();
    d.getFim();
    d.inserir(FRENTE,10);
    d.getInicio();
    d.getFim();
    d.inserir(FRENTE,30);
    d.getInicio();
    d.getFim();
    d.inserir(FRENTE,20);
    d.getInicio();
    d.getFim();
    d.inserir(FRENTE,40);
    // d.inserir(FRENTE,50);

    d.imprimir();
    d.getInicio();
    d.getFim();
    //d.getTam_max();
    d.getCp();


    d.remover(FRENTE);
    d.remover(FRENTE);
    d.remover(FRENTE);
    d.remover(FRENTE);
    // d.remover(RETAGUARDA);
    // d.remover(RETAGUARDA);
    // d.remover(RETAGUARDA);
    // d.remover(RETAGUARDA);
    // d.remover(FRENTE);
    // d.remover(FRENTE);
    // d.remover(FRENTE);
    // d.remover(FRENTE);
    // d.remover(FRENTE);
        // d.remover(FRENTE);
        // d.remover(RETAGUARDA);
        // d.remover(FRENTE);
        // d.remover(RETAGUARDA);
    d.getInicio();
    d.getFim();
    d.getCp();
    d.imprimir();

    d.inserir(FRENTE,66);
    d.inserir(RETAGUARDA,42);
    d.inserir(FRENTE,77);
    d.inserir(RETAGUARDA, 52);
    // d.inserir(FRENTE,66);
    d.getInicio();
    d.getFim();
    d.getCp();
    d.imprimir();

    Fila f(4);

    f.inserir(10);
    f.inserir(20);
    f.inserir(30);
    f.inserir(40);
    f.imprimir();
    f.remover();
    f.imprimir();
    f.remover();
    f.imprimir();
    f.remover();
    f.imprimir();
    f.remover();
    f.imprimir();
    f.remover();
    f.imprimir();

    return 0;
}