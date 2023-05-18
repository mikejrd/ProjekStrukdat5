#include"queue.h"
#include<map>
#include<fstream>
#include<sstream>

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
void save(Queue queue, string name){
    string playlist_name = "..\\videofiles\\"+ name +".csv";
    fstream out (playlist_name, ios::out);
    out << "lol"; 
}