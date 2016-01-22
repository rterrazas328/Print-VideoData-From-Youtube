#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 250

struct clip *build_a_lst();
struct clip *append();
int find_length();
void print_a_lst();
void split_line();

struct clip {
  int views;
  char *user;
  char *id;
  char *title;
  char *time;
  struct clip *next;
} *head;

int main(int argc, char **argv) {
  int n;
  head = build_a_lst(argv[1]);

  //n = find_length(head);
  //printf("%d clips\n",n);
  printf("List built\n");
  print_a_lst(head);		/* prints the table */

  printf("success\n");
  return 0;
}

struct clip* build_a_lst(char *fn) {
  FILE *fp;
  struct clip *hp=NULL;
  char *fields[5];
  char line[LINE_LENGTH];
  int cnt=0;
  hp=NULL;


  fp = fopen(fn, "r"); // open fn for reading
  if (fp == NULL){
  fprintf(stderr, "Error in opening file.\n");
  exit(1);
  }
  printf("reading lines\n");

  while (fgets(line, LINE_LENGTH, fp) != NULL){ // while no more lines
   // read a line
   // printf("line: %s\n", line);
  //printf("pointer value: %p\n", fields);
  split_line(fields, line);//split the line into four substrings/int and store them in a struct
  //printf("user: %s, views: %s, id: %s, time: %s, title: %s\n", fields[0], fields[1], fields[3], fields[2], fields[4]);
  hp = append(hp,fields); // append - add the struct at the end of the list
  //printf("before for\n");
  int i;
  for(i=0;i<5;i++){
    free(fields[i]);
  }//*/
  printf("\n");
  //printf("appended\n");
  // return the head pointer holding the list
	//hp = hp+1;
	}
  //*/
	if(fclose(fp)==0){
    printf("File closed successfully...\n");
  }
  else{
    printf("Error when attempting to close file!\n");
  }

  return hp;
}

/* fields will have four values stored upon return */
void split_line(char **fields,char *line) {
  int i;
  char *token, *delim;
  delim = ",\n";
  //printf("pointer value: %p\n", fields);
  /*if(delim[2]=='\0'){
  printf("null found @ delim!\n");
}//*/

  //fields = (char**) malloc(sizeof(char*)*5); 
  //printf("Size of fields@2: %d\n", sizeof(fields));
  //printf("fields@2: %c\n", fields[0][0]);
  //token = (char *) malloc(LINE_LENGTH+1); do we need?
  /* 
     call strtok(line, delim);
     malloc and strcpy token to fields

     repeat until strtok returns NULL using strtok(NULL, delim);
     each time you get token, malloc and strcpy to fields
 */
  token = strtok(line, delim);
  for(i=0;i<5;i++){//problem area
  //pointer to first row of chars
  fields[i] = (char *) malloc(strlen(token)+1);
  strcpy(fields[i], token);
  token = strtok(NULL, delim);  //PROBLEM IS HERE
  }//*/



}

/* set four values into a clip, insert a clip at the of the list */
struct clip *append(struct clip *hp,char **five) {
  struct clip *cp,*tp;

  /* 
     malloc tp
     set views using atoi(*five)
     malloc for four strings.
     strcpy four strings to tp
     insert tp at the end of the list pointed by hp
     use cp to traverse the list
 */
  tp = (struct clip*) malloc(sizeof(*tp));
  cp = (struct clip*) malloc(sizeof(*cp));
  int i=0;
  i = atoi(five[1]);

  //printf("user: %s, views: %s, id: %s, time: %s, title: %s\n", five[0], five[1], five[3], five[2], five[4]);

  tp->user = (char *) malloc(strlen(five[0])+1);
  tp->views = i;
  tp->id = (char *) malloc(strlen(five[3])+1);
  tp->time = (char *) malloc(strlen(five[2])+1);
  tp->title = (char *) malloc(strlen(five[4])+1);

  strcpy(tp->user, five[0]);
  strcpy(tp->id, five[3]);
  strcpy(tp->time, five[2]);
  strcpy(tp->title, five[4]);
  //printf("user: %s, views: %d, id: %s, time: %s, title: %s\n", tp->user, tp->views, tp->id, tp->time, tp->title);

  if (hp == NULL) {//possible problem area
    hp = tp;
    hp->next=NULL;
  } 
  else {
    cp = hp;

     while(cp->next != NULL){
      cp = cp->next;
    }
    tp->next = NULL;
    cp->next = tp; //appended here
  }
  return hp;
}

void print_a_lst(struct clip *cp) {
  while (cp->next != NULL){
     printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title,cp->time);
     cp = cp->next;
  }
  if(cp != NULL){
    printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title,cp->time);
  }
}

/* end */
