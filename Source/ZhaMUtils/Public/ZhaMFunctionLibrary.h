#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ZhaMFunctionLibrary.generated.h"

UCLASS()
class ZHAMUTILS_API UZhaMFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/** 打印一条绿色调试信息 */
	UFUNCTION(BlueprintCallable, Category="ZhaMUtils|Debug")
	static void PrintLog(const FString& Message, float Duration = 2.0f);

	/** 计算两个数的和 */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|Math")
	static int32 AddInts(int32 A, int32 B);
};
