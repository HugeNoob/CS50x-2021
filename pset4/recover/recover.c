#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

//COMPLETED

int main(int argc, char *argv[])
{
    //checks validity of key
    if(argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }
    
    //Open memory card
    FILE *file = fopen(argv[1], "r");
    
    //check validity of file
    if(file == NULL){
        printf("Unable to open file\n");
        return 1;
    }
    
    typedef uint8_t BYTE;
    BYTE buffer[512];
    char filename[999];
    int count = 0;
    bool first_jpeg = true;
    FILE *current_file;
    int size_read;
    bool found = false;
    
    //Repeat until end of card
    while(true){
        
        //Read 512 bytes into a buffer
        size_read = fread(buffer, sizeof(BYTE), 512, file);
        
        if(size_read == 0){
            break;
        }
        
        //If start of new JPEG
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            
            //if first jpeg
            if(first_jpeg){         
                first_jpeg = false;         //if first jpeg, nothing to close
                found = true;
            }
                        
            //else
            else{
                fclose(current_file);       
            }
            
            sprintf(filename, "%03i.jpg", count);            //creates filename with number xxx
            current_file = fopen(filename, "w");      //creates and opens file with name filename
            fwrite(buffer, sizeof(BYTE), size_read, current_file);         //writes a block into file
        
            count++;        //counts number of files
        }
        
        //else
        else{
            //if alr found jpeg
            if(found){
                fwrite(buffer, sizeof(BYTE), size_read, current_file);
            }
        }
    }
    
    //close any remaining files
    fclose(current_file);
    fclose(file);
    return 0;
    

}



//sprintf(filename, "03i.jpg", 2);
//fread(data, size, number, inptr);
//fwrite(data, size, num, outptr);