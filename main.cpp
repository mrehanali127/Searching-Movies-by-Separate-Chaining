#include <iostream>
#include<fstream>
using namespace std;

class node
{
private:
    string movie_Id;
    double movie_rate;
    int movie_votes;
    node *next;
public:
    node(string d,double r,int v)           //Node with Three Attributes
    {
        movie_Id=d;
        movie_rate=r;
        movie_votes=v;
        next=NULL;
    }
    void set_Id(string d)                 //Setter
    {
        movie_Id=d;
    }
    void set_Rate(double rate)
    {
        movie_rate=rate;
    }
    void set_Vote(int vote)
    {
        movie_votes=vote;
    }
    string get_Id()                     //Getter
    {
        return movie_Id;
    }
    double get_Rate()
    {
        return movie_rate;
    }
    int get_vote()
    {
        return movie_votes;
    }

    void set_next(node *n)
    {
        next=n;
    }
    node* get_next()
    {
        return next;
    }
};

//list Class
class list
{
private:
    node *first;
public:
    list()                         //List class constructor
    {
        first=NULL;
    }

    //function to add node at start of list
    void add_atstart(string id,double rate,int votes)
    {
        node *temp=new node(id,rate,votes);
        node *temp2=first;
        first=temp;
        first->set_next(temp2);

    }
    //function find movie By Rating
    void Find_Rate(double x)
    {
        node *temp=first;
        int counter=0;
        while(temp!=NULL)
        {

            if(temp->get_Rate()==x)
            {
                cout<<temp->get_Id()<<"  "<<temp->get_Rate()<<"  "<<temp->get_vote()<<endl;
                counter++;
            }
            temp=temp->get_next();
        }
        if(counter==0)
            cout<<" Result Not Found"<<endl;
        if(counter>1)
            cout<<"\n\t"<< counter <<" movies have "<< x<< " rating "<<endl;

    }

    //function to search movie By ID in particular Linked List
    void Find_Id(string x)
    {
        node *temp=first;
        int counter=0;
        while(temp!=NULL)
        {

            if(temp->get_Id()==x)
            {
                cout<<"\nMovie Id              Rating              Votes         "<<endl;
                cout<<temp->get_Id()<<"                 "<<temp->get_Rate()<<"                   "<<temp->get_vote()<<endl;
                counter++;
            }
            temp=temp->get_next();
        }
        if(counter==0)
            cout<<"\n\tResult Not Found"<<endl;
    }
};

class Search
{
private:
    list List[100];                //array of objects
    string movie_id;
    double rating;
    int votes;
    string popular_move;                 //to store most popular movie
    string least_move;                  //to store least popular movie
    double highest_rating=0;           //to store highest rating
    double low_rating=20;             //to store lowest rating
    int high_vote=0;                 //to store number of votes of most popular movie
    int low_vote=10000000;                    //to store number of votes of least popular movi
    int counter1=0;
    int counter2=0;
public:
    Search()                          //constructor
    {
        string temp;
        int counter=0;
        ifstream fin;
        fin.open("data.txt");                           //open the file in which Data is stored
        if(!fin)
            cout<<"File does not esist"<<endl;          //if file does not exist
        else
        {
            while(fin>>movie_id>>rating>>votes)
            {
                if(votes>1000000)
                    counter1++;
                if(votes<=1000)
                    counter2++;
                insert(movie_id,rating,votes);

                counter++;
            }
            fin.close();                                   //close text file

        }

    }

    //Hash function
    int hashh(double x)                                //Hash elements by average Rating
    {
        double temp=10.0;
        double z =x*temp;

        int y=z;
        return y%100;
    }

    //insertion function
    void insert(string id,double x,int vote)          //insert element in hash table
    {
        int i=hashh(x);
        //most popular movie
        if(x>highest_rating && vote>high_vote)
        {
            highest_rating=x;
            high_vote=vote;
            popular_move=id;
        }

        //least popular movie
        if(x<low_rating&& vote<low_vote)
        {
            low_rating=x;
            low_vote=vote;
            least_move=id;
        }

        List[i].add_atstart(id,x,vote);                //add in linked list
    }

    //searching function by rating
    void Search_Data(double x)                       //search Data from Hash Table
    {
        string str;
        int i=hashh(x);
        List[i].Find_Rate(x);
        cout<<"if you want to search any particular movie of That rating Enter ID enter q for quit:";
        cin>>str;
        if(str!="q")
            List[i].Find_Id(str);
    }
    void SDataR(double x)                       //search Data from Hash Table
    {
        int i=hashh(x);
        List[i].Find_Rate(x);
    }

    //searching function for movie id  string str
    void Search_Id(string str)
    {
        ifstream fin;
        fin.open("data.txt");                           //open the file in which Data is stored
        if(!fin)
            cout<<"File does not exist"<<endl;          //if file does not exist
        else
        {
            while(fin>>movie_id>>rating>>votes)
            {
                if(str==movie_id)
                {
                    cout<<"\nMovie ID              Rating              Votes"<<endl;
                    cout<<movie_id<<"            "<<rating<<"                 "<<votes<<endl;
                    return;
                }
            }
            cout<<"This Movie id does not exist"<<endl;
            fin.close();                                   //close text file

        }
    }

    void highest_vote()
    {
        cout<<"\n\t"<<counter1<< "  movies have votes greater than 1 million(1000000)"<<endl;
    }
    void lowest_vote()
    {
        cout<<"\n\t"<<counter2<<"  movies have votes less than 1 thousand(1000)"<<endl;
    }
    //function to find most popular movie
    void popular_movie()
    {

        cout<<"\n\tPopular Movie according to rating "<<endl;
        cout<<"Movie_ID         Rating           Votes"<<endl;
        cout<<popular_move<<"         " <<highest_rating<<"             "<<high_vote<<endl;
    }

    //function to find least popular movie
    void least_movie()
    {
        cout<<"\n\tLeast Popular  Movie according to rating "<<endl;
        cout<<"Movie_ID         Rating           Votes"<<endl;
        cout<<least_move<<"           "<<low_rating<<"                  "<<low_vote<<endl;
    }

};

int main()
{
    Search o;
    cout<<"\t\t\t\t Hello Guys! "<<endl;
    cout<<"\t\t We are introducing mini search engine to search movies"<<endl;
    cout<<"\t\t You can get information about least popular movie"<<endl;
    cout<<"\t\t You can get information about most popular movie"<<endl;
    cout<<"\t\t In this you can search movie by movie Id "<<endl;
    cout<<"\t\t In this you can search movie by rating "<<endl<<endl;
    char choice,quit;
    double rate;
    string str;
    string str1;
    while(choice!='X'|| choice!='x')
    {
        cout<<"\t*------------------------------------------------------*"<<endl;
        cout<<"\t|Enter H for finding how many movies have highest votes|"<<endl;
        cout<<"\t|Enter V for finding how many movies have lowest votes |"<<endl;
        cout<<"\t|Enter S for searching movies of particular rating     |"<<endl;
        cout<<"\t|Enter L for finding least popular movie               |"<<endl;
        cout<<"\t|Enter P for finding most popular movie                |"<<endl;
        cout<<"\t|Enter I for  search  movie  by  Id                    |"<<endl;
        cout<<"\t|Enter X for exiting from searching                    |"<<endl;
        cout<<"\t|Enter your choice                                     |"<<endl;
        cout<<"\t*------------------------------------------------------*"<<endl;
        cin>>choice;
        if(choice=='R'|| choice=='r')
        {
            quit='z';
            double x=0,y=0;
            while(quit!='q')
            {
                cout<<"\n\tEnter that Rating from which  you want to start :";
                cin>>x;
                cout<<"\n\tEnter that Rating from which  you want to end :";
                cin>>y;
                double a=10*x;
                double b=10*y;
                cout<<" b-"<<b<<endl;
                while(b>=a)
                    {
                         o.SDataR(x);
                          x=x+0.1;
                          a++;}

                cout<<" \n\tIF you want to check more Rating enter any key or for quit Enter q :";
                cin>>quit;
            }
        }
        else if(choice=='S'|| choice=='s')
        {
            quit='z';
            while(quit!='q')
            {
                cout<<"\n\tEnter Rating That you want to search :";
                cin>>rate;
                o.Search_Data(rate);
                cout<<" \n\tIF you want to check more Rating enter any key or for quit Enter q :";
                cin>>quit;
            }
        }
        else if(choice=='i'|| choice=='I')
        {
            quit='z';
            while(quit!='q')
            {
                cout<<"Enter movie Id that you want to search :";
                cin>>str1;
                o.Search_Id(str1);
                cout<<"\n\tIf you want to check more Enter any key other wise enter q :";
                cin>>quit;
            }
        }
        else if(choice=='P'||choice=='p')
        {
            o.popular_movie();
        }
        else if(choice=='L'|| choice=='l')
        {
            o.least_movie();
        }
        else if(choice=='H'|| choice=='h')
            o.highest_vote();
        else if(choice=='V'|| choice=='v')
            o.lowest_vote();
        else if(choice=='x'|| choice=='X')
            break;
    }

    return 0;
}
