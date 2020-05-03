#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
class RingNode
{
public:
    char value;
    RingNode *next; //pointer to the next
};

void print_the_ring(RingNode *head, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << head->value << endl;
        head = head->next;
    }
}
int read_recursively(ifstream &fin, RingNode *&current)
{
    if (fin.eof())
        return 0;
    else
    {
        char letter;
        letter = fin.get();
        if (letter == '\n')
            return 0;
        RingNode *first = current;
        current = new RingNode;
        current->value = letter;
        //first case
        if (first == NULL)
            current->next = current;
        //other cases
        else
            current->next = first;
        return 1 + read_recursively(fin, current->next);
    }
}
void delete_recursively(RingNode *&current)
{
    //case 1 : No nodes
    if (current == NULL)
        return;
    //case 2 : last node
    if (current == current->next)
    {
        free(current);
    }
    //case 3 : still has nodes
    else
    {
        RingNode *temp = current->next;
        current->next = temp->next;
        free(temp);
        delete_recursively(current);
    }
}

int main(int argc, const char *argv[])
{
    int node_num = 0;
    ifstream fin("input.txt");
    RingNode *start_point = NULL;
    node_num = read_recursively(fin, start_point);
    print_the_ring(start_point, node_num);
    delete_recursively(start_point);
}


