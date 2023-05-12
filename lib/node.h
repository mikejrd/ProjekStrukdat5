#include"video.h"
#include<iostream>
using namespace std;

class Node{
    public:
        Video video;
        Node* prev;
        Node* next;
        Node(){
            prev = NULL;
            next = NULL;
        }
        Node(Video v){
            prev = NULL;
            video = v;
            next = NULL;
        }
        void play(){
            cout << "Playing " << video.get_title() << "..." << endl;
            cout << "Finished playing " << video.get_title() << "." << endl;
        }
};