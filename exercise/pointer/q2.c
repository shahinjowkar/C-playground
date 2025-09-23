
/**QUESTION:
Modify Programming Project 8 from Chapter 5 so that it includes the following function:
void find_closest_flight(int desired_time,
int *departure_time,
int *arrival_time);
This function will find the flight whose departure time is closest to desired_time
(expressed in minutes since midnight). It will store the departure and arrival times of this
flight (also expressed in minutes since midnight) in the variables pointed to by
departure_time and arrival_time, respectively.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int processTime(const char *tok){
	int h,m;
	char ampm[3];
	sscanf(tok, "%d:%d %2s", &h,&m, ampm);	
	if (strstr(ampm, "pm") && h != 12) {
        h += 12;
    } 
	else if (strstr(ampm, "am") && h == 12) {
        h = 0;
    }
    return h * 60 + m;

}



int processInputTime(const char *time){
	int h,m;
	char ampm[3];
	sscanf(time, "%d:%d%2s", &h,&m,ampm);
	if (strstr(ampm, "pm") && h != 12) {
        h += 12;
    } 
	else if (strstr(ampm, "am") && h == 12) {
    	h = 0;
    }
    return h * 60 + m;
}





void formatTime(int minutes, char *buf, size_t bufSize) {
    int h = (minutes / 60) % 24;   
    int m = minutes % 60;
    const char *ampm = (h >= 12) ? "pm" : "am";
    if (h == 0) h = 12;        
    else if (h > 12) h -= 12;  
    snprintf(buf, bufSize, "%d:%02d %s", h, m, ampm);
}



void getCSV(const char *fileName, char *result[8][3]){
	FILE *fd = fopen(fileName,"r");
	char line[256];
	fgets(line,sizeof(line),fd);
	int countLine = 0;
	while(fgets(line, sizeof(line),fd)){
		int countToken = 0;
		line[strcspn(line,"\r\n")] = '\0';
		char *tok = strtok(line, ",");
		while(tok){
			if(countToken == 0){
				result[countLine][countToken] = strdup(tok);
			}
			else{
				result[countLine][countToken] = strdup(tok);
			}
			tok = strtok(NULL,",");
			countToken += 1;
		}
		countLine += 1;
	}

}

void find_next_flight(int desired_time, int *departure_time, int *arrival_time, char *result[8][3]) {
    int best_gap = INT_MAX;

    for (int i = 0; i < 8; i++) {
        int depart = processTime(result[i][1]);
        if (depart >= desired_time) {               
            int gap = depart - desired_time;        
            if (gap < best_gap) {
                best_gap = gap;
                *departure_time = depart;
                *arrival_time  = processTime(result[i][2]);
            }
        }
    }
}

int
main(int argc, char *argv[]){
	char *result[8][3];
	int departure_time, arrival_time;
	getCSV("flight.csv", result);
	char input[10];
	printf("when do you want to fly?");
	scanf("%9s",input);
	find_next_flight(processInputTime(input), &departure_time, &arrival_time, result);
	printf("%d\n", departure_time);
	printf("%d\n", arrival_time);
	char parsedDep[10],parsedArv[10];

	formatTime(departure_time,parsedDep, sizeof(parsedDep));
	formatTime(arrival_time,parsedArv, sizeof(parsedArv));

	printf("%s\n", parsedDep);
	printf("%s\n", parsedArv);
}
