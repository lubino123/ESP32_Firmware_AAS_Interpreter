/* ==========================================
    NFC_reader - Knihovna na synchronizaci dat pro zapis do NFC Čipu
    Copyright (c) 2023 Luboš Chmelař
    [Licence]
========================================== */
#ifndef NFC_HANDLER_H
#define NFC_HANDLER_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "NFC_reader.h"
#include <stddef.h>
  typedef struct
    {
      pn532_t sNFC;
      TCardInfo sIntegrityCardInfo;
      TCardInfo sWorkingCardInfo;
      size_t sRecipeStepIndexArraySize;
      bool* sRecipeStepIndexArray;
    } THandlerData;


uint8_t NFC_Handler_Init(THandlerData* aHandlerData);
uint8_t NFC_Handler_SetUp(THandlerData* aHandlerData,pn532_t sNFC);
uint8_t NFC_Handler_IsSameData(THandlerData* aHandlerData,TRecipeInfo* aRecipeInfo);
uint8_t NFC_Handler_LoadData(THandlerData* aHandlerData);
uint8_t NFC_Handler_ResizeIndexArray(THandlerData* aHandlerData,size_t aNewSize);
uint8_t NFC_Handler_Dealoc(THandlerData* aHandlerData);
uint8_t NFC_Handler_CopyToWorking(THandlerData* aHandlerData,bool InfoData,bool StepsData);
uint8_t NFC_Handler_AddIndex(THandlerData* aHandlerData,size_t aIndex);
uint8_t NFC_Handler_RemoveIndex(THandlerData* aHandlerData,size_t aIndex);
uint8_t NFC_Handler_GetRecipeInfo(THandlerData* aHandlerData,TRecipeInfo *  aRecipeInfo);
uint8_t NFC_Handler_GetRecipeStep(THandlerData* aHandlerData,TRecipeStep *  aRecipeStep, size_t aIndex);
uint8_t NFC_Handler_WriteStep(THandlerData* aHandlerData,TRecipeStep *  aRecipeStep, size_t aIndex);
uint8_t NFC_Handler_WriteInfo(THandlerData* aHandlerData,TRecipeInfo* aRecipeInfo);
uint8_t NFC_Handler_Sync(THandlerData* aHandlerData);
uint8_t NFC_Handler_WriteSafeInfo(THandlerData* aHandlerData,TRecipeInfo* aRecipeInfo);
uint8_t NFC_Handler_WriteSafeStep(THandlerData* aHandlerData,TRecipeStep* aRecipeStep, size_t aIndex);
uint8_t NFC_Handler_AddCardInfoToWorking(THandlerData* aHandlerData,TCardInfo aCardInfo);
uint8_t WorkingPrintPointers(THandlerData* aHandlerData);



/*uint8_t NFC_Handler_Load(THandlerData* aHandlerData);
uint8_t NFC_Handler_Write(THandlerData *aHandlerData, TRecipeStep aData, size_t aIndex,bool aCheckForIncluded);
uint8_t NFC_Handler_Sync(THandlerData* aHandlerData);
uint8_t NFC_Handler_WriteSafe(THandlerData* aHandlerData,TRecipeStep aData, size_t aIndex);
uint8_t NFC_Handler_GetStructFromSafeData(THandlerData* aHandlerData,TRecipeStep* aData, size_t aIndex);
uint8_t NFC_Handler_GetStructFromSafeDataAll(THandlerData* aHandlerData,TRecipeStep* aData);
uint8_t NFC_Handler_Destroy(THandlerData* aHandlerData);*/















#ifdef __cplusplus
}
#endif

#endif //NFC_HANDLER_H