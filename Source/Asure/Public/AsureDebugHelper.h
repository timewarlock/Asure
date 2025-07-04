#pragma once


namespace Debug


{
	static void print(const FString& message, const FColor& Color = FColor::MakeRandomColor(),
		int32 Inkey = -1)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Inkey, 7.f, Color, message);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *message);
		}
	}
}
