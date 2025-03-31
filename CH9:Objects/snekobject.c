#include <stdlib.h>
#include "snekobject.h"
#include <stdio.h>

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
snek_object_t **array = malloc(sizeof(snek_object_t) * size);
obj->data.v_array.elements = array; 
return obj;
}

bool snek_array_set(snek_object_t *obj, snek_object_t *value, int index){
if(obj == NULL || value == NULL || index == NULL || obj->kind != ARRAY || obj->data.v_array.size < index) { return false; }
obj->data.v_array.elements[index] = value;
return true;
}

snek_object_t snek_array_get(snek_object_t *obj, int index){
if(obj == NULL ||  index == NULL || obj->kind != ARRAY || obj->data.v_array.size < index) { return false; }

}

int main() {
    printf("sneklangobject");
    return 0;
}

