#include<bits/stdc++.h>
using namespace std;

/*
    Assume `in` is positioned at start of column.
    Accumulates chars from `in` as long as `in` is good
    until either:-
        - Have consumed a comma preceded by 0 quotes,or
        - Have consumed a comma immediately preceded by
        the last of an even number of quotes.
*/
std::string get_csv_column(istringstream & in)
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

int main()
{
    fstream in("new.csv");
    if (!in) {
        cout << "Open error :(" << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    while(getline(in, line)){
        string col;
        istringstream ss(line);
        for (std::string col; ss; ) {
            col = get_csv_column(ss);
            cout << col << std::endl;
        }
        if (!in && !in.eof()) {
            cout << "Read error :(" << endl;
            exit(EXIT_FAILURE);
        }
    }
}