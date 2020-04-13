#include <iostream>
#include <string>

using namespace std;

typedef struct _char_count
{
    char c;
    int count;
    struct _char_count *next;
} char_count;
//this is used for adding a new letter or counting
void add_into_list(char letter, char_count *first)
{
    char_count *p, *prev, *t;
    p = first;
    if (first == NULL)
    {
        t = (char_count *)malloc(sizeof(char_count));
        t->c = letter;
        t->count = 1;
        t->next = NULL;
        first = t;
        return;
    }
    //traverses through the list til it finds itself
    while (p != NULL)
    {
        if (letter == p->c)
        {
            p->count++;
            return;
        }
        prev = p;
        p = p->next;
    }
    //reaches end of list(p = NULL)
    t = (char_count *)malloc(sizeof(char_count));
    t->c = letter;
    t->count = 1;
    prev->next = t;
    t->next = NULL;
}
int main(int argc, char **argv)
{
    int i, j, len;
    char_count *first, *prev, *current, *t;
    first = new char_count();
    first = NULL;
    char letter;
    for (i = 1; i < argc; i++)
    {
        string str(argv[i]);
        //cout << str.length() << endl;
        for (j = 0; j < str.length(); j++){
            letter = argv[i][j];
            if(first == NULL){
                first = new char_count();
                first->count = 1;
                first->c = letter;
                first->next = NULL;
            }
            else{
                current = first;
                while(current != NULL ){
                    if(current->c == letter){
                        current->count++;
                        continue;
                    }
                    else{
                        prev = current;
                        current = current->next;
                    }
                }
                //case where we need to insert new letter
                t = new char_count();
                t->c = letter;
                t->next = NULL;
                prev->next = t;
            }
        }
    }
    current = first;
    while (current->c != '#')
    {
        cout << current->c << "-" << current->count << endl;
        current = current->next;
    }
    return 0;
}