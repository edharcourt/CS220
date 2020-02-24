#include <stdio.h>
#include <stdlib.h>   // malloc
#include <string.h>

// struct (a structure)
typedef struct {
    char zip[6];    // 6 bytes
    char state[3];  // 3 bytes
    char *city;     // pointer is 4 bytes
    double lng;     // 8 bytes
    double lat;     // 8 bytes
} zipinfo;


/*
 * parse_line extracts zip code info from a line and
 * returns a pointer to a zipinfo struct
 */
zipinfo *parse_line(char line[]) {

   char zip[6];      // leave room for the null character
   char state[3];    // two character state code 
   char *city;        
   double lat, lng;  // latitude and longitude

   // i will be the current location in the line
   int i = 0;

   // extract the zip code and make sure to null terminate
   while (line[i] != ',') {
       zip[i] = line[i];
       i++;
   }

   zip[5] = '\0';

   // printf("zip code: %s\n", zip);   // DEBUG

   i++; // move past the comma

   int j = 0; // current location in state

   // extract the state and null terminate
   while (line[i] != ',') {
       state[j] = line[i];
       i++;
       j++;
   }

   state[2] = '\0';

   i++;  // move past comma
 
   // printf("state: %s\n", state);

   // need to compute the city length
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

   // printf("%s\n", city);   // DEBUG

   // extract the longitude
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
      
   // printf("%f\n", lng);    // DEBUG

   // extract the latitude
   char tmp_lat[10];
   j = 0;

   while (line[i] != '\n') {
       tmp_lat[j] = line[i];
       j++;
       i++;
   }
   
   tmp_lat[j] = '\0';
   lat = atof(tmp_lat);   // convert latitude to a double

   // printf("%f\n", lat);

   // create a zipinfo struct and fill it with the 
   // data we just parsed
   zipinfo *info = malloc(sizeof(zipinfo));

   // copy the zipcode into the struct
   strcpy(info->zip, zip);
   strcpy(info->state, state);
   info->city = city;
   info->lat = lat;
   info->lng = lng;
   
   return info;
}

/*
 *  dump a zipinfo struct to the console
 */
void print_zipinfo(zipinfo *info) {
    printf("zip code: %s\n", info->zip);
    printf("state: %s\n", info->state);
    printf("city: %s\n", info->city);
    printf("latitude: %.2f\n", info->lat);
    printf("longitude: %.2f\n", info->lng);
}

/*
 * main program
 */
int main() {

   const int MAX_LINE_LEN = 1024;
   char buff[MAX_LINE_LEN];

   // declare an array of pointers to zipinfo structs
   zipinfo *ziparray[29470];  // zipcodes in file
   int i = 0;

   while (fgets(buff, MAX_LINE_LEN, stdin) != NULL) {
       ziparray[i] = parse_line(buff);
       i++;
   }

   print_zipinfo(ziparray[--i]);

   //zipinfo *info = parse_line("35004,AL,ACMAR,86.51557,33.584132\n");
   //print_zipinfo(info);
}
