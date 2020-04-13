//
//  main.cpp
//  ringnode
//
//  Created by raisemmina on 2020/4/7.
//  Copyright © 2020 raisemmina. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
class RingNode
{
    public:
    char value;
    RingNode *next; //pointer to the next
};

void print_the_ring(RingNode *head,int size);
int read_recursively (ifstream& fin, RingNode*& current);
void delete_recursively (RingNode*& current);

void print_the_ring(RingNode *head,int size)
{
    for (int i=0; i<size; i++)
    {
        cout << head->value << endl;
        head = head->next;
    }
}
int read_recursively (ifstream& fin, RingNode*& current)
{
    //EOF
    if(fin.eof()) return 0;
    char ch;
    //temp is used to record first node's position
    RingNode *temp=current;
    fin.get(ch);
    //cout << ch << endl;
    if(ch=='\n') 
        return 0;
    current= new RingNode;
    current->value=ch;
    if(temp==NULL){
        current -> next = current;
        // cout 
        // << "current address is : " << current << endl
        // << "current value is : " << current->value << endl;
    }
    else{
        current -> next = temp;
        // cout 
        // << "current address is : " << current << endl
        // << "current value is : " << current->value << endl;
    }
    cout << "temp is : " << temp << endl;
    //link nodes by passing current->next;
    return 1+read_recursively(fin, current->next);
}
void delete_recursively (RingNode*& current)
{
    if (current == NULL) return;
    if (current != current->next)
    { // not a single node yet
        RingNode* tmp = current->next;
        current->next = tmp->next;
        delete tmp;
        delete_recursively (current);
    }
    else{ // a single node left
        delete current;
        current = NULL;
    }
}

int main(int argc, const char * argv[])
{
    ifstream fin("input.txt");
    RingNode* start_point = NULL;
    cout << "address of start_point is : " << &start_point << endl;
    int total = read_recursively(fin, start_point);
    print_the_ring(start_point,total);
    delete_recursively (start_point);
}
