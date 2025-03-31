#include <stdlib.h>
#include "snekobject.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


snek_object_t *snek_add(snek_object_t *a, snek_object_t *b){
    switch (a->kind){
    case INTEGER:{
       switch (b->kind)
       {
       case FLOAT: return new_snek_float((float)a->data.v_int + b->data.v_float);
       case  INTEGER: return new_snek_integer(a->data.v_int+b->data.v_int);
       default: return NULL;
       }
    }
    case FLOAT:{
      switch (b->kind)
      {
      case INTEGER:return new_snek_float(a->data.v_float + (float)b->data.v_int);
      case FLOAT: return new_snek_float(a->data.v_float+b->data.v_float);
      default:return NULL;
      }        
    }
    case STRING:{
        if(b->kind != STRING) {return NULL;}
        int length  = strlen(a->data.v_string) + strlen(b->data.v_string) + 1;
        char *newStr = malloc(sizeof(char)* length);
        strcat(newStr, b->data.v_string);
        strcat(newStr,a->data.v_string);
        return new_snek_string(newStr);
    }
    case VECTOR3:{
        if(b->kind != VECTOR3) {return NULL;}
        return new_snek_vector3(
        snek_add(a->data.v_vector3.x, b->data.v_vector3.x),
        snek_add(a->data.v_vector3.y, b->data.v_vector3.y),
        snek_add(a->data.v_vector3.z, b->data.v_vector3.z));
    }
    case ARRAY:{
        if(b->kind!=ARRAY) { return NULL;}
        int length = a->data.v_array.size+b->data.v_array.size;
        int i;
        snek_object_t *obj = new_snek_array(length);
        for(i=0;i<= a->data.v_array.size;i++){
        snek_array_set(obj,a->data.v_array.elements[i],i);
        }
        for(i=a->data.v_array.size+1;i<= a->data.v_array.size;i++){
        snek_array_set(obj,b->data.v_array.elements[i],i);
        }
        return obj;
    } 
}
}

int snek_length(snek_object_t *obj) {
    switch (obj->kind)
    {
    case INTEGER:
            return 1;
    case FLOAT:
            return 1;
    case STRING:
            return strlen(obj->data.v_string);
    case VECTOR3: 
            return 3;
    case ARRAY:
            return obj->data.v_array.size;
    default:
        return -1;
    }
        return -1;
  }

snek_object_t *new_snek_string(char *value) {
snek_object_t *obj = malloc(sizeof(snek_object_t));
if(obj == NULL) { return NULL; }
obj->kind = STRING;
obj->data.v_string = value;
return obj;
}

snek_object_t *new_snek_float(float value){
snek_object_t *obj = malloc(sizeof(snek_object_t));
if(obj == NULL) { return NULL; }
obj->kind = FLOAT;
obj->data.v_float = value;
return obj;
}

snek_object_t *new_snek_integer(int value) {
    snek_object_t *obj = malloc(sizeof(snek_object_t));
    if(obj == NULL) { return NULL; }
    obj->kind = INTEGER;
    obj->data.v_int = value;
    return obj;
}

snek_object_t *new_snek_vector3(snek_object_t *x,snek_object_t *y, snek_object_t *z){
    if(x == NULL || y == NULL || z == NULL) {return NULL;}
    snek_object_t *obj = malloc(sizeof(snek_object_t));
    if(obj == NULL) { return NULL; }
    obj->kind = VECTOR3;
    obj->data.v_vector3 = (snek_vector_t){.x=x, .y=y, .z=z};
    return obj;
}
snek_object_t *new_snek_array(int size) {
snek_object_t *obj = malloc(sizeof(snek_object_t));
if(obj == NULL) { return NULL; }
obj->kind = ARRAY;
obj->data.v_array.size = size;
snek_object_t **array = calloc(size, sizeof(snek_object_t));
obj->data.v_array.elements = array; 
return obj;
}

bool snek_array_set(snek_object_t *obj, snek_object_t *value, int index){
if(obj == NULL || value == NULL || obj->kind != ARRAY || obj->data.v_array.size <= index) { return false; }
obj->data.v_array.elements[index] = value;
return true;
}

snek_object_t *snek_array_get(snek_object_t *obj, int index){
if(obj == NULL || obj->kind != ARRAY || obj->data.v_array.size <= index) { return NULL; }
return obj->data.v_array.elements[index];
}

int main() {
    printf("sneklangobject");
    return 0;
}

