#include "datacache.h"

#define CacheRdIdx(CACHE)           (CACHE->dRdIndex)
#define CacheWrIdx(CACHE)           (CACHE->dWrIndex)
#define CacheMaxSz(CACHE)           (CACHE->dMaxBufLen)
#define CacheStartAddr(CACHE)       (CACHE->pBufAddr)
#define CacheEndAddr(CACHE)         (CACHE->pBufAddr + CACHE->dMaxBufLen)
#define CacheRdAddr(CACHE)          (CacheStartAddr(CACHE) + CacheRdIdx(CACHE))
#define CacheWrAddr(CACHE)          (CacheStartAddr(CACHE) + CacheWrIdx(CACHE))
#define CacheExistNewData(CACHE)    (CacheRdIdx(CACHE) != CacheWrIdx(CACHE))

#define LineCacheDataSz(cache)      (CacheWrIdx(cache) - CacheRdIdx(cache))
#define LoopCacheDataSz(cache)    \
    ((CacheRdIdx(cache) <= CacheWrIdx(cache))?    \
        (CacheWrIdx(cache) - CacheRdIdx(cache)):    \
        (CacheMaxSz(cache) - CacheRdIdx(cache) + CacheWrIdx(cache))    \
    )

#define LineCacheEmptySz(cache)     (CacheMaxSz(cache) - CacheWrIdx(cache))
#define LoopCacheEmptySz(cache) \
    ((CacheRdIdx(cache) >= CacheWrIdx(cache))?    \
        (CacheRdIdx(cache) - CacheWrIdx(cache)):    \
        (CacheMaxSz(cache) - CacheWrIdx(cache) + CacheRdIdx(cache))    \
    )

void DataCacheInit(struct DATA_CACHE* Cache, uint8_t* pBufAddr, uint32_t dMaxBufLen)
{
    CacheStartAddr(Cache) = pBufAddr;
    CacheMaxSz(Cache) = dMaxBufLen;
    CacheRdIdx(Cache) = 0;
    CacheWrIdx(Cache) = 0;
}

enum stm32_bool_e PopDataCacheByte(struct DATA_CACHE* Cache, uint8_t* RdData)
{
    if(CacheExistNewData(Cache)) {
        *RdData = CacheStartAddr(Cache)[CacheRdIdx(Cache)];
        if(++CacheRdIdx(Cache) >= CacheMaxSz(Cache)) {
            CacheRdIdx(Cache) = 0;
        }
        return stm32_true;
    }
    return stm32_false;
}

enum stm32_bool_e PushDataCacheByte(struct DATA_CACHE* Cache, uint8_t WrData)
{
    CacheStartAddr(Cache)[CacheWrIdx(Cache)] = WrData;
    if(++CacheWrIdx(Cache) >= CacheMaxSz(Cache)) {
        CacheWrIdx(Cache) = 0;
    }
    return stm32_true;
}

enum stm32_bool_e FetchDataCacheByte(struct DATA_CACHE* Cache, uint8_t* RdData)
{
    if(CacheExistNewData(Cache)) {
        *RdData = CacheStartAddr(Cache)[CacheRdIdx(Cache)];
        return stm32_true;
    }
    return stm32_false;
}

enum stm32_bool_e PopDataCacheBuff(struct DATA_CACHE* Cache, uint8_t* RdBuff, uint32_t dMaxBufLen)
{
    if(!CacheExistNewData(Cache)) {
        return stm32_false;
    }
    for(uint32_t i = 0; i < dMaxBufLen; i++) {
        if(CacheRdIdx(Cache) == CacheWrIdx(Cache)) {
            break;
        }
        RdBuff[i] = CacheStartAddr(Cache)[CacheRdIdx(Cache)];
        if(++CacheRdIdx(Cache) >= CacheMaxSz(Cache)) {
            CacheRdIdx(Cache) = 0;
        }
    }
    return stm32_true;
}

enum stm32_bool_e PushDataCacheBuff(struct DATA_CACHE* Cache, const uint8_t* WrBuff, uint32_t dMaxBufLen)
{
    for(uint32_t i = 0; i < dMaxBufLen; i++) {
        CacheStartAddr(Cache)[CacheWrIdx(Cache)] = WrBuff[i];
        if(++CacheWrIdx(Cache) >= CacheMaxSz(Cache)) {
            CacheWrIdx(Cache) = 0;
        }
    }
    return stm32_true;
}

enum stm32_bool_e FetchDataCacheBuff(struct DATA_CACHE* Cache, uint8_t* RdBuff, uint32_t dMaxBufLen)
{
    if(!CacheExistNewData(Cache)) {
        return stm32_false;
    }
    for(uint32_t i = 0; i < dMaxBufLen; i++) {
        if(CacheRdIdx(Cache) == CacheWrIdx(Cache)) {
            break;
        }
        RdBuff[i] = CacheStartAddr(Cache)[CacheRdIdx(Cache) + i];
    }
    return stm32_true;
}

uint32_t DataCacheRatio(struct DATA_CACHE* Cache)
{
    return (LoopCacheDataSz(Cache) * 100) / CacheMaxSz(Cache);
}

uint32_t DataCacheSize(struct DATA_CACHE* Cache)
{
    return LoopCacheDataSz(Cache);
}