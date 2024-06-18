#include <iostream>
using namespace std;
int tsp_g[10][10] = {
   {12, 30, 33, 10, 45},
   {56, 22, 9, 15, 18},
   {29, 13, 8, 5, 12},
   {33, 28, 16, 10, 3},
   {1, 4, 30, 24, 20}
};
//An array that keeps track of all the visited vertices
int visited[10];
int n;
int cost = 0;


// This function recursively finds the shortest path starting from vertex c.
void travellingsalesman(int c){
   int k, adj_vertex = 999;
   int min = 999; //initializes the maximum min value, which will be reset obviously when other nodes are checked
   
   //Marks the current vertex as marked
   visited[c] = 1;
   
   // This will display the shortest path
   cout<<c + 1<<" ";
   
   // Here we are checking the minimum cost-edge in the graph
   for(k = 0; k < n; k++) {
      if((tsp_g[c][k] != 0) && (visited[k] == 0)) {
         if(tsp_g[c][k] < min) {
            min = tsp_g[c][k];
               adj_vertex = k;
         }
      }
   }
   if(min != 999) { 
      cost = cost + min;
   }
   if(adj_vertex == 999) {
      adj_vertex = 0;
      cout<<adj_vertex + 1;
      cost = cost + tsp_g[c][adj_vertex];
      return;
   }
   travellingsalesman(adj_vertex);
}

/* main function */
int main(){
   int i, j;
   n = 5;
   for(i = 0; i < n; i++) {
      visited[i] = 0;
   }
   cout<<"Shortest Path: ";
   travellingsalesman(0);
   cout<<"\nMinimum Cost: ";
   cout<<cost;
   return 0;
}