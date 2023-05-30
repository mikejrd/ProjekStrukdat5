#include"video.h"
#include"history.h"
#include<iostream>
using namespace std;

class Node{
    public:
        Video video;
        Node* prev;
        Node* next;
        stackHistory history;
        Node(){
            prev = NULL;
            next = NULL;
        }
        Node(Video v){
            prev = NULL;
            video = v;
            next = NULL;
        }
        bool checknext(){
            if(next!=NULL){
                return true;
            }
        }
        bool checkprev(){
            if(prev!=NULL){
                return true;
            }
        }
        void play(stackHistory &h){
            if(video.get_title() ==""){
                cout << "Video not found..." << endl;
                free(this);
                return;
            }
            cout << "Playing " << video.get_title() << "..." << endl;
            h.push(video.get_title());
            cout << "Finished playing " << video.get_title() << "." << endl;
        }
        void display(){
            if(checkprev()){
                cout << "1. Previous: " << prev->video.get_title() << endl;
            }
            if(checknext()){
                cout << "2. Next: " << next->video.get_title() << endl;
            }
        }
};