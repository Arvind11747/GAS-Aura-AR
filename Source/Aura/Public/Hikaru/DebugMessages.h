#pragma once

#include "Engine/GameEngine.h"
/*----------------------------------------------------Section 1--------------------------------------------------------*/
//PRINTs a Single Message
#define PRINT(Text) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT(Text),false);}
//ex: PRINT("Hello");
#define PRINT_C(Text, Color) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 10.0f, Color, TEXT(Text),false);}
//PRINTc("Hello", FColor::Black);
/*----------------------------------------------------Section 2--------------------------------------------------------*/
//PRINTs a Single Message using key method
#define PRINT_K(Key, Text) if(GEngine){GEngine->AddOnScreenDebugMessage(Key, 10.0f, FColor::Yellow, TEXT(Text));}
#define PRINT_KC(Key, Text, Color) if(GEngine){GEngine->AddOnScreenDebugMessage(Key, 10.0f, Color, TEXT(Text));}
//-------------//
//we can use -1, 1 and 2 for the keys, check examples below.
//1 to replace the new data, avoid filling the screen.
//-1 to not replace, fil the screen in the up direction.
//2 to replace the new data, avoid filling the screen. (still need to practice)
//-------------//
//ex:PRINTk(1, "Hello 1");
//ex:PRINTk(-1, "Hello 2");
//ex:PRINTk(2, "Hello 3");
/*----------------------------------------------------Section 3--------------------------------------------------------*/
//PRINTs Variables Data
#define PRINT_F(Format, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::PRINTf(TEXT(Format), ##__VA_ARGS__), false);}
// %f = float value
// %d = int value
// %s = string value
//float pi = 3.14f;
//int32 a = 5;
//FString s(TEXT("ANONYMOUS"));
//ex: PRINTf("Calling PRINTf with the value: %f", pi); //PRINTing a value from a single variable.
//ex: PRINTf("Calling PRINTf with the values: %f, %d, %s", pi, a, *s ); //PRINTing values from multiple variables.
/*----------------------------------------------------Section 3--------------------------------------------------------*/
//PRINTs Variables Data using key method
#define PRINT_KF(Key, Format, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(Key, 10.0f, FColor::Yellow, FString::PRINTf(TEXT(Format), ##__VA_ARGS__));}
//-------------//
//we can use -1, 1 and 2 for the keys, check examples below.
//1 to replace the new data, avoid filling the screen.
//-1 to not replace, fil the screen in the up direction.
//2 to replace the new data, avoid filling the screen. (still need to practice)
//-------------//
// %f = float value
// %d = int value
// %s = string value
//float pi = 3.14f;
//int32 a = 5;
//FString s(TEXT("ANONYMOUS"));
//ex: PRINTfk(1, "Calling PRINTf with the value: %f", pi); //PRINTing a value from a single variable.
//ex: PRINTfk(1, "Calling PRINTf with the values: %f, %d, %s", pi, a, *s ); //PRINTing values from multiple variables.
//ex: PRINTfk(-1, "Calling PRINTf with the value: %f", pi); //PRINTing a value from a single variable.
//ex: PRINTfk(-1, "Calling PRINTf with the values: %f, %d, %s", pi, a, *s ); //PRINTing values from multiple variables.
//ex: PRINTfk(2, "Calling PRINTf with the value: %f", pi); //PRINTing a value from a single variable.
//ex: PRINTfk(2, "Calling PRINTf with the values: %f, %d, %s", pi, a, *s ); //PRINTing values from multiple variables.
/*----------------------------------------------------Section 3--------------------------------------------------------*/
