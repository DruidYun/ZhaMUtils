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

	/** 验证手机号（中国大陆） */
	UFUNCTION(BlueprintPure, Category = "ZhaMUtils|Validation")
	static bool IsValidChinesePhoneNumber(const FString& PhoneNumber);

	/** 验证身份证号（18位，中国大陆） */
	UFUNCTION(BlueprintPure, Category = "ZhaMUtils|Validation")
	static bool IsValidChineseIDNumber(const FString& IDNumber);
};
