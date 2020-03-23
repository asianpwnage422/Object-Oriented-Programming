#include <iostream>
#include <cstring>
using namespace std;

#define Max_LenGth 1000

typedef struct char_count char_count;
struct char_count
{
    char letter;
    int num;
    char_count *next;
    char_count *prev;
};

int appear_check(char c, char_count *current)
{
    if (current->letter != c)
    {
        if (current->prev == NULL)
            return 0;
        else
            return appear_check(c, current->prev);
    }
    else
    {
        current->num++;
        return 1;
    }
}

int main(int argc, char **argv)
{
    char_count *First, *cur, *prev;

    First = new char_count();
    First->prev = NULL;
    cur = First;

    // argv data preprocessing
    // merge all data into single data
    char data[Max_LenGth];
    data[0] = '\0';

    for (int i = 1; i < argc; i++)
        strcat(data, argv[i]);

    int len = strlen(data);
    for (int i = 0; i < len; i++)
    {
        if (appear_check(data[i], cur) == 1)
            continue;
        else
        {
            cur->letter = data[i];
            cur->num++;
            cur->next = new char_count();
            prev = cur;
            cur = cur->next;
            cur->letter = '#';
            cur->prev = prev;
        }
    }

    // output
    cur = First;
    while (cur->letter != '#')
    {
        cout << cur->letter << "-" << cur->num << endl;
        cur = cur->next;
    }

    return 0;
}
