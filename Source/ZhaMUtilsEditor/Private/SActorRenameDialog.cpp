// SActorRenameDialog.cpp

#include "SActorRenameDialog.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Editor.h"
#include "ZhaMActorRenameTool.h"

void SActorRenameDialog::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SVerticalBox)

		+ SVerticalBox::Slot().AutoHeight().Padding(5)
		[
			SNew(STextBlock).Text(FText::FromString(TEXT("替换前字符")))
		]

		+ SVerticalBox::Slot().AutoHeight().Padding(5)
		[
			SNew(SEditableTextBox)
			.Text_Lambda([this]() { return SearchText; })
			.OnTextChanged_Lambda([this](const FText& NewText) { SearchText = NewText; })
		]

		+ SVerticalBox::Slot().AutoHeight().Padding(5)
		[
			SNew(STextBlock).Text(FText::FromString(TEXT("替换后字符")))
		]

		+ SVerticalBox::Slot().AutoHeight().Padding(5)
		[
			SNew(SEditableTextBox)
			.Text_Lambda([this]() { return ReplaceText; })
			.OnTextChanged_Lambda([this](const FText& NewText) { ReplaceText = NewText; })
		]

		+ SVerticalBox::Slot().AutoHeight().Padding(10)
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("确认替换")))
			.OnClicked(this, &SActorRenameDialog::OnConfirmClicked)
		]
	];
}

FReply SActorRenameDialog::OnConfirmClicked()
{
	const FString From = SearchText.ToString();
	const FString To = ReplaceText.ToString();
	FZhaMActorRenameTool::RenameSelectedActors(From, To);

	return FReply::Handled();
}
