#ifndef __DATACACHE_H__
#define __DATACACHE_H__

#include <stdint.h>
#include "stm32_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct DATA_CACHE
{
    uint32_t    dRdIndex;
    uint32_t    dWrIndex;
    uint32_t    dMaxBufLen;
    uint8_t     *pBufAddr;
};

void DataCacheInit(struct DATA_CACHE* Cache, uint8_t* pBufAddr, uint32_t dMaxBufLen);
enum stm32_bool_e PopDataCacheByte(struct DATA_CACHE* Cache, uint8_t* RdData);
enum stm32_bool_e PushDataCacheByte(struct DATA_CACHE* Cache, uint8_t WrData);
enum stm32_bool_e FetchDataCacheByte(struct DATA_CACHE* Cache, uint8_t* RdData);
enum stm32_bool_e PopDataCacheBuff(struct DATA_CACHE* Cache, uint8_t* RdBuff, uint32_t dMaxBufLen);
enum stm32_bool_e PushDataCacheBuff(struct DATA_CACHE* Cache, const uint8_t* WrBuff, uint32_t dMaxBufLen);
enum stm32_bool_e FetchDataCacheBuff(struct DATA_CACHE* Cache, uint8_t* RdBuff, uint32_t dMaxBufLen);
uint32_t DataCacheRatio(struct DATA_CACHE* Cache);
uint32_t DataCacheSize(struct DATA_CACHE* Cache);

#ifdef __cplusplus
}
#endif

#endif