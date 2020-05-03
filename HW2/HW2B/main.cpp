//
//  main.cpp
//  ringnode
//
//  Created by raisemmina on 2020/4/7.
//  Copyright © 2020 raisemmina. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MAXN = 50;

int minCutCost(int dp[][MAXN+5], int c[], int l, int u){
  if( dp[l][u] != -1 ) return dp[l][u];
  if( l == u-1 ) return dp[l][u] = 0;
  dp[l][u] = INT_MAX;
  for( int i = l + 1 ; i < u ; ++i ){
    dp[l][u] = min( dp[l][u], minCutCost(dp, c, l, i) + 
                              minCutCost(dp, c, i, u) + ( c[u] - c[l] ));
  }
  cout << " l is " << l << " u is " << u << endl;
  return dp[l][u];

}

int main(){
  int l;
  while( scanf("%d", &l) != EOF && l != 0 ){
    int n;
    scanf("%d", &n);

    int c[MAXN+5] = {0};
    c[0] = 0; 
    for( int i = 1 ; i <= n ; ++i ){
      scanf("%d", &c[i]);
    }
    c[n+1] = l;

    int dp[MAXN+5][MAXN+5];
    for( int i = 0 ; i <= n+1 ; ++i ){
      for( int j = 0 ; j <= n+1 ; ++j ){
        dp[i][j] = -1;
      }
    }

    printf( "The minimum cutting is %d.\n", minCutCost(dp, c, 0, n+1) ); 

  }

  return 0;
}