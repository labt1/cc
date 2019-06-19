#include<iostream>
#include<string>
using namespace std;

template <class T>
class Pila;

template <class T>
class linked_list;

template <class T>
class Nodo{
    T dato;
    Nodo *next;
    public:
        Nodo(T dato){
            this->dato=dato;
            next=NULL;
        };
        void eliminar_todo(){
            if(next){
                next->eliminar_todo();
            }
            delete this;
        }
        void print_dato(){
            cout<<dato<<"->";
        }
	    T get_dato(){
            return dato;
        }

        Nodo(const Nodo<T>*& n){
            dato=n->dato;
            next=n->next;
        }
        friend class Pila<T>;
        friend class linked_list<T>;
};

template <class T>

class linked_list{
    Nodo<T> * head; 
    int size;

    public:
        linked_list(){
            size=0;
            head=NULL;
        }

        void insertar(T dato, int pos){
            Nodo<T> *nuevo_nodo = new Nodo<T> (dato);
            Nodo<T> *temp = head;
            if(pos!=size && size>pos){
                for(int i=pos; i<size; i++){
                    temp->next;
                }
                nuevo_nodo->next=temp->next;
                temp->next=nuevo_nodo;
                size++;
            }

            else {
                if(pos==1){
                    if (!head) {
                        head = nuevo_nodo;} 
                    else{
                        nuevo_nodo->next=head;
                        head=nuevo_nodo;
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        }    
                    size++;
                }   
                else if(pos!=0){
                    if (!head) {
                        head = nuevo_nodo;}                   
                    else {
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        temp->next = nuevo_nodo;
                    }
                    size++;
                }
            }
        }

        void print(){
            Nodo<T> *temp = head;
            if(temp==NULL){
                
            }

            else{
                cout<<"Tail ";
                for(int i=0;i<size;i++){
                    if(temp!=NULL){
                        temp->print_dato();
                        temp=temp->next;
                    }
                    else cout<<"NULL"<<endl;
                }
                
            }
            cout<<endl;
        }	

        void delete_all(){
            head->eliminar_todo();
            size=0;
        }
        
        Nodo<T>* obtener(int n){
            Nodo<T> * aux=head;
            for(int i=0;i<n-1;i++){
                aux=aux->next;
            }
            return aux;
        }

        void eliminar_head(){
            Nodo<T>* aux;
            aux=obtener(size-1);
            aux->next=NULL;
            size--;
        }
        friend class Pila<T>;
};

template <class T>
class Pila{
    Nodo<T>* head;
    linked_list<T> tail;
    int Size;
    public:
        Pila(){
            head=NULL;
            Size=0;
        }

        void push(T dato){
            if(Size>1){
                tail.insertar(head->dato,Size+1);
            }
            Nodo<T>*temp=new Nodo<T>(dato);
            if(!head){
                head=temp;
                tail.insertar(dato,1);
            }
            else{
                head->next=temp;
                head=temp;    
            }
            Size++;
        }

        void pop(){
            Nodo<T>* temp2 = tail.obtener(Size-1);
            Nodo<T>*temp=head;
            head=temp2;
            tail.eliminar_head();
            delete temp;
            Size--;
        }

        void show(){
            tail.print();
            cout<<"Head ";
            head->print_dato();
            cout<<endl;
        }

        void top(){
            head->print_dato;
        }

        void size(){
            cout<<"Tamaño de la pila "<<tail.size+1;
        }

};

class point{
	public:
		int x, y;
		point(int x1, int y1) :x(x1), y(y1) {}
		point() : x(0), y(0) {}
		int get_punto_x(){return x;}
        int get_punto_y(){return y;}
        void set_puntos(int a, int b){
            x=a; y=b;
        }
		point operator +(point p);

};

point point::operator +(point p) {
	point temp;
	temp.x = x + p.x;
	temp.y = y + p.y;
	return temp;
}

ostream& operator<<(ostream& os, point& punto){
    os<<"("<<punto.get_punto_x()<<" , "<<punto.get_punto_y()<<")"<<" ";
    return os;
}

istream& operator>>(istream& is, point& punto){
    int a,b;
    char z;
    is>>a>>z>>b;
    if(z==','){
        punto.set_puntos(a,b);
        return is;
    }
    else
        cout<<"Invalido"<<endl;
}

int main(){
    Pila<point> pila;
    point dato;
    cout<<"Ingrese los datos"<<endl;
    for (int i = 0; i < 4; i++)
    {
        cin>>dato;
        pila.push(dato);
    }
    cout<<endl;
    pila.size();cout<<endl;
    pila.show();cout<<endl;
    cout<<"Funcion pop elimina: el ultimo elemento LIFO"<<endl;
    pila.pop();cout<<endl;
    pila.size();cout<<endl;
    pila.show();
    return 0;
}
