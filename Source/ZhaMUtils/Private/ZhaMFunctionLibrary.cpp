#include "ZhaMFunctionLibrary.h"
#include "Engine/Engine.h"

void UZhaMFunctionLibrary::PrintLog(const FString& Message, float Duration)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, Duration, FColor::Green, Message);
	}
}

int32 UZhaMFunctionLibrary::AddInts(int32 A, int32 B)
{
	return A + B;
}
