#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INITIAL_CAPACITY 2

typedef struct List{
  void *data;
  size_t item_size;
  size_t length;
  size_t capacity;
}List;

typedef struct String{
  char *str;
}String;

void init_list(List *list, size_t item_size){
  list->data = malloc(item_size * INITIAL_CAPACITY);
  list->item_size = item_size;
  list->length = 0;
  list->capacity = INITIAL_CAPACITY;
}

void add_item(List *list, void *item){
  if(list->length == list->capacity){
    list->capacity *= 2;
    list->data = realloc(list->data, list->item_size * list->capacity);
  }
  memcpy((char*)list->data + (list->length * list->item_size), item, list->item_size);
  list->length++;
}

void *get_item(List *list, size_t index){
  if(index >= list->length) return NULL;
  return (char*)list->data + (index * list->item_size);
}

void free_list(List *list){
  free(list->data);
  list->data = NULL;
  list->length = 0;
  list->capacity = 0;
}

int count_spaces(String *str){
  int i,count = 0;
  for(i = 0; str->str[i] != '\0'; i++){
    if(str->str[i] == ' ') count++;
  }
  return count;
}

int main(){
  int n, min;
  char buffer[101];
  List pic, spaces;

  while( scanf("%d", &n) != EOF && n != 0 ){
    int i,total_void;
    String line;

    getchar(); 

    init_list(&pic, sizeof(String));
    for(i = 0; i < n; i++){
      int len;
      fgets(buffer, 101, stdin);
      len = strcspn(buffer, "\n");
      buffer[len] = 0;
      line.str = malloc(len * sizeof(char));
      strcpy(line.str, buffer);
      add_item(&pic, &line);
    }

    init_list(&spaces, sizeof(int));
    min = 101;
    for(i = 0; i < pic.length; i++){
      int space_count = count_spaces((String*)get_item(&pic, i));
      if(space_count < min) min = space_count;
      add_item(&spaces, &space_count);
    }
    total_void = 0;
    for(i = 0; i < spaces.length; i++){
      int space_count = *(int*)get_item(&spaces, i);
      total_void += (space_count - min);
    }
    printf("%d\n", total_void);
    free_list(&pic);
    free_list(&spaces);
  }
}
