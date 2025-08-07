#include "ZhaMFunctionLibrary.h"
#include "Engine/Engine.h"

void UZhaMFunctionLibrary::PrintLog(const FString& Message, float Duration)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, Duration, FColor::Green, Message);
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
