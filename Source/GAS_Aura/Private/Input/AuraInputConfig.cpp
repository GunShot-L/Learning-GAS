// Copyright Linwenjie


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	bool bLogNotFound) const
{
	for (const FAuraInputAction& AuraInputAction : AbilityInputActions)
	{
		if (AuraInputAction.InputAction && AuraInputAction.InputTag == InputTag)
		{
			return AuraInputAction.InputAction;
		}
	}
	
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("The InputAction for Tag: %s Not Found!"), *InputTag.ToString());
	}
	
	return nullptr;
	
}
