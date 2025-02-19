#ifndef NFC_RECIPE_H
#define NFC_RECIPE_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "NFC_handler.h"

typedef struct
{
  uint16_t IDofCell;
  char* IPAdress;
  size_t IPAdressLenght;
  uint8_t* ProcessTypes;
  size_t ProcessTypesLenght;
} CellInfo;

typedef struct
{
  uint16_t IDofCell;
  uint16_t IDofReservation;
  uint8_t ProcessType;
  float Price;
  UA_DateTime TimeOfReservation;
} Reservation;

enum ProcessTypes {
    ToStorageGlass,
    StorageAlcohol,
    StorageNonAlcohol,
    Shaker,
    Cleaner,
    SodaMake,
    ToCustomer,
    Transport,
    Buffer
};

enum AlcoholType {
    Vodka,
    Rum,
    Goralka
};

enum NonAlcoholType {
    Water,
    Cola
};
static const TRecipeStep EmptyRecipeStep = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
static const TRecipeInfo EmptyRecipeInfo= {
    0,0,0,0,0,0,0,0,0
};

enum StavovyAutomat
{
  State_Mimo_Polozena, // Sklenice se polozina na cteckou(default) //Written
  State_Mimo_NastaveniNaPresunDoSkladu,
  State_Inicializace_Podminky,     // Prvni cast inicializace
  State_Inicializace_ZiskaniAdres, // Ziskani adres od ResearchServeru
  State_Poptavka_Vyroba,
  State_Poptavka_Skladovani,
  State_Poptavka_Transporty,
  State_Poptavka_AktualniBunkaPrioritne,
  State_Rezervace,
  State_Transport,
  State_WaitUntilRemoved,
  State_Vyroba_Objeveni,
  State_Vyroba_OznameniOProvedeni,
  State_Vyroba_SpravneProvedeni,
  State_ZmizeniZeCtecky,
  State_KonecReceptu,
  State_NovyRecept,
  NouzovyStav
};



TRecipeStep GetRecipeStepByNumber(uint8_t aNumOfRecipe, uint16_t aParam);
TCardInfo GetCardInfoByNumber(uint8_t aNumOfRecipe);
TCardInfo SaveLocalsData(THandlerData* aHandlerData,TCardInfo aCardInfo);
uint8_t ChangeID(TCardInfo* aCardInfo,uint16_t aNewID);
CellInfo* GetCellInfoFromLDS(uint8_t aType,uint16_t* aNumberOfCells);
bool ChooseCell(uint8_t* aArrayOfProcess, size_t aArrayOfProcessSize, uint8_t* aArrayOfReqProcess, size_t aArrayOfReqProcessSize);
uint8_t DestroyCellInfoArray(CellInfo* aCellInfo,uint16_t aNumberOfCells);
uint8_t GetWinningCell(CellInfo* aCellInfo,uint16_t aNumberOfCells,uint16_t InterpreterID, uint8_t aProcessType,uint8_t param1, uint16_t param2,bool priority,Reservation* aReservation);
bool ExistType(CellInfo* aCellInfo,uint16_t aNumberOfCells, uint8_t aProcessType);
uint8_t AskForValidOffer(THandlerData* aHandlerData,uint16_t* aLastGoodReserved,CellInfo* aCellInfo,uint16_t aNumberOfCells);
uint8_t ReserveAllOfferedReservation(THandlerData *aHandlerData, CellInfo *aCellInfo, uint16_t aNumberOfCells,SemaphoreHandle_t* aSemaforHandlerNFC);
uint8_t AskForValidReservation(THandlerData* aHandlerData,bool process,CellInfo* aCellInfo,uint16_t aNumberOfCells);
uint8_t OcupancyCell(CellInfo* aCellInfo,uint16_t aNumberOfCells,uint16_t aActualCellID,bool Occupancy);
uint8_t DoReservation(THandlerData* aHandlerData,CellInfo* aCellInfo,uint16_t aNumberOfCells,bool process);
uint8_t IsDoneReservation(THandlerData* aHandlerData,CellInfo* aCellInfo,uint16_t aNumberOfCells,bool process);
char* GetRafName(uint8_t aRaf);
uint8_t AddRecipe(THandlerData *aHandlerData, TRecipeStep aRecipeStep, uint8_t aRecipeBefore, SemaphoreHandle_t *xSemaforNFC,bool First);
char* GetRafName(uint8_t aRaf);
uint8_t GetMinule(THandlerData *aHandlerData,uint8_t ActualID,uint8_t* PreviousID);
#ifdef __cplusplus
}
#endif

#endif //NFC_RECIPE_H