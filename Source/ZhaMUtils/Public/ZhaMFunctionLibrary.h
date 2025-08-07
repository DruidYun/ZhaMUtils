#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ZhaMFunctionLibrary.generated.h"
/**ZhaM定义的星期几,映射EDayOfWeek*/
UENUM(BlueprintType)
enum class EZhaMDayOfWeek : uint8
{
	Monday     UMETA(DisplayName = "星期一"),
	Tuesday    UMETA(DisplayName = "星期二"),
	Wednesday  UMETA(DisplayName = "星期三"),
	Thursday   UMETA(DisplayName = "星期四"),
	Friday     UMETA(DisplayName = "星期五"),
	Saturday   UMETA(DisplayName = "星期六"),
	Sunday     UMETA(DisplayName = "星期日")
};
UCLASS()
class ZHAMUTILS_API UZhaMFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 将EDayOfWeek映射为EZhaMDayOfWeek*/
	static EZhaMDayOfWeek ConvertToZhaMDayOfWeek(EDayOfWeek UEWeekday);
	/** 验证手机号（中国大陆） */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|验证", DisplayName="验证中国大陆手机号")
	static bool IsValidChinesePhoneNumber(const FString& PhoneNumber);

	/** 验证身份证号（18位，中国大陆） */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|验证", DisplayName="验证18位身份证号")
	static bool IsValidChineseIDNumber(const FString& IDNumber);

	/// 将类似"1,2,3,4"的是字符串转换为整型数组
	/// @param InputString 由逗号隔开的有很多整数元素的字符串
	/// @return 整型数组
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|字符串", DisplayName="解析逗号分隔的整数字符串")
	static TArray<int32> ParseCommaSeparatedInts(const FString& InputString);

	/// 将整型数组修改为浮点数组
	/// @param IntArray 要修改的整型数组
	/// @return 修改后的浮点数组
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|数组", DisplayName="整型数组转浮点数组")
	static TArray<float> ConvertIntArrayToFloatArray(const TArray<int32>& IntArray);

	/** 获取今天日期（格式：YYYY-MM-DD） */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|时间日期", DisplayName="获取今天日期")
	static FString GetTodayDate();

	/** 获取下个月第一天的日期 */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|时间日期", DisplayName="获取下月第一天日期")
	static FString GetFirstDayOfNextMonth();

	/** 获取上个月第一天的日期 */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|时间日期", DisplayName="获取上月第一天日期")
	static FString GetFirstDayOfLastMonth();

	/** 获取与今天相隔N天的日期（N可正可负） */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|时间日期", DisplayName="获取与今天相隔N天的日期")
	static FString GetDateNDaysFromToday(int32 DaysOffset);

	/** 获取今年第一天的日期 */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|时间日期", DisplayName="获取今年第一天日期")
	static FString GetFirstDayOfThisYear();

	/** 获取去年第一天的日期 */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|时间日期", DisplayName="获取去年第一天日期")
	static FString GetFirstDayOfLastYear();

	/** 获取明年第一天的日期 */
	UFUNCTION(BlueprintPure, Category="ZhaMUtils|时间日期", DisplayName="获取明年第一天日期")
	static FString GetFirstDayOfNextYear();
	/// 获取某天的星期索引
	/// @param DateString 输入YY-MM-DD格式日期字符串
	/// @return 返回整数 0是星期一 6是星期日
	UFUNCTION(BlueprintPure, Category = "ZhaMUtils|时间日期", DisplayName = "获取星期索引")
	static int32 GetDayOfWeekIndex(const FString& DateString);
	/// 获取某天是星期几
	/// @param DateString 输入YY-MM-DD格式日期字符串
	/// @param bSuccess 返回格式日期字符串是否正确
	/// @return 返回星期一到星期日的枚举
	UFUNCTION(BlueprintPure, Category = "ZhaMUtils|时间日期", DisplayName = "获取星期几")
	static  EZhaMDayOfWeek GetDayOfWeek(const FString& DateString,bool& bSuccess);
	
	UFUNCTION(BlueprintPure, Category = "ZhaMUtils|时间", DisplayName = "时间转字符串（HH:mm:ss）")
	static FString FormatTimespanToString(const FTimespan& Time);
	
	UFUNCTION(BlueprintPure, Category = "ZhaMUtils|时间", DisplayName = "获取最小时间（00:00:00）")
	static FTimespan GetMinTimeOfDay();
	
	UFUNCTION(BlueprintPure, Category = "ZhaMUtils|时间", DisplayName = "获取最大时间（23:59:59）")
	static FTimespan GetMaxTimeOfDay();

};

