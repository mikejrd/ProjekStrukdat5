#include"queue.h"
#include<map>
#include <sys\stat.h>
#include <iostream>
#include<fstream>
#include<sstream>
#include<conio.h>
// #include<filesystem>
#include<dirent.h>

using namespace std;

string get_csv_column(istringstream & in)
{
    std::string col;
    unsigned quotes = 0;
    char prev = 0;
    bool finis = false;
    for (int ch; !finis && (ch = in.get()) != EOF; ) {
        switch(ch) {
        case '"':
            ++quotes;
            break;
        case ',':
            if (quotes == 0 || (prev == '"' && (quotes & 1) == 0)) {
                finis = true;
            }
            break;
        default:;
        }
        if((ch=='"') || (ch==',')){
            prev = ch;
            continue;
        }
        col += prev = ch;
    }
    return col;
}

void load(Queue& queue, string name){
    queue.clear();
    string playlist_name = "..\\videofiles\\"+ name +".csv";
    fstream in (playlist_name, ios::in);
    string line;
    while(getline(in, line)){

        string col;
        string title, desc, cat, tags, duration, date;
        int views, likes, dislikes, comments;
        istringstream ss(line);
        col = get_csv_column(ss);
        title = col;
        col = get_csv_column(ss);
        desc = col;
        col = get_csv_column(ss);
        cat = col;
        col = get_csv_column(ss);
        tags = col;
        col = get_csv_column(ss);
        duration = col;
        col = get_csv_column(ss);
        date = col;
        col = get_csv_column(ss);
        views = stoi(col);
        col = get_csv_column(ss);
        likes = stoi(col);
        col = get_csv_column(ss);
        dislikes = stoi(col);
        col = get_csv_column(ss);
        comments = stoi(col);

        Video temp(title, desc, cat, tags, duration, date, views, likes, dislikes, comments);
        Node* n = new Node(temp);
        
        queue.insert(n);
    }
}

void save(Queue &queue, string name){
    string playlist_name = "..\\videofiles\\"+ name +".csv";
    fstream out (playlist_name, ios::out);
    
    queue.current = queue.begin;
    while(queue.current!=NULL){
        out <<
        queue.current->video.get_title()
        << "," <<
        queue.current->video.get_desc()
        << "," <<
        queue.current->video.get_cat()
        << "," <<
        queue.current->video.get_tags()
        << "," <<
        queue.current->video.get_dur()
        << "," <<
        queue.current->video.get_date()
        << "," <<
        queue.current->video.get_views()
        << "," <<
        queue.current->video.get_likes()
        << "," <<
        queue.current->video.get_dislikes()
        << "," <<
        queue.current->video.get_comments() << endl;
        queue.current = queue.current->next;
    }
}

void get_playlists()
{
	struct dirent *d;
	struct stat dst;
	
	DIR *dr;
	
	string path = "..\\videofiles\\";
	
	dr = opendir(path.c_str());
	
	if (dr != NULL)
	{   
        int i = 1;
		for (d = readdir(dr); d != NULL; d = readdir(dr))
		{
			string type = d->d_name;
            string temp = path + type;
            if (stat(temp.c_str(), &dst) == 0)
			{
				if (dst.st_mode & S_IFDIR)
				{
					;
				}
				else if (dst.st_mode & S_IFREG)
				{
                    cout<< i << ". " << type.substr(0, type.find(".csv")) << endl;
                    i++;
				}
			}
            
		}
		closedir(dr);
	}
}
string access_playlist(int j)
{
	string ret;
    struct dirent *d;
	struct stat dst;
	
	DIR *dr;
	
	string path = "..\\videofiles\\";
	
	dr = opendir(path.c_str());
	
	if (dr != NULL)
	{   
        
        int i = 1;
		for (d = readdir(dr); d != NULL; d = readdir(dr))
		{
			string type = d->d_name;
            string temp = path + type;
            
            if (stat(temp.c_str(), &dst) == 0)
			{
				if (dst.st_mode & S_IFDIR)
				{
					;
				}
				else if (dst.st_mode & S_IFREG)
				{
                     if(i==j){
                        ret = type.substr(0, type.find(".csv"));
                        break;
                    }
                    i++;
				}
			}
		}
		closedir(dr);
	}
    return ret;

    
}
void add_to_queue(Queue &queue){
    string title, desc, cat, tags, duration, date;
    int views, likes, dislikes, comments;
    cout << "Enter video title:" << endl;
    cin >> title;
    cout << "Enter video description:" << endl;
    cin >> desc;
    cout << "Enter video category:" << endl;
    cin >> cat;
    cout << "Enter video tags:" << endl;
    cin >> tags;
    cout << "Enter video duration:" << endl;
    cin >> duration;
    cout << "Enter video date:" << endl;
    cin >> date;
    cout << "Enter video views:" << endl;
    cin >> views;
    cout << "Enter video likes:" << endl;
    cin >> likes;
    cout << "Enter video dislikes:" << endl;
    cin >> dislikes;
    cout << "Enter video comments:" << endl;
    cin >> comments;

    Video temp(title, desc, cat, tags, duration, date, views, likes, dislikes, comments);
    Node* n = new Node(temp);
    
    queue.insert(n);
}