#include "ZhaMFunctionLibrary.h"
#include "Engine/Engine.h"

EZhaMDayOfWeek UZhaMFunctionLibrary::ConvertToZhaMDayOfWeek(EDayOfWeek UEWeekday)
{
	switch (UEWeekday)
	{
	case EDayOfWeek::Monday:    return EZhaMDayOfWeek::Monday;
	case EDayOfWeek::Tuesday:   return EZhaMDayOfWeek::Tuesday;
	case EDayOfWeek::Wednesday: return EZhaMDayOfWeek::Wednesday;
	case EDayOfWeek::Thursday:  return EZhaMDayOfWeek::Thursday;
	case EDayOfWeek::Friday:    return EZhaMDayOfWeek::Friday;
	case EDayOfWeek::Saturday:  return EZhaMDayOfWeek::Saturday;
	case EDayOfWeek::Sunday:    return EZhaMDayOfWeek::Sunday;
	default:                    return EZhaMDayOfWeek::Sunday;
	}
}
bool UZhaMFunctionLibrary::IsValidChinesePhoneNumber(const FString& PhoneNumber)
{
	const FRegexPattern Pattern(TEXT("^1[3-9]\\d{9}$"));
	FRegexMatcher Matcher(Pattern, PhoneNumber);
	return Matcher.FindNext();
}

bool UZhaMFunctionLibrary::IsValidChineseIDNumber(const FString& IDNumber)
{
	if (IDNumber.Len() != 18)
		return false;

	const FRegexPattern Pattern(TEXT("^[1-9]\\d{5}(19|20)\\d{2}(0[1-9]|1[0-2])"
									 "(0[1-9]|[12]\\d|3[01])\\d{3}[0-9Xx]$"));
	FRegexMatcher Matcher(Pattern, IDNumber);

	if (!Matcher.FindNext())
		return false;

	static const int32 Weights[17] = {7, 9, 10, 5, 8, 4, 2,
									  1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	static const TCHAR CheckCodes[11] = {'1', '0', 'X', '9', '8',
										 '7', '6', '5', '4', '3', '2'};

	int32 Sum = 0;
	for (int32 i = 0; i < 17; i++)
	{
		if (!FChar::IsDigit(IDNumber[i]))
			return false;

		int32 Digit = IDNumber[i] - '0';
		Sum += Digit * Weights[i];
	}

	int32 Mod = Sum % 11;
	TCHAR ExpectedCheckCode = CheckCodes[Mod];
	TCHAR LastChar = FChar::ToUpper(IDNumber[17]);

	return LastChar == ExpectedCheckCode;
}

TArray<int32> UZhaMFunctionLibrary::ParseCommaSeparatedInts(const FString& InputString)
{
	TArray<FString> SplitStrings;
	TArray<int32> Result;

	// 将字符串按 , 拆分
	InputString.ParseIntoArray(SplitStrings, TEXT(","), true);

	for (const FString& Str : SplitStrings)
	{
		// 清除可能的空格后转换为 int
		FString TrimmedStr = Str.TrimStartAndEnd();
		int32 Value = FCString::Atoi(*TrimmedStr);
		Result.Add(Value);
	}

	return Result;
}
TArray<float> UZhaMFunctionLibrary::ConvertIntArrayToFloatArray(const TArray<int32>& IntArray)
{
	TArray<float> FloatArray;
	FloatArray.Reserve(IntArray.Num());

	for (int32 Value : IntArray)
	{
		FloatArray.Add(static_cast<float>(Value));
	}
	return FloatArray;
	
	
}
FString FormatDate(const FDateTime& Date)
{
	return Date.ToString(TEXT("%Y-%m-%d"));
}

FString UZhaMFunctionLibrary::GetTodayDate()
{
	FDateTime Now = FDateTime::Now();
	return FormatDate(Now);
}

FString UZhaMFunctionLibrary::GetFirstDayOfNextMonth()
{
	FDateTime Now = FDateTime::Now();
	int32 Year = Now.GetYear();
	int32 Month = Now.GetMonth() + 1;
	if (Month > 12)
	{
		Month = 1;
		Year++;
	}
	return FormatDate(FDateTime(Year, Month, 1));
}

FString UZhaMFunctionLibrary::GetFirstDayOfLastMonth()
{
	FDateTime Now = FDateTime::Now();
	int32 Year = Now.GetYear();
	int32 Month = Now.GetMonth() - 1;
	if (Month < 1)
	{
		Month = 12;
		Year--;
	}
	return FormatDate(FDateTime(Year, Month, 1));
}

FString UZhaMFunctionLibrary::GetDateNDaysFromToday(int32 DaysOffset)
{
	FDateTime Now = FDateTime::Now();
	FDateTime TargetDate = Now + FTimespan(DaysOffset, 0, 0, 0);
	return FormatDate(TargetDate);
}

FString UZhaMFunctionLibrary::GetFirstDayOfThisYear()
{
	int32 Year = FDateTime::Now().GetYear();
	return FormatDate(FDateTime(Year, 1, 1));
}

FString UZhaMFunctionLibrary::GetFirstDayOfLastYear()
{
	int32 Year = FDateTime::Now().GetYear() - 1;
	return FormatDate(FDateTime(Year, 1, 1));
}

FString UZhaMFunctionLibrary::GetFirstDayOfNextYear()
{
	int32 Year = FDateTime::Now().GetYear() + 1;
	return FormatDate(FDateTime(Year, 1, 1));
}
int32 UZhaMFunctionLibrary::GetDayOfWeekIndex(const FString& DateString)
{
	FDateTime Date;
	// 拼接默认时间，使字符串能被正确解析
	if (!FDateTime::Parse(DateString + TEXT(" 00:00:00.000000"), Date))
	{
		return -1;  // 解析失败
	}
	
	// Monday=0, Sunday=6
	EDayOfWeek DayOfWeek = Date.GetDayOfWeek();

	// 转换为 int32（Monday=0 到 Sunday=6）
	return static_cast<int32>(DayOfWeek);
	
}

EZhaMDayOfWeek UZhaMFunctionLibrary::GetDayOfWeek(const FString& DateString,bool& bSuccess)
{
	FDateTime Date;
	// 拼接默认时间，使字符串能被正确解析
	if (!FDateTime::Parse(DateString + TEXT(" 00:00:00.000000"), Date))
	{
		bSuccess=false;
		return EZhaMDayOfWeek::Monday;  // 解析失败
	}
	
	EDayOfWeek DayOfWeek = Date.GetDayOfWeek();
	bSuccess=true;
	return ConvertToZhaMDayOfWeek(DayOfWeek);
	
}
FString UZhaMFunctionLibrary::FormatTimespanToString(const FTimespan& Time)
{
	int32 Hours = Time.GetHours();
	int32 Minutes = Time.GetMinutes();
	int32 Seconds = Time.GetSeconds();

	return FString::Printf(TEXT("%02d:%02d:%02d"), Hours, Minutes, Seconds);
}
FTimespan UZhaMFunctionLibrary::GetMinTimeOfDay()
{
	return FTimespan(0, 0, 0); // 00:00:00
}
FTimespan UZhaMFunctionLibrary::GetMaxTimeOfDay()
{
	return FTimespan( 23, 59, 59); // 23:59:59
}

