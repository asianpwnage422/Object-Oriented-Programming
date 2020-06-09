#include "bigint.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

long get_length(long x)
{
    int counter = 0;
    while(x/10 != 0){
        ++counter;
        x /= 10;
    }
    ++counter;
    return counter;
}
void bigint::initialize()
{
    for(int i = 0; i < 5; i++){
        v[i] = 0;
        length_v[i] = 0;
    }
}
bigint::bigint()
{
    size=1;
    initialize();
}
bigint::bigint(long x0)
{
    size=1;
    initialize();
    v[0] = x0;
}
bigint::bigint(long x0, long x1)
{
    size=2;
    initialize();
    v[0] = x0;
    v[1] = x1;
    length_v[0] = get_length(x0);
    length_v[1] = get_length(x1);  
}
bigint::bigint(long x0, long x1, long x2)
{
    size=3;
    initialize();
    v[0] = x0;
    v[1] = x1;
    v[2] = x2;
    length_v[0] = get_length(x0);
    length_v[1] = get_length(x1);  
    length_v[2] = get_length(x2);
}
bigint::bigint(long x0, long x1, long x2, long x3)
{
    size=4;
    initialize();
    v[0] = x0;
    v[1] = x1;
    v[2] = x2;
    v[3] = x3;
    length_v[0] = get_length(x0);
    length_v[1] = get_length(x1);  
    length_v[2] = get_length(x2);
    length_v[3] = get_length(x3);
}
bigint::bigint(long x0, long x1, long x2, long x3, long x4)
{
    size=5;
    initialize();
    v[0]=x0;
    v[1]=x1;
    v[2]=x2;
    v[3]=x3;
    v[4]=x4;
    length_v[0] = get_length(x0);
    length_v[1] = get_length(x1);  
    length_v[2] = get_length(x2);
    length_v[3] = get_length(x3);
    length_v[4] = get_length(x4);
}

ostream& operator<<(ostream &output, const bigint& number)
{
    for(int i=number.size-1;i>=0;i--)
    {
        int zero_num = 9;
        if(i == number.size - 1)
            output << number.v[i];
        else{
            zero_num = 9 - number.length_v[i];
            for(int j = 0; j < zero_num; j++)
                output << 0;
            output << number.v[i];
        }
    }
    //output << endl;
    return output;
}
istream& operator>>(istream &input,  bigint& number)
{
    string str;
    input >> str;
    // cout << "string is " << str << endl;
    int len = str.length();
    //cout << "length is " << len << endl;
    int exp = len/9;
    int remainder = len%9;
    if(remainder == 0 )
        number.size = exp;
    else
        number.size = exp+1;
    //get remainder
    int index = number.size-1;
    if(remainder != 0){
            string str_r = str.substr(0,remainder);
            number.v[index] = atoi(str_r.c_str());
            number.length_v[index] = remainder;
            //cout << "remainder is " << number.v[index] << " and length_v[] is " << number.length_v[index] << endl;
            index--;
    }
    int counter = remainder;
    // cout << str[remainder];
    for(int i = 0; i < exp; i++){
        string sub = str.substr(counter, 9);
        counter += 9;
        int j;
        for(j = 0; j < 9; j++){
            if(sub[j] != '0')
                break;
        }
        string v_sub = sub.substr(j,9-j);
        number.v[index] = atoi(v_sub.c_str());
        number.length_v[index] = 9-j;
        //cout << index << " v[] is " << number.v[index] << " and length_v[] is " << number.length_v[index] << endl; 
        index--;
    }
    return input;
}

bool operator > (const bigint& first, const bigint& second)
{
    //compare size first
    if(first.size > second.size)
        return true;
    else if(first.size < second.size)
        return false;
    //compare v[i]
    else{
        for(int i = first.size-1; i >= 0; i--)
        {
            if(first.v[i] > second.v[i])
                return true;
            else if(first.v[i] < second.v[i])
                return false;
        }
    return false;
    }
}
bool operator < (const bigint& first, const bigint& second)
{
    if(first.size < second.size) 
        return true;
    else if(first.size > second.size) 
        return false;
    else{
        for(int i = first.size-1; i >= 0; i--)
        {
            if(first.v[i] < second.v[i]) 
                return true;
            else if(first.v[i] > second.v[i])
                return false;
        }
        return false;
    }
}
bool operator == (const bigint& first, const bigint& second)
{
    for(int i = first.size-1; i >= 0; i--)
    {
        if(first.v[i] != second.v[i])
            return false;
    }
    return true;
}
bool operator <= (const bigint& first, const bigint& second)
{
    if(first > second)
        return false;
    else
        return true;
}
bool operator >= (const bigint& first, const bigint& second)
{
    if(first < second)
        return false;
    else
        return true;
}
bool operator != (const bigint& first, const bigint& second)
{
    if(first == second)
        return false;
    else
        return true;
}

long pow10(long x)
{
    long sum=10;
    if(x==0)return 1;
    for(long i=0;i<(x-1);i++)
    {
        sum=sum*10;
    }
    return sum;
}
bigint operator + (const bigint& first, const bigint& second)
{
    return first + second;
}
bigint operator + (const bigint& number, const int n )
{
    return number+n;
}
bigint operator - (const bigint& first, const bigint& second)
{
    if(first < second) 
        return 0;
    return second - first;
   
}
bigint operator - (const bigint& number, const int n)
{
    if(n > number)
        return 0;
    return number - n;
}
