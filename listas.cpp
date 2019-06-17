#include<iostream>
#include<string>

using namespace std;

template <class T>
class _iterator;

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
        friend class linked_list<T>;
        friend class _iterator<T>;
};

template <class T>

class _iterator{
    Nodo<T> * it;
    int posicion;
    public:
        _iterator(Nodo<T>* nodo){
            it=nodo;
        }

        bool estado(){
            return (it!=NULL);
        }

        Nodo<T>* next(){
            Nodo<T> * aux;
            if(estado()){
                aux=it;
                it=it->next;
                return aux; 
            return NULL;        
            }
        }
    friend class linked_list<T>;    

};

template <class T>

class linked_list{
    Nodo<T> * head; 
    _iterator<T>* itr;
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
                else{
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
            itr=new _iterator<T>(head);
        }

        void print(){
            Nodo<T> *temp = head;
            if(temp==NULL){
                
            }

            else{
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
	
        void buscar(T dato){
            bool b=false;
            Nodo<T> *temp=head;
            for(int i=0; i<size; i++){
                if(temp->get_dato()==dato){
                    cout<<"El dato "<<dato<<" esta en la lista "<<"en la posicion "<<i+1<<endl;
                    b=true;
                    break;
                }
                 temp=temp->next;
            }
            if(b==false) cout<<"El dato no esta en la lista"<<endl;
        }		

        void delete_all(){
            head->eliminar_todo();
            size=0;
        }

        _iterator<T>* get_iterador(){
            return itr;
        }
        
        Nodo<T>* obtener(int n){
            itr->it=head;
            Nodo<T> * aux;
            for(int i=0;i<n;i++){
                aux=itr->next();
            }
            return aux;
        }

        void eliminar_pos(int pos){
            Nodo<T> *temp;
            if(pos!=size && size>pos){
                temp=this->obtener(pos-1);
                temp->next=this->obtener(pos+1);

                this->obtener(pos)->next=NULL;
                delete this->obtener(pos);
                size--;
            }

            else {
                if(pos==1){
                    head=obtener(pos+1);
                    delete obtener(pos);
                    size--;
                }   
                else{
                    delete obtener(pos);
                    size--;
                }
            }
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
    is>>a>>b;
    punto.set_puntos(a,b);
    return is;
}

int main(){
    
    cout<<"Lista de puntos"<<endl;
    linked_list<point> list_1;
    point pt;
    for (int i = 1; i <= 3; i++)
    {
        cin>>pt;
        list_1.insertar(pt,i);
    }
    list_1.print();
    cout<<endl;
    cout<<"Lista de enteros"<<endl;
    linked_list<int> list_2;
    int n;
    for (int i = 1; i <= 3; i++)
    {
        cin>>n;
        list_2.insertar(n,i);
    }
    list_2.print();
    cout<<endl;
    cout<<"Lista de cadenas"<<endl;
    linked_list<string> list_3;
    string cad;
    for (int i = 1; i <= 3; i++)
    {
        cin>>cad;
        list_3.insertar(cad,i);
    }
    list_3.print();
    cout<<endl;
    //cout<<"Se elimina el segundo elemento de la lista 2"<<endl;
    //list_2.eliminar_pos(2);
    list_2.print();
    cout<<"Buscar un dato en la lista 3"<<endl;
    cin>>cad;
    list_3.buscar(cad);
    cout<<"Iterador"<<endl;
    _iterator<string>* it = list_3.get_iterador(); 
    list_3.obtener(1)->print_dato();
    list_3.obtener(3)->print_dato();

    return 0;
}

