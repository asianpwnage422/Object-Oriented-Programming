//
//  bigint.cpp
//  bigint
//
//  Created by raisemmina on 2020/5/12.
//  Copyright © 2020 raisemmina. All rights reserved.
//

#include "bigint.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <math.h>

long int pow10(long int x)
{
    long int sum=10;
    if(x==0)return 1;
    for(long int i=0;i<(x-1);i++)
    {
        sum=sum*10;
    }
    return sum;
}

long int count_x(long int x)
{
    int c=1;
    x=x/10;
    while(x!=0)
    {
        x/=10;
        c++;
    }
    return c;
}
void bigint::initialize()
{
    memset(num, 0, sizeof(num));
    memset(len, 0, sizeof(len));
}
bigint::bigint()
{
    size=1;
    initialize();
}
bigint::bigint(long int x0)
{
    size=1;
    initialize();
    len[0]=count_x(x0);
    num[0]=x0;
}
bigint::bigint(long int x0, long int x1)
{
    size=2;
    initialize();
    len[0]=count_x(x0);
    len[1]=count_x(x1);
    num[0]=x0;
    num[1]=x1;
}
bigint::bigint(long int x0, long int x1, long int x2)
{
    size=3;
    initialize();
    len[0]=count_x(x0);
    len[1]=count_x(x1);
    len[2]=count_x(x2);
    num[0]=x0;
    num[1]=x1;
    num[2]=x2;
}
bigint::bigint(long int x0, long int x1, long int x2, long int x3)
{
    size=4;
    initialize();
    len[0]=count_x(x0);
    len[1]=count_x(x1);
    len[2]=count_x(x2);
    len[3]=count_x(x3);
    num[0]=x0;
    num[1]=x1;
    num[2]=x2;
    num[3]=x3;
}
bigint::bigint(long int x0, long int x1, long int x2, long int x3, long int x4)
{
    size=5;
    initialize();
    len[0]=count_x(x0);
    len[1]=count_x(x1);
    len[2]=count_x(x2);
    len[3]=count_x(x3);
    len[4]=count_x(x4);
    num[0]=x0;
    num[1]=x1;
    num[2]=x2;
    num[3]=x3;
    num[4]=x4;
}
bool operator > (const bigint& tl, const bigint& tr)
{
    if(tl.size>tr.size) return true;
    else if(tl.size<tr.size) return false;
    else{
        for(int i=tl.size-1;i>=0;i--)
        {
            if(tl.num[i]>tr.num[i]) return true;
            else if(tl.num[i] < tr.num[i]) return false;
            //else continue;
        }
    return false;
    }
}
bool operator < (const bigint& tl, const bigint& tr)
{
    if(tl.size<tr.size) return true;
    else if(tl.size>tr.size) return false;
    else{
        for(int i=tl.size-1;i>=0;i--)
        {
            if(tl.num[i]<tr.num[i]) return true;
            else if(tl.num[i] > tr.num[i]) return false;
            //else continue;
        }
        return false;
    }
}
bool operator == (const bigint& tl, const bigint& tr)
{
    for(int i=0;i<tl.size;i++)
    {
        if(tl.num[i]!=tr.num[i]) return false;
    }
    return true;
}
bool operator <= (const bigint& tl, const bigint& tr)
{
    if(tl > tr) return false;
    return true;
}
bool operator >= (const bigint& tl, const bigint& tr)
{
    if(tl < tr) return false;
    return true;
}
bool operator != (const bigint& tl, const bigint& tr)
{
    if(tl == tr) return false;
    return true;
}
bigint operator + (const bigint& tl, const bigint& tr)
{
    if(tr > tl) return (tr + tl);
    bigint c;
    c.size=tl.size;
    for(int i=0;i<c.size;i++)
    {
        c.num[i]=c.num[i]+tl.num[i]+tr.num[i];
        while( count_x(c.num[i]) >9&& i<tl.size)
        {
            c.num[i+1]+=(c.num[i]/pow10(9));
            c.num[i]=c.num[i]%pow10(9);
        }
    }
    if(c.num[c.size] != 0 )
    {
        c.size++;
    }
    for(int i=0; i<c.size; i++)
    {
        c.len[i]=count_x(c.num[i]);
    }
    return c;
}
bigint operator + (const bigint& t, const int n )
{

    bigint c;
    c.size=t.size;
    int i=0;
    c.num[i]=c.num[i]+t.num[i]+n;
    for( i=0;i<c.size;)
    {
        while( count_x(c.num[i]) >9&& i<t.size)
        {
            c.num[i+1]+=c.num[i]/pow10(9);
            c.num[i]=c.num[i]%pow10(9);
        }
        i++;
        c.num[i]=c.num[i]+t.num[i];
    }
    for(int i=0; i<c.size; i++)
    {
        c.len[i]=count_x(c.num[i]);
    }
    
    return c;
}
bigint operator - (const bigint& tl, const bigint& tr)
{
    if(tl<tr) return 0;
    bigint c;
    c.size=tl.size;
    for(int i=0; i<c.size; i++)
    {
        if((c.num[i]+tl.num[i])>=tr.num[i])
        {
            c.num[i] += (tl.num[i] - tr.num[i]);
        }
        else
        {
            c.num[i+1]-=1;
            c.num[i]+= 1000000000+(tl.num[i] - tr.num[i]);
        }
    }
    if(c.num[0]<0)
    {
        c.size = 1;
        memset(c.num, 0, sizeof(c.num));
        memset(c.len, 0, sizeof(c.len));
        c.len[0]=1;
    }
    
    for(int i=tl.size-1; i>=0; i--, c.size--)
    {
        if(c.num[i]!=0)
            break;
    }
    if(c.size == 0)
    {
        c.size = 1;
        memset(c.num, 0, sizeof(c.num));
        memset(c.len, 0, sizeof(c.len));
        c.len[0]=1;
    }
    for(int i=0; i<c.size; i++)
    {
        c.len[i]=count_x(c.num[i]);
    }
    return c;
}
bigint operator - (const bigint& t, const int n)
{
    bigint c;
    c.size=t.size;
    long int mm =t.num[0]-n;
    c.num[0]=mm;
    for(int i=0; i<c.size; i++)
    {
        if(c.num[i]>=0)
        {
            c.num[i] =t.num[i];
        }
        else
        {
            c.num[i+1]-=1;
            c.num[i]+= 1000000000;
        }
    }
    
    if(c.num[0]<0)
    {
        c.size = 1;
        memset(c.num, 0, sizeof(c.num));
        memset(c.len, 0, sizeof(c.len));
        c.len[0]=1;
    }
    
    for(int i=t.size-1; i>=0; i--, c.size--)
    {
        if(c.num[i]!=0)
            break;
    }
    if(c.size == 0)
    {
        c.size = 1;
        memset(c.num, 0, sizeof(c.num));
        memset(c.len, 0, sizeof(c.len));
        c.len[0]=1;
    }
    for(int i=0; i<c.size; i++)
    {
        c.len[i]=count_x(c.num[i]);
    }
    return c;
}

ostream& operator<<(ostream &os, const bigint& t)
{
    for(int i=t.size-1;i>=0;i--)
    {
        if(t.num[i]==0 && i!=t.size && t.size>1)os<<"00000000";
        else if(t.num[i]!=0 && t.len[i]<9 && i!=t.size-1 && t.size>1)
        {
            for(int j=0;j<9-t.len[i];j++) os<<"0";
        }
        os<< t.num[i];
    }
    return os;
}

istream& operator>>(istream &is,  bigint& t)
{
    string str;
    is>>str;
    int r=str.length()%9;
    int q;
    if(r!=0)q=str.length()/9+1;
    else q=str.length()/9;
    int size=q,j=0;
    long int tmp[5];
    memset(tmp,0,sizeof(tmp));
    int count=1;
    
    while(size>0 && j<str.length())
    {
        if(r!=0)
        {
            while(size==q && r!=0)
            {
                tmp[size-1]=tmp[size-1]*10+(str[j]-'0');
                r--;
                j++;
                count++;
            }
            size--;
            count=0;
        }
        else if(r==0)
        {
            tmp[size-1]=tmp[size-1]*10+(str[j]-'0');
            j++;
            count++;
        }
        if(count==10)
        {

            count=1;
            size--;
        }
 
    }
    for(int i=0;i<q ;i++)
    {
        t.num[i]=tmp[i];
        t.len[i]=count_x(t.num[i]);
    }
   t.size=q;

    return is;
}
