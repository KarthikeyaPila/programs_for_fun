#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#define MALLOC(p,s) \
	if (!((p) = malloc(s))) {\
		fprintf(stderr, "malloc failed"); \
		exit(EXIT_FAILURE); \
	}

void textToBrainfuck(const char *text, FILE *f_out){
    int currentValue = 0;

    for(size_t i = 0; i < strlen(text); i++){
        int targetValue =(int)text[i];
        int difference = targetValue - currentValue;

        if(difference > 0){
            for(int j = 0; j < difference; j++){
                fputs("+",f_out);
            }
        } else if(difference < 0){
            for(int j = 0; j < -difference; j++){
                fputs("-",f_out);
            }
        }
    
        fputs(".",f_out);
        
        currentValue = targetValue;
    }

    return;
}

int main(){
    FILE * f_in;
    f_in = fopen(INPUT_FILE_NAME, "rb   ");
    FILE * f_out;
    f_out = fopen(OUTPUT_FILE_NAME, "w");

    if (!f_in || !f_out) {
        fprintf(stderr, "Failed to open input or output file\n");
        return 1;
    }
    
    char *buffer;
    long file_size;
    size_t result;

    fseek (f_in , 0 , SEEK_END);
    file_size = ftell (f_in);
    rewind (f_in);
    MALLOC(buffer, sizeof(char)*file_size)
    buffer[file_size] = '\0';

    result = fread (buffer, 1, file_size, f_in);
    if (result != file_size) {
        fputs ("unable to read",stderr); 
        exit;
    }


    textToBrainfuck(buffer, f_out);

    fclose(f_in);
    fclose(f_out);
    free(buffer);
    return 0;
}
