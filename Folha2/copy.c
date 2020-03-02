#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_LENGTH 256 

int main(int argc,char *argv[]) {   

	if(argc!=3){ printf("Error!! Usage: copy file1 file2\n"); }

	FILE *src, *dst;   
	char buf[BUF_LENGTH];

	char *infile = argv[1];
	char *outfile = argv[2];



	if ( ( src = fopen( infile, "r" ) ) == NULL )    {
		//perror("Error");
		//printf("Error: %s\n", strerror(errno));
		//printf("Error: %d\n", errno);
	    exit(1);     
	 }   
	 if ( ( dst = fopen( outfile, "w" ) ) == NULL )   { 
	    exit(2);  
	}   
	while( ( fgets( buf, BUF_LENGTH+1, src ) ) != NULL )   { 
	    fputs( buf, dst );   
	}   
	fclose( src );   
	fclose( dst );   
	exit(0);  // zero é geralmente indicativo de "sucesso" 
}