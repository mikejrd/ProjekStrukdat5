#include"node.h"
using namespace std;


class Queue{
    private:
        Node* begin;
        Node* current;
        Node* end;
        bool checknext(){
            if(current->next!=NULL){
                return true;
            }
        }
        bool checkprev(){
            if(current->prev!=NULL){
                return true;
            }
        }
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
        void next(){
            if(checknext()){
                current = current->next;
            }
        }
        void prev(){
            if(checkprev()){
                current = current->prev;
            }
        }
        void access(int num){
            current = begin;
            int i = 1;
            while(current!=NULL){
                if(i==num){
                    current->play();
                }
                current = current->next;
                i++;
            }
            
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