#include <stdio.h>

void parse_line(char line[]) {

   char zip[6];     // leave room for the null character
   char state[3];   
   char *city; 
   double lat, lng;  // latitude and longitude

   // extract the zip code
   int i = 0;
   while (line[i] != ',') {
       zip[i] = line[i];
       i++;
   }

   zip[5] = '\0';
   printf("zip code: %s\n", zip);   // DEBUG

   i++; // move past the comma

   int j = 0;

   // extract the state
   while (line[i] != ',') {
       state[j] = line[i];
       i++;
       j++;
   }

   state[2] = '\0';
   i++;  // move past comma
 
   printf("state: %s\n", state);

   // city 
   // load the city into the city variable 
   // count between commas to see how much memory
   // to allocate
   city = malloc(??????);
   j = 0;
   while (line[i] != ',') {
       
   }  
   

}

int main() {

   parse_line("35004,AL,ACMAR,86.51557,33.584132");


}