#ifndef __PLATFORM_PROPERTIES_H__
#define __PLATFORM_PROPERTIES_H__

#ifdef __cplusplus
extern "C" {
#endif

void property_get(const char* key, char* value, const char* def);
void property_set(const char* key, const char* value);

#ifdef __cplusplus
}
#endif

#endif