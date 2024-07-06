#include<iostream>
using namespace std;

#define MAX 9999

int n = 4; // Number of cities
int distan[20][20] = { // Distance matrix between cities
   {0, 22, 26, 30},
   {30, 0, 45, 35},
   {25, 45, 0, 60},
   {30, 35, 40, 0}
};

int completed_visit = (1 << n) - 1; // All bits set to 1 (binary representation of visiting all cities)
int DP[32][8]; // DP table, where DP[subset][current] represents minimum cost

// Function to solve TSP using DP
int TSP(int mask, int position) {
   // If all cities have been visited, return the cost to return to the starting city
   if (mask == completed_visit) {
      return distan[position][0];
   }
   
   // If already computed, return the stored value
   if (DP[mask][position] != -1) {
      return DP[mask][position];
   }
   
   int answer = MAX;
   
   // Try visiting all cities from the current city
   for (int city = 0; city < n; city++) {
      // If city 'city' is not visited yet
      if ((mask & (1 << city)) == 0) {
         // Calculate the cost of visiting 'city' from 'position' and recurse
         int newAnswer = distan[position][city] + TSP(mask | (1 << city), city);
         // Update the minimum cost
         answer = min(answer, newAnswer);
      }
   }
   
   // Store the computed answer in DP table
   return DP[mask][position] = answer;
}

int main() {
   // Initialize DP table with -1 (unvisited state)
   for (int i = 0; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) {
         DP[i][j] = -1;
      }
   }
   
   // Start TSP from city 0 (0th bit set in mask)
   cout << "Minimum Distance Travelled -> " << TSP(1, 0); // 1 means city 0 is visited
   
   return 0;
}
