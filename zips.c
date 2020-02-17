#include <stdio.h>
#include <stdlib.h>   // malloc

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

   int city_len = 0;
   j = i;

   // count the characters between the commas
   while (line[j] != ',') {
       city_len++;
       j++;
   }

   // city 
   // load the city into the city variable 
   // count between commas to see how much memory
   // to allocate
   city = malloc(city_len + 1);  // new in Java
   j = 0;

   char *tmp_city = city;

   // fill in the city from the line
   while (line[i] != ',') {
       *tmp_city = line[i];
       tmp_city++;
       i++;
   }  
   
   *tmp_city = '\0';
   printf("%s\n", city);

   // longitude
   char tmp_lng[10];
   j = 0;
   i++;

   while (line[i] != ',') {
       tmp_lng[j] = line[i];
       j++;
       i++;
   }
   tmp_lng[j] = '\0';  
   i++; // jump over comma

   // convert the string into a double
   lng = atof(tmp_lng);   
      
   printf("%f\n", lng);    // DEBUG

   char tmp_lat[10];
   j = 0;

   while (line[i] != '\n') {
       tmp_lat[j] = line[i];
       j++;
       i++;
   }
   
   tmp_lat[j] = '\0';
   lat = atof(tmp_lat);   // convert latitude to a double

   printf("%f\n", lat);

}

int main() {

   const int MAX_LINE_LEN = 1024;
   char buff[MAX_LINE_LEN];

   while (fgets(buff, MAX_LINE_LEN, stdin) != NULL) {
       parse_line(buff);
   }


   // parse_line("35004,AL,ACMAR,86.51557,33.584132\n");


}