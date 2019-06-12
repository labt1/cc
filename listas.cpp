#include<iostream>
#include<string>
using namespace std;

template <class T>

class Nodo{
    T dato;
    public:
        Nodo *next;
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
};

template <class T>

class linked_list{
    Nodo<T> *head; 
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
        }

        void print(){
            Nodo<T> *temp = head;
            if(!head){
                cout<<"La lista esta vacia"<<endl;
            }

            else{
                while(temp){
                    temp->print_dato();
                    if(!temp->next){cout<<"NULL";}
                    temp=temp->next;
                }
            }
            cout<<endl;
        }

        void delete_all(){
            head->eliminar_todo();
            size=0;
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
    cout<<"Se elimina la lista"<<endl;
    list_2.delete_all();
    list_2.print();

    return 0;
}

