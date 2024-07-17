#pragma once

UENUM(BlueprintType)
enum class PlayerWeaponState : uint8
{
	PWS_Unequipped UMETA(DisplayName = "Unequipped"),
	PWS_Equipped UMETA(DisplayName = "Equipped")

};
