#include <iostream>
#include <string>
#include <List>
#include <fstream>
#include<stdio.h>
using namespace std;

template <typename T,typename V>
class Map{
	private:
		class Node{
			private:
				T data;
				V value;
				Node* right;
				Node* left;
			public:
				Node(T d, V v){
					data= d;
					value=v;
					right=NULL;
					left=NULL;
				}
			
			T getdata(){return data;}
			V& getvaluep(){ return value;}
			V getvalue(){return value;}
			
			Node* getleft(){return left;}
			Node* getright(){return right;}
			
			bool hasleft(){
				return left != NULL;
			}
			bool hasright(){
				return right!=NULL;
			}
			
			void setleft(Node* n){
				left=n;
			}
			void setright(Node* n){
				right=n;
			}
			
			void setvalue(){
				value= value+1;
			}
			
			void setValue2(string a){
				value.push_back(a);
			}
				
		};
	Node* root;
	 
	
	public:
	Map(){
		root=NULL;
	}

	Node* getroot(){
		return root;
	}
	
	void insert(T e, V k, Node* n){
		
		if(e == n->getdata()){
			
			n->setvalue();
	    }
		else if (e < n -> getdata()){
				
			if(n->hasleft())
			
				insert(e,k,n->getleft());
			else{
				Node *j= new Node(e,k);
				n->setleft(j);
				}
		}
		
		else{
			
			if(n->hasright())
				insert(e,k,n->getright());
			else {
				Node *j= new Node(e,k);
				n->setright(j);
			}
	    }
      }
      
	void insert(T e, V k){
		if(root!=NULL){
			
			insert(e,k,root);
		}
		else
		root= new Node(e,k);
	}
	
	void print(Node* n){
		if(n!=NULL){
		cout<<n->getdata()<<"-"<< n->getvalue()<<endl;
		print (n->getleft());
		print(n->getright());
		}
    }

	void print(){
		print(root);
	}    


// NEW BST

	Node* search(T d, Node* n){
		if(n != NULL){
			if(d == n->getdata()){
				return n;
			}
			if(d < n->getdata()){
				return search(d,n->getleft());
			}
			if(d > n->getdata()){
				return search(d,n->getright());
			}
		}
		else{
			return NULL;
		}
	}

	Node * search(T d){
		return search(d,root);
	}
	void newbst(Map* newmap,Node *n){
		if(n != NULL){
			newbst(newmap,n->getleft());
			newmap->insert(n->getvalue() ,n->getdata());
			newbst(newmap,n->getright());
		}
	}

	bool itsreal(Node* j,T d){
		if(j==NULL)return false;
			else{
				if(j->getdata() == d)return true;
				else if (d < j->getdata()){
                	itsreal(j->getleft(), d);
              	}
              	else {
                	itsreal(j->getright(), d);
              	}
        	}
  	}
	 bool itsarealdata(T d){
     	itsreal(root,d);
  }
		
	V& givevalue(Node *n, T d){
		 if (d == n->getdata()) return (n->getvaluep());
        else if (d < n->getdata()){
             givevalue(n->getleft(), d);
             }
         else {
             givevalue(n->getright(),d);
             }
  	}

	V& returnvalue(T d){
    	givevalue(root,d);
  	}  
	
	void Insert2(Map<int,list<string> > &newmap, Node* n){
   	 if (n!=NULL){

    	Insert2(newmap,n->getleft());
      	if(newmap.itsarealdata(n->getvalue())){
        	newmap.returnvalue(n->getvalue()).push_back(n->getdata());
      	}
      	else{
       	 	list<T> aux;
        	aux.push_back(n->getdata());
        	newmap.insertnew(n->getvalue(),aux);
      	}	
      	Insert2(newmap,n->getright());
    	}
  	}

	void insertnew (T nkey, V ndata){
      Node* nwnode= new Node(nkey,ndata);
      if (root == NULL){
        root= nwnode;
        cout << "root" << '\n';
      }
	}

	void maptomap(Map<int,list<string > > &newmap){
		Insert2(newmap,root);
	}

};

bool isAlpaChar(char c){
	if(c >= 'a' && c <= 'z')return true;
	if(c >= 'A' && c <= 'Z')return true;
	return false;
}

string ReadFile (string filename)
{
  fstream input(filename);
  string completeFile;
  string line;
  while (getline(input, line))
  {
    completeFile.append(line);
  }
  return(completeFile);
}

bool isAlphachar (char c)
{
  if (c>='a' && c<='z')return true;
  if (c>='A' && c<='Z')return true;
  return false;

}

int main() {
	string book=ReadFile("prueba.txt");
 	Map<string,int> libro;
 	for(int i=0;i<book.size();){
 		string w;
 		while(isAlpaChar(book[i])){
 			w.push_back(book[i]);
 			i++;
		 }
		 libro.insert(w,1);
		 while(!isAlpaChar(book[i])){
		 	i++;
		 }
	 }
	libro.print();
	//Map<int, list<string>> newbst;
	//libro.maptomap(newbst);
	
}
