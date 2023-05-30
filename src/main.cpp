// #include"../lib/video.h"
#include"../lib/csvio.h"
// #include"../lib/queue.h"
// #include"../lib/history.h"
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

    main_menu:{
        cout << endl << endl;
        cout << "==================================" << endl;
        cout << "   *** Welcome to Motionate ***   " << endl;
        cout << "World's first educative video bank" << endl;
        cout << "==================================" << endl;
        cout << "1. Browse all videos" << endl;
        cout << "2. Browse Playlists" << endl;
        cout << "3. Browse History" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Enter your choice : ";
        cin >> c;
        cout << endl << endl;
        if (c == 1)
        {
            cout << "======================================" << endl;
            cout << "         All available videos:   " << endl;
        }
        
        switch(c){
            case 1:
            curque = all_videos;
            goto current_queue; break;
            case 2:
            // goto browse_playlist; break;
            case 3:
            cout << "=====================================" << endl;
            cout << "        Your current history:   " << endl;
            history.showHistory();           
            cout << "0. Back to main menu" << endl;
            if (!history.is_empty())
            {
            cout << "1. Clear history" << endl;
            }
            
            cout << "Enter your choice : ";
            cin >> c;
                switch(c){
                    case 0:
                    goto main_menu; break;
                    case 1:
                    history.clearHistory();
                    goto main_menu; break;

                }
        }
    }
    // browse_playlist:{
    //     for (const auto & entry : fs::directory_iterator())
    //     std::cout << entry.path() << std::endl;
    // }

    current_queue:{
        curque.display();
        cout << "=========================================" << endl << endl;

        cout << "0. Back to main menu" << endl;

        cout << "Enter your choiche : ";
        cin >> c;

        switch(c){
            case 0:
            goto main_menu; break;
        }
        
        curnode = curque.access(c);
        goto current_node;
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
}
