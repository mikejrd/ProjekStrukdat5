#include"node.h"
using namespace std;


class Queue{
    private:
        Node* begin;
        Node* current;
        Node* end;
        
    public:
        Queue(){
            begin = NULL;
            current = NULL;
            end = NULL;
        }
        void display(){
            int i = 1;
            current = begin;
            while(current!=NULL){
                cout << i << ". " << current->video.get_title() << endl;
                i++;
                current = current->next;
            }
        }
        Node next(){
            if(current->checknext()){
                current = current->next;
            }
            return *current;
        }
        Node prev(){
            if(current->checkprev()){
                current = current->prev;
            }
            return *current;
        }
        Node access(int num){
            current = begin;
            int i = 1;
            while(current!=NULL){
                if(i==num){
                    return *current;
                }
                current = current->next;
                i++;
            }
            Node *n = new Node();
            return *n;
            
        }
        void del(int i){

        }
        void insert(Node *n){
            if(begin == NULL){
                begin = n;
                end = begin;
            }else{
                end->next = n;
                n->prev = end;
                end = n;
            }
            // cout<<"b";
            // n->play();

        }
        void move(){ 
            
        }
        
};