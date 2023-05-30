#include"../lib/csvio.h"
// #include"../lib/util.h"
#include<iostream>
using namespace std;


int main(){
    //all
    map<string, Video> all_unique_video;
    Queue all_videos;

    //current
    Queue curque;
    Node curnode;
    string curquen;

    //user input
    int c; // case
    int index;
    string word;
    //history
    stackHistory history;
    system("cls");

    main_menu:{
        cout << endl << endl;
        cout << "==================================" << endl;
        cout << "   *** Welcome to Motionate ***   " << endl;
        cout << "World's first educative video bank" << endl;
        cout << "==================================" << endl;
        cout << "1. Browse all videos" << endl;
        cout << "2. Playlists" << endl;
        cout << "3. History" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Enter your choice : ";
        cin >> c;

        switch(c){
            case 1:
            curquen = "allvideos\\all videos";
            goto current_queue; break;
            case 2:
            goto browse_playlist; break;
            case 3:
            cout << "============================" << endl;
            cout << "Your current history: " << endl;
            history.showHistory();           
            cout << "0. Back to main menu" << endl;
            if (!history.is_empty())
            {
            cout << "1. Clear history" << endl;
            }
            
            cout << "Enter your choice : ";
            cin >> c;
            system("cls");
                switch(c){
                    case 0:
                    goto main_menu; break;
                    case 1:
                    history.clearHistory();
                    cout << "0. Back to main menu" << endl;
                    cin >> c;
                    system("cls");
                    switch(c){
                        case 0:
                        goto main_menu; break;
                    }
                    goto main_menu; break;

                }
            case 4:
            exit(0);
        }
    }
    
    current_queue:{
        load(curque, curquen);
        curque.display();
        cout << "=========================================" << endl << endl;

        cout << "0. Back to main menu" << endl;

        cout << "Enter your choiche..." << endl;
        cin >> c;
        system("cls");

        switch(c){
            case 0:
            goto main_menu; break;
            case 99:
            goto edit; break;
        }
        
        curnode = curque.access(c);
        goto current_node;
    }
    
    browse_playlist:{
        system("cls");
        get_playlists();
        cout << "0. Back to main menu" << endl;
        cout << "Enter your choice..." << endl;
        cin >> c;
        switch(c){
            case 0:
            goto main_menu; break;
        }
        curquen = access_playlist(c);
        goto current_queue;
    }

    current_node:{
        history.push(curnode.video.get_title());
        curnode.display();
        cout << "=========================================" << endl;
        cout << "0. Back to main menu" << endl << endl;
        cout << "Enter your choice..." << endl;
        cin >> c;
        switch(c){
            case 1: 
            curnode = *(curnode.prev);
            goto current_node; break;
            case 2: 
            curnode = *(curnode.next);
            goto current_node; break;
            case 0:
            goto main_menu; break;
        }
    }
    edit:{
        cout << "1. Add a video" << endl;
        cout << "2. Move a video" << endl;
        cout << "3. Remove a video" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Enter your choice..." << endl;
        cin >> c;
        switch(c){
            case 1: 
            cout << "Current playlist" << endl;
            curque.display();
            add_to_queue(curque);
            save(curque, curquen);
            goto edit; break;
            case 2: 
            cout << "Current playlist" << endl;
            curque.display();
            curque.move(2, 3);
            save(curque, curquen);
            goto edit; break;
            case 3:
            cout << "Current playlist" << endl;
            curque.display();
            cin >> index;
            curque.del(index);
            save(curque, curquen);
            case 0:
            goto main_menu; break;
        }
    }
    
    
}
