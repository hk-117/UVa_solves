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

typedef struct Pair{
  char first[85];
  char second[85];
}Pair;

void init_list(List *list, size_t item_size){
  list->data = malloc(item_size * INITIAL_CAPACITY);
  list->item_size = item_size;
  list->length = 0;
  list->capacity = INITIAL_CAPACITY;
}

int sort_comparator(const void *a, const void *b){
  Pair *pa = (Pair *)a;
  Pair *pb = (Pair *)b;
  if(strcmp(pa->second,pb->second) == 0){
    return strcmp(pa->first,pb->first);
  }
  return strcmp(pa->second,pb->second);
}

int find_comparator(const void *a, const void *b){
  Pair *pa = (Pair *)a;
  Pair *pb = (Pair *)b;
  return strcmp(pa->first,pb->first);
}

void add_item(List *list, void *item){
  if(list->length == list->capacity){
    list->capacity *= 2;
    list->data = realloc(list->data, list->item_size * list->capacity);
  }
  memcpy((char*)list->data + (list->length * list->item_size), item, list->item_size);
  list->length++;
}

void remove_item(List *list, size_t index){
  if(index >= list->length) return;
  memmove((char*)list->data + (index * list->item_size), 
          (char*)list->data + ((index + 1) * list->item_size), 
          (list->length - index - 1) * list->item_size);
  list->length--;
}

void *get_item(List *list, size_t index){
  if(index >= list->length) return NULL;
  return (char*)list->data + (index * list->item_size);
}

void sort_list(List *list, int (*comparator)(const void*, const void*)){
  qsort(list->data, list->length, list->item_size, comparator);
}

void *find_item(List *list, void *key, int (*comparator)(const void*, const void*)){
  size_t i;
  for(i=0; i<list->length; i++){
    void *item = get_item(list,i);
    if(comparator(key,item) == 0){
      return item;
    }
  }
  return NULL;
}

void free_list(List *list){
  free(list->data);
  list->data = NULL;
  list->length = 0;
  list->capacity = 0;
}

int main(){
  char buffer[1005],name[100],author[100];
  Pair temp;
  List stock,borrowed,returned;
  init_list(&stock,sizeof(Pair));
  init_list(&borrowed,sizeof(Pair));
  init_list(&returned,sizeof(Pair));

  while(fgets(buffer,1005,stdin)){
    if(strcmp(buffer,"END\n") == 0) break;
    sscanf(buffer,"\"%[^\"]\" by %[^\n]",name,author);
    strcpy(temp.first,name);
    strcpy(temp.second,author);
    add_item(&stock,&temp);
  }

  sort_list(&stock,sort_comparator);

  while(fgets(buffer,1005,stdin)){

    if(strcmp(buffer,"END\n") == 0) break;

    if(strncmp(buffer,"BORROW",6) == 0){

      Pair *found;
      sscanf(buffer,"BORROW \"%[^\"]\"",name);
      strcpy(temp.first,name);
      found = (Pair *)find_item(&stock,&temp,find_comparator);
      if(found != NULL){
        size_t index = (size_t)(found - (Pair *)stock.data);
        add_item(&borrowed,found);
        remove_item(&stock,index);
      }

    } else if(strncmp(buffer,"RETURN",6) == 0){

      Pair *found;
      sscanf(buffer,"RETURN \"%[^\"]\"",name);
      strcpy(temp.first,name);
      found = (Pair *)find_item(&borrowed,&temp,find_comparator);
      if(found != NULL){
        size_t index = (size_t)(found - (Pair *)borrowed.data);
        add_item(&returned,found);
        remove_item(&borrowed,index);
      }

    } else {

      size_t i,pos;
      sort_list(&returned,sort_comparator);

      for(i=0; i<returned.length; i++){
        Pair *found;
        Pair *ret = (Pair *)get_item(&returned,i);
        add_item(&stock,ret);
        sort_list(&stock,sort_comparator);
        pos = stock.length-1;
        found = (Pair *)find_item(&stock,ret,find_comparator);
        if(found != NULL) pos = (size_t)(found - (Pair *)stock.data);
        if(pos == 0){
          printf("Put \"%s\" first\n",ret->first);
        } else {
          Pair *prev = (Pair *)get_item(&stock,pos-1);
          printf("Put \"%s\" after \"%s\"\n",ret->first,prev->first);
        }
      }

      printf("END\n");
      free_list(&returned);
      init_list(&returned,sizeof(Pair));

    }
  }  
  free_list(&stock);
  free_list(&borrowed);
  free_list(&returned);  
  return 0;
}
