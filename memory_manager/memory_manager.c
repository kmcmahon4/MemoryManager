
#include <stdio.h>
#include <stdlib.h>




 struct process
{
  int pid;
  int size;
};

struct block
{
  int size;
};

int main()
{//start main

printf("******* MEMORY MANAGER PROGRAM ********\n");
printf("******* @author: Kerri McMahon ********\n");
printf("*******    Assumptions.        ********\n");  
printf("        Ready Queue Limit: 10\n");
printf("        Memory Size: Whatever the sum\n" );
printf("                      your blocks is.\n");
printf("        Job size: < 1000.\n");
printf("        Please be easy on me this was hard. :(\n");
printf("****************************************\n\n");


int running =0;
int a;

while(running !=9)

{//start while
printf("Pick an algorithm. press 1 for FF, 2 for BF, 3 for WF -- Press 9 to quit\n");
scanf("%d", &a);

int ff();
void bf();
void wf();


if (a==9)
{
exit(0);
}

if(a==1)
{
ff();

}
 if (a == 2)
{
bf();
}
if (a == 3)
{
wf();
}
} //end while


return 0;

}//end main


int ff()
{       //max processes is 10

        struct block blocks[10];
        struct process files[10];
    static int block_arr[10], file_arr[10];
      int fragments[10];// blocks[10], files[10];
      int m, n, number_of_blocks, number_of_files, temp;
      printf("\nEnter the Total Number of Blocks:\t");
      scanf("%d", &number_of_blocks);
      printf("Enter the Total Number of Files:\t");
      scanf("%d", &number_of_files);
      printf("\nEnter the Size of the Blocks:\n");
      for(m = 0; m < number_of_blocks; m++) 
      {
            printf("Block No.[%d]:\t", m );
            scanf("%d", &blocks[m].size);
      }
      printf("Enter the PID for each process:\n");
      for (m =0; m <number_of_files;m++)
      {
          printf("PID: ");
          scanf("%d", &files[m].pid);
      }
      printf("Enter the Size of the Files:\n");
      for(m = 0; m < number_of_files; m++) 
      {
            printf("File No.[%d]:\t", files[m].pid );
            scanf("%d", &files[m].size);
      }
      for(m = 0; m < number_of_files; m++)
      {
            for(n = 0; n < number_of_blocks; n++)
            {
                  if(block_arr[n] != 1)
                  {
                        temp = blocks[n].size - files[m].size;
                        if(temp >= 0)
                        {
                              file_arr[m] = n;
                              break;
                        }
                  }
            }
            fragments[m] = temp;
            block_arr[file_arr[m]] = 1;
      }
      printf("\nFile Number\tBlock Number\tFile Size\tBlock Size\tFragment");
      for(m = 0; m < number_of_files; m++)
      {
          if (fragments[m]<0 )
          {
              continue;
          }
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", files[m].pid, file_arr[m], files[m].size, blocks[file_arr[m]].size, fragments[m]);
      }
      printf("\n\n\n");
      
      int b =0;
      while (b != 9)
      {
          printf("1. Remove a Process\n9. Back to Main Menu\n");
          scanf("%d", &b);
            if (b==9)
            {
                return 0;
            }
          if(b=1)
          {
                
              int remove;
              printf("Which process number to remove?");
              scanf("%d", &remove);
                
                printf("\nFile Number\tBlock Number\tFile Size\tBlock Size\tFragment");
              for(m = 0; m < number_of_files; m++)
                {
                    //Establishing statistical conditions for when a block is freed.
                    if(remove ==  files[m].pid)
                    {
                        continue;
                     //99 indicates a freed slot
                     //printf("\nin if\n");
                     //file_arr[m]=999;
                     //fragments[m] =  blocks[file_arr[m]].size
                    }
                    if (fragments[m]<0 || fragments[m] >999)
                    continue;
                printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", files[m].pid, file_arr[m], files[m].size, blocks[file_arr[m]].size, fragments[m]);
                 }
                printf("\n\n\n");


              
          }//end if



      }//end while
      return 0;

}// end ff

void bf()
{

    struct block block[10];
    struct process file[10];
    int fragments[10],  m, n, number_of_blocks, number_of_files, temp, lowest = 10000; //block[10], file[10],
      static int block_arr[10], file_arr[10];
      printf("\nEnter the Total Number of Blocks:\t");
      scanf("%d", &number_of_blocks);
      printf("\nEnter the Total Number of Files:\t");
      scanf("%d", &number_of_files);
      printf("\nEnter the Size of the Blocks:\n");
      for(m = 0; m < number_of_blocks; m++) 
      {
            printf("Block No.[%d]:\t", m );
            scanf("%d", &block[m].size);
      }
      printf("Enter the PID for each process");
      for (m=0;m< number_of_files;m++)
      {
          scanf("%d", &file[m].pid);
      }
      
      printf("Enter the Size of the Files:\n");
      for(m = 0; m < number_of_files; m++) 
      {
            printf("File No.[%d]:\t", file[m].pid); 
            scanf("%d", &file[m].size);
      }
      for(m = 0; m < number_of_files; m++)
      {
            for(n = 0; n < number_of_blocks; n++)
            {
                  if(block_arr[n] != 1)
                  {
                        temp = block[n].size - file[m].size;
                        if(temp >= 0)
                        {
                              if(lowest > temp)
                              {
                                    file_arr[m] = n;
                                    lowest = temp;
                              }
                        }
                  }
                  fragments[m] = lowest;
                  block_arr[file_arr[m]] = 1;
                  lowest = 10000;
            }
      }
      printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
      for(m = 0; m < number_of_files; m++) //&& file_arr[m] != 0
      {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", file[m].pid, file[m].size, file_arr[m], block[file_arr[m]].size, fragments[m]);
      }
      printf("\n");





      int b =0;
      while (b != 9)
      {
          printf("1. Remove a Process\n9. Back to Main Menu\n");
          scanf("%d", &b);
            if (b==9)
            {
                return 0;
            }
          if(b=1)
          {
                
              int remove;
              printf("Which process number to remove?");
              scanf("%d", &remove);
                
                printf("\nFile Number\tBlock Number\tFile Size\tBlock Size\tFragment");
              for(m = 0; m < number_of_files; m++)
                {
                    //Establishing statistical conditions for when a block is freed.
                    if(remove ==  file[m].pid)
                    {
                        continue;
                     //99 indicates a freed slot
                     //printf("\nin if\n");
                     //file_arr[m]=999;
                     //fragments[m] =  blocks[file_arr[m]].size;


                    }
                printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", file[m].pid, file_arr[m], file[m].size, block[file_arr[m]].size, fragments[m]);
                 }
                printf("\n");


              
          }//end if



      }//end while
      
}//end bf


void wf()
{
   int fragments[10], blocks[10], files[10];
      int m, n, number_of_blocks, number_of_files, temp, top = 0;
      static int block_arr[10], file_arr[10];
      printf("\nEnter the Total Number of Blocks:\t");
      scanf("%d",&number_of_blocks);
      printf("Enter the Total Number of Files:\t");
      scanf("%d",&number_of_files);
      printf("\nEnter the Size of the Blocks:\n");
      for(m = 0; m < number_of_blocks; m++) 
      {
            printf("Block No.[%d]:\t", m );
            scanf("%d", &blocks[m]);
      }
      printf("Enter the Size of the Files:\n");
      for(m = 0; m < number_of_files; m++) 
      {
            printf("File No.[%d]:\t", m );
            scanf("%d", &files[m]);
      }
      for(m = 0; m < number_of_files; m++)
      {
            for(n = 0; n < number_of_blocks; n++)
            {
                  if(block_arr[n] != 1)
                  {
                        temp = blocks[n] - files[m];
                        if(temp >= 0)
                        {
                              if(top < temp)
                              {
                                    file_arr[m] = n;
                                    top = temp;
                              }
                        } 
                  }
                  fragments[m] = top;
                  block_arr[file_arr[m]] = 1;
                  top = 0;
            }   
      }
      printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
      for(m = 0; m < number_of_files; m++)
      {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", m, files[m], file_arr[m], blocks[file_arr[m]], fragments[m]);
      }
      printf("\n");
      
}