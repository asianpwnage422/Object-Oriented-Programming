#include <iostream>
#include <string.h> 

using namespace std;

typedef struct _char_count{
    char c;
    int count;
    struct _char_count *next;
}char_count;
char_count *first = NULL;

int main(int argc, char** argv)
{
    int i,j,checker = 0;
    char_count *cur = NULL,*temp = NULL,*prev = NULL;
    char added_str[100000];
    added_str[0] = '\0';

    //add argv's to a single string
    for(i = 1; i < argc; i++)
        strcat(added_str,argv[i]);
    
    //start scanning letters and calculating
    for(i = 0; i < strlen(added_str); i++){
        //first case
        if(first == NULL){
            first = new(char_count);
            first->next = NULL;
            first->c = added_str[i];
            first->count = 1;
        }
        //start checking, if letter is not in chain, add new block
        else{
            while(cur!=NULL){
                if(added_str[i] == cur->c){
                    cur->count++;
                    checker = 1;
                }
                prev = cur;
                cur = cur->next;
            }
            //procedure for adding new block(cur == NULL)
            if(checker == 0){
                cur = prev;
                cur->next = new(char_count);
                cur = cur->next;
                cur->c = added_str[i];
                cur->count = 1;
                cur->next = NULL;
            }
        }
        //reset checker, cur
        checker = 0;
        cur = first;
    }

    while(cur != NULL){
        if(cur!=first)
            cout<<",";

        cout << cur->c << "-" << cur->count;
        cur = cur->next;
    }
    return 0;
}