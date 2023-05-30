#include<string>
#include<vector>
using namespace std;

class Video {
    private:
        string title;
        string desc;
        string cat;
        string tags, duration, date;
        int views;
        int likes;
        int dislikes;
        int comments;
    public:
        Video(){
            title = "";
            desc = "";
            cat = "";
            tags.clear();
            int views = 0;
            int likes = 0;
            int dislikes = 0;
            int comments = 0;
        }
        Video(string t, string d, string c, string ta, string du, string da, int v, int l, int dis, int co){
            title = t;
            desc = d;
            cat = c;
            tags = ta;
            duration = du;
            date = da;
            views = v;
            likes = l;
            dislikes = dis;
            comments = co;
        }
        string get_title(){
            return title;
        }
        string get_desc(){
            return desc;
        }
        string get_cat(){
            return cat;
        }
        string get_tags(){
            return tags;
        }
        string get_dur(){
            return duration;
        }
        string get_date(){
            return date;
        }
        int get_views(){
            return views;
        }
        int get_likes(){
            return likes;
        }
        int get_dislikes(){
            return dislikes;
        }
        int get_comments(){
            return comments;
        }
};