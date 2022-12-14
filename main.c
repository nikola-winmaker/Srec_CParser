/*
 * main.c
 *
 *  Created on: Nov 13, 2022
 *      Author: nikola
 */

#include <stdio.h>
#include <string.h>
#include "parser/parser_interface.h"


int main(int argc, char *argv[]){

    FILE *mot_ptr;
    char byte;
    int bytes_read = -1;
    t_parser_ret ret;
    mot_ptr = fopen("/Users/nikola/Desktop/Work/C_Apps/MOT_CParser/example/mot_example.mot","rb");  // r for read, b for binary


    t_record_info rec_info = {0};
    while(bytes_read != 0) {
        bytes_read = fread(&byte,sizeof(char),1,mot_ptr); // read 10 bytes to our buffer

        //(void) record_parse_sync(&byte, &rec_info);
        ret = Parser.parse_input(&byte);
        if(ret == PARSE_OK){
            Parser.get_record(&rec_info);
            printf("Type: 0x%x\n", rec_info.type);
            printf("Addr: 0x%lx\n", rec_info.address);
            printf("Data: %s\n", rec_info.data);
            printf("Csum: 0x%x\n", rec_info.csum);
            //executor
            //
       }
    }



	return 0;
}
