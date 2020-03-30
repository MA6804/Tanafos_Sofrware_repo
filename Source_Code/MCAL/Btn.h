#ifndef BTN_H
#define BTN_H
typedef enum {BUT_OFF, BUT_ON, BUT_PRSSED, BUT_RELEASED} BtnStateType;
typedef struct 
{
	unsigned char DioGroupId;
	unsigned char BtnActiveState;
}BtnConfigType;
void BTN_Init(void);
void BTN_GetState(BtnStateType *BtnStatePtr, unsigned char BtnId);
void BTN_Manager(void);

#endif