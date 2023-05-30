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
                        
                    cout << "Successfully deleted video" << endl;
                        return;
                    }
                    if(current->next == NULL){
                        current->prev->next = NULL;
                        free(current);
                        
                    cout << "Successfully deleted video" << endl;
                        return;
                    }
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                    free(current);
                    
                    cout << "Successfully deleted video" << endl;
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

        void moves(int j, int k){
            current = begin;
            int i = 1;
            Node *move, *temp;
            
            while(current!=NULL){
                if(i==j){
                    move = current;
                    if((move->prev == NULL) && (move->next == NULL)){
                        cout << "Error. There's only 1 video in the playlist";
                    }else if(move->prev == NULL){
                        move->next->prev = NULL;
                    }else if(move->next == NULL){
                        move->prev->next = NULL;
                    }else{
                        move->next->prev = move->prev;
                        move->prev->next = move->next;
                    }
                    break;
                }
                current = current->next;
                i++;
            }
            if(current==NULL){
                cout << "Video not found" << endl;
                return;
            }

            current = begin;
            i=1;

            while(current!=NULL){
                if(i==k){
                    current->prev->next = move;
                    move->prev = current->prev;
                    move->next = current;
                    current->prev = move;
                    cout << "Successfully moved video" << endl;
                    break;
                }
                current = current->next;
                i++;
            }
            if(current==NULL){
                cout << "Video not found" << endl;
            }
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