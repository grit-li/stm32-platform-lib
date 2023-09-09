#include <string.h>
#include <stdio.h>
#include "properties.h"

struct properties_t
{
    char key[MAX_PROPERTIE_KEY_LEN];
    char value[MAX_PROPERTIE_VAL_LEN];
};

static struct properties_t g_property_array[MAX_PROPERTIE_NUM] = { 0 };
static int g_property_array_length = 0;
void property_get(const char* key, char* value, const char* def)
{
    int find = 0;
    for(int i = 0; i < g_property_array_length; i++) {
        if(strncmp(g_property_array[i].key, key, strlen(key)) == 0) {
            strncpy(value, g_property_array[i].value, MAX_PROPERTIE_VAL_LEN);
            find = 1;
            break;
        }
    }
    if(find == 0) {
        strcpy(value, def);
    }
}

void property_set(const char* key, const char* value)
{
    int find = -1;
    for(int i = 0; i < g_property_array_length; i++) {
        if(strncmp(g_property_array[i].key, key, strlen(key)) == 0) {
            find = i;
            break;
        }
    }
    
    if(g_property_array_length < MAX_PROPERTIE_NUM) {
        if(find >= 0) {
            strcpy(g_property_array[find].value, value);
        } else {
            strcpy(g_property_array[g_property_array_length].key, key);
            strcpy(g_property_array[g_property_array_length].value, value);
            g_property_array_length++;
        }
    }
}

void property_print(void)
{
    for(int i = 0; i < g_property_array_length; i++) {
        printf("[%s]:[%s]\n", g_property_array[i].key, g_property_array[i].value);
    }
}