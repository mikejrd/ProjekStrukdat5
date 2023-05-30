#include"node.h"
using namespace std;


class Queue{
    public:
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
        void del(int num){
            current = begin;
            int i = 1;
            while(current!=NULL){
                
                if(i==num){
                    if(current->prev == NULL){
                        current->next->prev = NULL;
                        free(current);
                        return;
                    }
                    if(current->next == NULL){
                        current->prev->next = NULL;
                        free(current);
                        return;
                    }
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                    free(current);
                    return;
                }
                current = current->next;
                i++;
            }
            cout << "Video not found" << endl;
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

        }
        void move(int i, int j){ 
            Node temp;
            while(0);
        }

        void clear(){
            Node* prev = begin;
            current = begin;
            while(current!=NULL){
                prev = current;
                current = current->next;
                free(prev);
            }
            begin = NULL;
            current = NULL;
            end = NULL;
        }
        
};