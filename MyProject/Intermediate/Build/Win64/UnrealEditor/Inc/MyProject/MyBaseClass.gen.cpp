// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/MyBaseClass.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyBaseClass() {}
// Cross Module References
	MYPROJECT_API UEnum* Z_Construct_UEnum_MyProject_CharacterStates();
	UPackage* Z_Construct_UPackage__Script_MyProject();
	MYPROJECT_API UClass* Z_Construct_UClass_AMyBaseClass_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_AMyBaseClass();
	NINJACHARACTER_API UClass* Z_Construct_UClass_ANinjaCharacter();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTimelineComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UFunction* Z_Construct_UDelegateFunction_Engine_OnTimelineFloat__DelegateSignature();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_UNitroHealthComponent_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_CharacterStates;
	static UEnum* CharacterStates_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_CharacterStates.OuterSingleton)
		{
			Z_Registration_Info_UEnum_CharacterStates.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MyProject_CharacterStates, Z_Construct_UPackage__Script_MyProject(), TEXT("CharacterStates"));
		}
		return Z_Registration_Info_UEnum_CharacterStates.OuterSingleton;
	}
	template<> MYPROJECT_API UEnum* StaticEnum<CharacterStates>()
	{
		return CharacterStates_StaticEnum();
	}
	struct Z_Construct_UEnum_MyProject_CharacterStates_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_MyProject_CharacterStates_Statics::Enumerators[] = {
		{ "CharacterStates::Walking", (int64)CharacterStates::Walking },
		{ "CharacterStates::Jumping", (int64)CharacterStates::Jumping },
		{ "CharacterStates::Bouncing", (int64)CharacterStates::Bouncing },
		{ "CharacterStates::Stomping", (int64)CharacterStates::Stomping },
		{ "CharacterStates::Spindashing", (int64)CharacterStates::Spindashing },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_MyProject_CharacterStates_Statics::Enum_MetaDataParams[] = {
		{ "Bouncing.Name", "CharacterStates::Bouncing" },
		{ "Comment", "//Unused enum states\n" },
		{ "Jumping.Name", "CharacterStates::Jumping" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "Spindashing.Name", "CharacterStates::Spindashing" },
		{ "Stomping.Name", "CharacterStates::Stomping" },
		{ "ToolTip", "Unused enum states" },
		{ "Walking.Name", "CharacterStates::Walking" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MyProject_CharacterStates_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_MyProject,
		nullptr,
		"CharacterStates",
		"CharacterStates",
		Z_Construct_UEnum_MyProject_CharacterStates_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_MyProject_CharacterStates_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_MyProject_CharacterStates_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_MyProject_CharacterStates_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_MyProject_CharacterStates()
	{
		if (!Z_Registration_Info_UEnum_CharacterStates.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_CharacterStates.InnerSingleton, Z_Construct_UEnum_MyProject_CharacterStates_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_CharacterStates.InnerSingleton;
	}
	DEFINE_FUNCTION(AMyBaseClass::execTimelineTick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TimelineTick();
		P_NATIVE_END;
	}
	void AMyBaseClass::StaticRegisterNativesAMyBaseClass()
	{
		UClass* Class = AMyBaseClass::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TimelineTick", &AMyBaseClass::execTimelineTick },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyBaseClass_TimelineTick_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyBaseClass_TimelineTick_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Timeline functions that are required for homing attack to work\n" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "Timeline functions that are required for homing attack to work" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyBaseClass_TimelineTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyBaseClass, nullptr, "TimelineTick", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyBaseClass_TimelineTick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyBaseClass_TimelineTick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyBaseClass_TimelineTick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyBaseClass_TimelineTick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyBaseClass);
	UClass* Z_Construct_UClass_AMyBaseClass_NoRegister()
	{
		return AMyBaseClass::StaticClass();
	}
	struct Z_Construct_UClass_AMyBaseClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpBallMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpBallMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnRateGamepad_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnRateGamepad;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChargingSpindash_MetaData[];
#endif
		static void NewProp_ChargingSpindash_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ChargingSpindash;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pushForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pushForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_stompForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_stompForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_jumpDashForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_jumpDashForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bounceForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_bounceForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinSpindashForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinSpindashForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxSpindashForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSpindashForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSpindashForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentSpindashForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GroundAngle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundAngle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OldTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OldTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChosenTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChosenTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MainTimeline_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MainTimeline;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FloatCurve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FloatCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActorLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ActorLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TLMovementValue_MetaData[];
#endif
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_TLMovementValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RingCount_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_RingCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CanBounce_MetaData[];
#endif
		static void NewProp_CanBounce_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_CanBounce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsJumping_MetaData[];
#endif
		static void NewProp_bIsJumping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsJumping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsJumpDashing_MetaData[];
#endif
		static void NewProp_bIsJumpDashing_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsJumpDashing;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsStomping_MetaData[];
#endif
		static void NewProp_bIsStomping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsStomping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsGrounded_MetaData[];
#endif
		static void NewProp_bIsGrounded_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsGrounded;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsHomingAttacking_MetaData[];
#endif
		static void NewProp_bIsHomingAttacking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHomingAttacking;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsBouncing_MetaData[];
#endif
		static void NewProp_bIsBouncing_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsBouncing;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsAutomated_MetaData[];
#endif
		static void NewProp_bIsAutomated_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAutomated;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StompAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StompAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BounceAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BounceAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpindashAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpindashAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RestartAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RestartAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PauseAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PauseAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpSFX_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpSFX;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpDashSFX_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpDashSFX;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChargeSpinDashSFX_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChargeSpinDashSFX;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReleaseSpinDashSFX_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReleaseSpinDashSFX;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StompSFX_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StompSFX;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PauseMenuWidget_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_PauseMenuWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MyWidgetInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MyWidgetInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealthComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyBaseClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANinjaCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyBaseClass_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyBaseClass_TimelineTick, "TimelineTick" }, // 2482431242
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyBaseClass.h" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Follow camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpBallMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpBallMesh = { "JumpBallMesh", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, JumpBallMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpBallMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpBallMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TurnRateGamepad_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TurnRateGamepad = { "TurnRateGamepad", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, TurnRateGamepad), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TurnRateGamepad_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TurnRateGamepad_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_speed_MetaData[] = {
		{ "Category", "Speed related stuff" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_speed = { "speed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, speed), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_speed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargingSpindash_MetaData[] = {
		{ "Category", "Spindash stuff" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargingSpindash_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->ChargingSpindash = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargingSpindash = { "ChargingSpindash", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargingSpindash_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargingSpindash_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargingSpindash_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce_MetaData[] = {
		{ "Category", "Forces" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce = { "pushForce", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, pushForce), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_stompForce_MetaData[] = {
		{ "Category", "Forces" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_stompForce = { "stompForce", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, stompForce), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_stompForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_stompForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_jumpDashForce_MetaData[] = {
		{ "Category", "Forces" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_jumpDashForce = { "jumpDashForce", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, jumpDashForce), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_jumpDashForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_jumpDashForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bounceForce_MetaData[] = {
		{ "Category", "Forces" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bounceForce = { "bounceForce", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, bounceForce), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bounceForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bounceForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MinSpindashForce_MetaData[] = {
		{ "Category", "Forces" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MinSpindashForce = { "MinSpindashForce", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, MinSpindashForce), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MinSpindashForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MinSpindashForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MaxSpindashForce_MetaData[] = {
		{ "Category", "Forces" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MaxSpindashForce = { "MaxSpindashForce", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, MaxSpindashForce), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MaxSpindashForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MaxSpindashForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentSpindashForce_MetaData[] = {
		{ "Category", "Forces" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentSpindashForce = { "CurrentSpindashForce", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, CurrentSpindashForce), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentSpindashForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentSpindashForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_GroundAngle_MetaData[] = {
		{ "Category", "Slope Physics" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_GroundAngle = { "GroundAngle", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, GroundAngle), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_GroundAngle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_GroundAngle_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_OldTarget_MetaData[] = {
		{ "Category", "Homing Attack" },
		{ "Comment", "// These don't get noticed by the blueprints if they're not spread out\n" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "These don't get noticed by the blueprints if they're not spread out" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_OldTarget = { "OldTarget", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, OldTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_OldTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_OldTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget_MetaData[] = {
		{ "Category", "Homing Attack" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget = { "CurrentTarget", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, CurrentTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget_MetaData[] = {
		{ "Category", "Homing Attack" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget = { "ChosenTarget", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, ChosenTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline_MetaData[] = {
		{ "Category", "TimelineShit" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline = { "MainTimeline", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, MainTimeline), Z_Construct_UClass_UTimelineComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FloatCurve_MetaData[] = {
		{ "Category", "TimelineShit" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FloatCurve = { "FloatCurve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, FloatCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FloatCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FloatCurve_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ActorLocation_MetaData[] = {
		{ "Category", "TimelineShit" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ActorLocation = { "ActorLocation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, ActorLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ActorLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ActorLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TLMovementValue_MetaData[] = {
		{ "Category", "TimelineShit" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TLMovementValue = { "TLMovementValue", nullptr, (EPropertyFlags)0x0010000000080014, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, TLMovementValue), Z_Construct_UDelegateFunction_Engine_OnTimelineFloat__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TLMovementValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TLMovementValue_MetaData)) }; // 1025672532
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount_MetaData[] = {
		{ "Category", "Rings" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount = { "RingCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, RingCount), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CanBounce_MetaData[] = {
		{ "Category", "Bounce Stuff" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CanBounce_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->CanBounce = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CanBounce = { "CanBounce", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CanBounce_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CanBounce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CanBounce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumping_MetaData[] = {
		{ "Category", "State bools" },
		{ "Comment", "// These are most likely gonna be replaced by enums later. - Ersan 04.03.2024\n" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "These are most likely gonna be replaced by enums later. - Ersan 04.03.2024" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumping_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->bIsJumping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumping = { "bIsJumping", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumping_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumpDashing_MetaData[] = {
		{ "Category", "State bools" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumpDashing_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->bIsJumpDashing = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumpDashing = { "bIsJumpDashing", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumpDashing_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumpDashing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumpDashing_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsStomping_MetaData[] = {
		{ "Category", "State bools" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsStomping_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->bIsStomping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsStomping = { "bIsStomping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsStomping_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsStomping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsStomping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_MetaData[] = {
		{ "Category", "State bools" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->bIsGrounded = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded = { "bIsGrounded", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsHomingAttacking_MetaData[] = {
		{ "Category", "State bools" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsHomingAttacking_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->bIsHomingAttacking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsHomingAttacking = { "bIsHomingAttacking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsHomingAttacking_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsHomingAttacking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsHomingAttacking_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsBouncing_MetaData[] = {
		{ "Category", "State bools" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsBouncing_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->bIsBouncing = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsBouncing = { "bIsBouncing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsBouncing_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsBouncing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsBouncing_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsAutomated_MetaData[] = {
		{ "Category", "State bools" },
		{ "Comment", "//This is currently unused cuz I couldn't figure out how to reset it\n" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "This is currently unused cuz I couldn't figure out how to reset it" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsAutomated_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->bIsAutomated = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsAutomated = { "bIsAutomated", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsAutomated_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsAutomated_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsAutomated_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentState_MetaData[] = {
		{ "Category", "UNUSED | Character State" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, CurrentState), Z_Construct_UEnum_MyProject_CharacterStates, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentState_MetaData)) }; // 2683037699
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Inputs" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_InputMappingContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_InputMappingContext_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_LookAction_MetaData[] = {
		{ "Category", "Actions" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_LookAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_LookAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MoveAction_MetaData[] = {
		{ "Category", "Actions" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MoveAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MoveAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpAction_MetaData[] = {
		{ "Category", "Actions" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompAction_MetaData[] = {
		{ "Category", "Actions" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompAction = { "StompAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, StompAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BounceAction_MetaData[] = {
		{ "Category", "Actions" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BounceAction = { "BounceAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, BounceAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BounceAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BounceAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_SpindashAction_MetaData[] = {
		{ "Category", "Actions" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_SpindashAction = { "SpindashAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, SpindashAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_SpindashAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_SpindashAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RestartAction_MetaData[] = {
		{ "Category", "Actions" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RestartAction = { "RestartAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, RestartAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RestartAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RestartAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseAction_MetaData[] = {
		{ "Category", "Actions" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseAction = { "PauseAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, PauseAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpSFX_MetaData[] = {
		{ "Category", "SoundFX" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpSFX = { "JumpSFX", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, JumpSFX), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpSFX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpSFX_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpDashSFX_MetaData[] = {
		{ "Category", "SoundFX" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpDashSFX = { "JumpDashSFX", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, JumpDashSFX), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpDashSFX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpDashSFX_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargeSpinDashSFX_MetaData[] = {
		{ "Category", "SoundFX" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargeSpinDashSFX = { "ChargeSpinDashSFX", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, ChargeSpinDashSFX), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargeSpinDashSFX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargeSpinDashSFX_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ReleaseSpinDashSFX_MetaData[] = {
		{ "Category", "SoundFX" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ReleaseSpinDashSFX = { "ReleaseSpinDashSFX", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, ReleaseSpinDashSFX), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ReleaseSpinDashSFX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ReleaseSpinDashSFX_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompSFX_MetaData[] = {
		{ "Category", "SoundFX" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompSFX = { "StompSFX", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, StompSFX), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompSFX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompSFX_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseMenuWidget_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseMenuWidget = { "PauseMenuWidget", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, PauseMenuWidget), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseMenuWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseMenuWidget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MyWidgetInstance_MetaData[] = {
		{ "Comment", "//This is required to create the widget\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "This is required to create the widget" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MyWidgetInstance = { "MyWidgetInstance", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, MyWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MyWidgetInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MyWidgetInstance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_HealthComponent_MetaData[] = {
		{ "Category", "Health Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_HealthComponent = { "HealthComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, HealthComponent), Z_Construct_UClass_UNitroHealthComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_HealthComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_HealthComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyBaseClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpBallMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TurnRateGamepad,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargingSpindash,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_stompForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_jumpDashForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bounceForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MinSpindashForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MaxSpindashForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentSpindashForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_GroundAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_OldTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FloatCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ActorLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TLMovementValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CanBounce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsJumpDashing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsStomping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsHomingAttacking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsBouncing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsAutomated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_InputMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BounceAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_SpindashAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RestartAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpSFX,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_JumpDashSFX,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChargeSpinDashSFX,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ReleaseSpinDashSFX,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_StompSFX,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_PauseMenuWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MyWidgetInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_HealthComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyBaseClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyBaseClass>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyBaseClass_Statics::ClassParams = {
		&AMyBaseClass::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyBaseClass_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyBaseClass()
	{
		if (!Z_Registration_Info_UClass_AMyBaseClass.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyBaseClass.OuterSingleton, Z_Construct_UClass_AMyBaseClass_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyBaseClass.OuterSingleton;
	}
	template<> MYPROJECT_API UClass* StaticClass<AMyBaseClass>()
	{
		return AMyBaseClass::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyBaseClass);
	struct Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::EnumInfo[] = {
		{ CharacterStates_StaticEnum, TEXT("CharacterStates"), &Z_Registration_Info_UEnum_CharacterStates, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2683037699U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyBaseClass, AMyBaseClass::StaticClass, TEXT("AMyBaseClass"), &Z_Registration_Info_UClass_AMyBaseClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyBaseClass), 2434527284U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_1348256265(TEXT("/Script/MyProject"),
		Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
