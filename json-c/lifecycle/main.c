/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/30/2018 04:00:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <json-c/json.h>

int main(int argc, char **argv)
{
    json_object *sJsonObject;

    char *cJsonString = "{          \
        \"k1\" : 1,                 \
        \"k2\" : 1.1,               \
        \"k3\" : \"string\",        \
        \"键\" : \"值\"             \
    }";

    sJsonObject = json_tokener_parse(cJsonString);
    printf("jsonObject.to_json=%s\n", json_object_to_json_string(sJsonObject));
    printf("jsonObject.to_json2=%s\n", json_object_to_json_string_ext(sJsonObject, JSON_C_TO_STRING_NOSLASHESCAPE));
    printf("jsonObject.to_json3=%s\n", json_object_to_json_string_ext(sJsonObject, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_SPACED));

    json_object *sTmpJsonObject = NULL;
    json_object_deep_copy(sJsonObject, &sTmpJsonObject, NULL);
    json_object_object_add(sJsonObject, "jsonObject", sTmpJsonObject);

    json_object_object_add(sJsonObject, "k4", json_object_new_boolean(1));
    printf("jsonObject=%s\n", json_object_to_json_string_ext(sJsonObject, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_SPACED));

    printf("%s=%s\n", "键", json_object_get_string(json_object_object_get(sJsonObject, "键")));
    json_object_get(sTmpJsonObject);
    json_object_put(sTmpJsonObject);
    json_object_put(sJsonObject);

    return 0;
}
