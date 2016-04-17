/* DEMO to learn the Spliting the words in text file  */
/* NOTE: TEST File needs to be present in same directory */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<glib.h>

void free_array(char** array)
{
	char **temp = array;
	if ( NULL != array)
	{
		while(NULL  != *array)
		{
			free(*array);
			array++;
		}
		free(temp);
	}
}


int main( int argc , char *argv[] )
{
	char *file_read = NULL;
	char **line = NULL;
	char **line_parts = NULL;
	int counter_1 = 0;
	int counter_2 = 0;

	/* Get all the content of file */
	g_file_get_contents("./test",&file_read,NULL,NULL);
	
	/* first split the file content into different lines */
	line = g_strsplit_set(file_read,"\n",-1);

	/* Get number of lines */
	int no_of_lines = g_strv_length(line);

	/* Perform spliting on individual line */
	for(counter_1=0;counter_1<no_of_lines;counter_1++)
	{
		/* Spliting on spaces and tabs */
		line_parts = g_strsplit_set(line[counter_1]," \t,;",-1);

		int size = g_strv_length(line_parts);
		
		for(counter_2=0;counter_2<size;counter_2++)
		{
			/* Just printing the words and their length */
			printf("%s \t",line_parts[counter_2]);
			printf("%ld\n", strlen(line_parts[counter_2]));
		}

		/* Free the individual array */
		free_array( line_parts );
	}
	/* free main array */
	free_array(line);
	/* Free file */	
	free(file_read);

	return(EXIT_SUCCESS);

}
