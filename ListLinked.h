#include <ostream>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
	    Node<T>* first;
	    int n;
    public:
	    ListLinked(){
		    first = nullptr;
		    n = 0;
	    }
	    ~ListLinked(){
		for(int i=0; i < n; i++){
	    		Node<T>* aux = first->next;
			delete first;
			first = aux;
		}
	    }
	    T operator[](int pos){
		    if(pos < 0 || pos > n){
			    throw out_of_range("La posicion esta fuera del rango");
		    }
		    Node<T>* current = first;
		    for(int i = 0; i < pos; i++){
			    current = current->next;
	   	    }
		    return current->data;
	    }
	    friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
		    out << list->first->data;
		    return out;
 	    }

};
