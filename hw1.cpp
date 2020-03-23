#include <iostream>
#include <string>

using namespace std;

typedef struct _char_count{
    char c;
    int count;
    struct _char_count *next;
}char_count;
char_count *first = NULL;
//this is used for adding a new letter or counting
void add_into_list(char letter,char_count *first){
    char_count *p,*prev,*t;
    p = first;
    if(first == NULL){
        t = (char_count*) malloc(sizeof(char_count));
        t->c = letter;
        t->count = 1;
        t->next = NULL;
        first = t;
        return;
    }
    //traverses through the list til it finds itself 
    while(p != NULL){
        if(letter == p->c){
            p->count++;
            return;
        }
        prev = p;
        p = p->next;
    }
    //reaches end of list(p = NULL)
    t = (char_count*) malloc(sizeof(char_count));
    t->c = letter;
    t->count = 1;
    prev->next = t;
    t->next = NULL;
    
}
int main(int argc, char** argv)
{
    int i,j;
    for(i = 0; i < argc; i++){
        string str(argv[i]);
        for(j = 0; j < str.length(); j++){
            add_into_list(argv[i][j], first);
        }
    }
    while(first != NULL){
        cout << first->c << first->count << endl;
        first = first->next;
    }
    return 0;
}