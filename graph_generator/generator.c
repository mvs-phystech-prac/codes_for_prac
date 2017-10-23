#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

char buf1[4096];
char buf2[4096];


int main(int argc,char **argv)
{
    unsigned int size_x, size_y, size_z;
    char *graph_file;

    int i,j,k;

    FILE *file;
    
    if(argc<5)
    {
        printf("Please show size_x size_y size_z graph_file\n");
        return 1;
    }

    size_x=atoi(argv[1]);
    size_y=atoi(argv[2]);
    size_z=atoi(argv[3]);
    graph_file=argv[4];

    file=fopen(graph_file,"w");
    if(file==NULL)
    {
        fprintf(stderr,"Can't open '%s'\n",graph_file);
        return 2;
    }

    fprintf(file,"Vertices:\n");

    for(i=0;i<size_x;i++)
    for(j=0;j<size_y;j++)
    for(k=0;k<size_z;k++)
    {
        sprintf(buf1,"v_%d_%d_%d",i,j,k);
        fprintf(file,"   %s\n",buf1);
    }

    fprintf(file,"\nEdges:\n");
    
    for(i=0;i<size_x;i++)
    for(j=0;j<size_y;j++)
    for(k=0;k<size_z;k++)
    {
        sprintf(buf2,"v_%d_%d_%d",i,j,k);
        if(i != 0)
        {
            
            sprintf(buf1,"v_%d_%d_%d",i-1,j,k);
            fprintf(file,"   %s -> %s\n    { %u , %u, %u \"car\"}\n\n",
                    buf1,
                    buf2,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)/2),
                    (unsigned int)((i+j+k)*3)
                   );

            fprintf(file,"   %s -> %s\n    { %u , %u, %u \"flight\"}\n\n",
                    buf2,
                    buf1,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)*5),
                    (unsigned int)((i+j+k)/100)
                   );

        }

        if(i != size_x-1 )
        {
            sprintf(buf1,"v_%d_%d_%d",i+1,j,k);
            fprintf(file,"   %s -> %s\n    { %u , %u, %u \"car\"}\n\n",
                    buf1,
                    buf2,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)/2),
                    (unsigned int)((i+j+k)*3)
                   );

            fprintf(file,"   %s -> %s\n    { %u , %u, %u \"flight\"}\n\n",
                    buf2,
                    buf1,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)*5),
                    (unsigned int)((i+j+k)/100)
                   );

        }
    
        if(j != 0)
        {
            
            sprintf(buf1,"v_%d_%d_%d",i,j-1,k);
            fprintf(file,"   %s -> %s\n    { %u , %u, %u \"car\"}\n\n",
                    buf1,
                    buf2,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)/2),
                    (unsigned int)((i+j+k)*3)
                   );

            fprintf(file,"   %s -> %s\n    { %u , %u, %u \"flight\"}\n\n",
                    buf2,
                    buf1,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)*5),
                    (unsigned int)((i+j+k)/100)
                   );

        }

        if(j != size_y-1 )
        {
            sprintf(buf1,"v_%d_%d_%d",j+1,j,k);
            fprintf(file,"   %s -> %s\n    { %u , %u, %u \"car\"}\n\n",
                    buf1,
                    buf2,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)/2),
                    (unsigned int)((i+j+k)*3)
                   );

            fprintf(file,"   %s -> %s\n    { %u , %u, %u \"flight\"}\n\n",
                    buf2,
                    buf1,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)*5),
                    (unsigned int)((i+j+k)/100)
                   );

        }

        if(k != 0)
        { 
            sprintf(buf1,"v_%d_%d_%d",i,j,k-1);
            if(k%2)
            {               
                fprintf(file,"   %s -> %s\n    { %u , %u, %u \"ship\"}\n\n",
                    buf1,
                    buf2,
                    (unsigned int)i+j+k,
                    1000,
                    (unsigned int)((i+j+k)*100)
                   );
            }
            else
            {
                fprintf(file,"   %s -> %s\n    { %u , %u, %u \"flight\"}\n\n",
                    buf2,
                    buf1,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)*5),
                    (unsigned int)((i+j+k)/100)
                   );
            }

        }

        if(k != size_z-1)
        { 
            sprintf(buf1,"v_%d_%d_%d",i,j,k+1);
            if(k%2)
            {               
                fprintf(file,"   %s -> %s\n    { %u , %u, %u \"ship\"}\n\n",
                    buf1,
                    buf2,
                    (unsigned int)i+j+k,
                    1000,
                    (unsigned int)((i+j+k)*100)
                   );
            }
            else
            {
                fprintf(file,"   %s -> %s\n    { %u , %u, %u \"flight\"}\n\n",
                    buf2,
                    buf1,
                    (unsigned int)i+j+k, 
                    (unsigned int)((i+j+k)*5),
                    (unsigned int)((i+j+k)/100)
                   );
            }

        }
   
    }
   

    fclose(file);

    return 0;
}
