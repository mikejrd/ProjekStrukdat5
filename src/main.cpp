// #include"../lib/video.h"
#include"../lib/csvio.h"
// #include"../lib/queue.h"
#include"../lib/history.h"
#include<map>
#include<iostream>
using namespace std;


// template<typename T>
// vector<T> tempvec()

int main(){
    //all
    map<string, Video> all_unique_video;
    Queue all_videos;
    //current
    Queue curque;
    Node curnode;
    //temp
    Queue tempque;
    Node tempnode;
    //user input
    int c; // case
    string word;
    //history
    stackHistory history;

    load(all_videos, "new");

    main_menu:
    cout << "1. Browse all videos" << endl;
    cout << "2. Browse Playlists" << endl;
    cout << "3. Browse History" << endl;
    cout << "4. Exit" << endl << endl;
    cout << "Enter your choiche..." << endl;
    cin >> c;

    switch(c){
        case 1:
        curque = all_videos;
        goto current_queue; break;
        case 3:
        cout << "============================" << endl;
        history.showHistory();
        cout << "============================" << endl;
        cout << "1. Back to main menu" << endl;
        switch (c){
        case 1:
        goto main_menu; break;
        }
    }

    current_queue:
    curque.display();
    cout << "0. Back to main menu" << endl;

    cout << "Enter your choiche..." << endl;
    cin >> c;

    switch(c){
        case 0:
        goto main_menu; break;
    }
}