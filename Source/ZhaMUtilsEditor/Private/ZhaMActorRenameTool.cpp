
#include "ZhaMActorRenameTool.h"
#include "Editor.h"
#include "Engine/Selection.h"
#include "GameFramework/Actor.h"


#include "SActorRenameDialog.h"
#include "ScopedTransaction.h"

void FZhaMActorRenameTool::RenameSelectedActors(const FString& from,const FString& to)
{
	USelection* SelectedActors = GEditor->GetSelectedActors();
	

	const FScopedTransaction Transaction(NSLOCTEXT("ZhaMUtils", "RenameActors", "批量重命名Actor"));

	for (FSelectionIterator It(*SelectedActors); It; ++It)
	{
		if (AActor* Actor = Cast<AActor>(*It))
		{
			FString OldLabel = Actor->GetActorLabel();
			if (OldLabel.Contains(*from))
			{
				FString NewLabel = OldLabel.Replace(*from,*to,ESearchCase::CaseSensitive);
				FActorLabelUtilities::SetActorLabelUnique(Actor, NewLabel);
				UE_LOG(LogTemp, Log, TEXT("Rename: %s → %s"), *OldLabel, *NewLabel);
			}
		}
	}
}

void FZhaMActorRenameTool::OpenActorRenameDialog()
{
	USelection* SelectedActors = GEditor->GetSelectedActors();
	if (!SelectedActors) return;
	FGlobalTabmanager::Get()->TryInvokeTab(
	FTabId("LevelEditor")  // 也可以用 FSlateApplication::PushMenu 方式
);

	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString(TEXT("批量重命名Actor")))
		.ClientSize(FVector2D(400, 200))
		.SupportsMinimize(false).SupportsMaximize(false)
		[
			SNew(SActorRenameDialog)
		];

	FSlateApplication::Get().AddWindow(Window);
}
