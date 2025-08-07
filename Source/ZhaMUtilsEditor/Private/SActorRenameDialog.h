// SActorRenameDialog.h
#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SActorRenameDialog : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SActorRenameDialog) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	FText SearchText;
	FText ReplaceText;

	FReply OnConfirmClicked();
};
