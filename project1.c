#include "time_functions_19.h"
#include "setpath_fn.h"

#define LINE_WIDTH 80

void read_file_by_char();
void read_file_by_line();

int main(){
	setpath();
	
	printf("Please insert a 1 to read by character or a 0 to read by line\n");
	int user_response;

	scanf("%i", &user_response);

	if(user_response){
		read_file_by_char();
	}
	else{
		read_file_by_line();
	}
	/*-------------------------------------------------------------------------------------
	When executed, the functions get_wall_clock_diff() and get_nanodiff() output the same results
	---------------------------------------------------------------------------------------*/
	printf("The wall clock time for the functions to end is: %f\n", get_wall_clock_diff());
	printf("The CPU time for the functions to end is: %f\n", get_nanodiff());


	return 0;
}

void read_file_by_char(){
	infile = fopen(in_path, "r");
	/*---------------------------------------------------------------------------------------
	Am I using setvbuf correctly?
	-----------------------------------------------------------------------------------------*/
	setvbuf(infile, 0,_IONBF, 0);	
	outfile = fopen(out_path, "w");
	setvbuf(outfile, 0, _IONBF, 0);

	/*---------------------------------------------------------------------------------------
		Am I using start_timing and stop_timing correctly
	-----------------------------------------------------------------------------------------*/
	start_timing();
	start_nanotime();
	while(!feof(infile)){
		char c;
		c = fgetc(infile);
		fputc(fgetc(infile), outfile);
	}
	stop_timing();
	stop_nanotime();
	fclose(infile);
	fclose(outfile);
}

void read_file_by_line(){
	infile = fopen(in_path, "r");
	setvbuf(infile, 0,_IONBF, 0);	
	outfile = fopen(out_path, "w");
	setvbuf(outfile, 0, _IONBF, 0);

	char buf[81] = {0};
	start_timing();
	start_nanotime();
	while(fgets(buf, LINE_WIDTH, infile) != NULL){
		fputs(buf, outfile);
	}
	stop_timing();
	stop_nanotime();
	fclose(infile);
	fclose(outfile);
}
