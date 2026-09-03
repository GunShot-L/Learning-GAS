// Copyright Linwenjie


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	check(AttributeInfo);
	// 将单个属性的变化分别绑定到各自的委托上
	UAuraAttributeSet* AS = Cast<UAuraAttributeSet>(AttributeSet);
	for (auto& Pari : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pari.Value()).AddLambda(
			[this, Pari](const FOnAttributeChangeData& Data)
			{
				BoardCastAttributeInfo(Pari.Key, Pari.Value());
			}	
		);
	}
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	// 初始化时向View广播所有属性
	UAuraAttributeSet* AS = Cast<UAuraAttributeSet>(AttributeSet);
	
	check(AttributeInfo);
	
	for (auto& Pari : AS->TagsToAttributes)
	{
		BoardCastAttributeInfo(Pari.Key, Pari.Value());
	}
}

void UAttributeMenuWidgetController::BoardCastAttributeInfo(const FGameplayTag& AttributeTag, 
	const FGameplayAttribute& Attribute) const
{
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
