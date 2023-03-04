#include <conio.h>
#include <stdio.h>
#include <string.h>
 
// Driver Code
int main()
{
    // Substitute the full file path
    // for the string file_path
    FILE* fp = fopen("test.csv", "r");
 
    if (!fp)
        printf("Can't open file\n");
 
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[50];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,1024, fp)) {
            column = 0;
            row++;
 
            // To avoid printing of column
            // names in file can be changed
            // according to need
 
            // Splitting the data
            char* value = strtok(buffer, ", ");
 
            while (value) {
                // Column 1
                if (column == 0) {
                    printf("Name :");
                }
 
                // Column 2
                if (column == 1) {
                    printf("\tID :");
                }
 
                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }
 
            printf("\n");
        }
 
        // Close the file
        fclose(fp);
    }
    return 0;
}
