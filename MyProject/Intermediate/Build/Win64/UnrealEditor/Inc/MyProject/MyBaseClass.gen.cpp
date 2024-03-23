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
	MYPROJECT_API UClass* Z_Construct_UClass_AMyBaseClass_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_AMyBaseClass();
	NINJACHARACTER_API UClass* Z_Construct_UClass_ANinjaCharacter();
	UPackage* Z_Construct_UPackage__Script_MyProject();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTimelineComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UFunction* Z_Construct_UDelegateFunction_Engine_OnTimelineFloat__DelegateSignature();
// End Cross Module References
	DEFINE_FUNCTION(AMyBaseClass::execTimelineProgress)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Alpha);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TimelineProgress(Z_Param_Alpha);
		P_NATIVE_END;
	}
	void AMyBaseClass::StaticRegisterNativesAMyBaseClass()
	{
		UClass* Class = AMyBaseClass::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TimelineProgress", &AMyBaseClass::execTimelineProgress },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics
	{
		struct MyBaseClass_eventTimelineProgress_Parms
		{
			float Alpha;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Alpha;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::NewProp_Alpha = { "Alpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyBaseClass_eventTimelineProgress_Parms, Alpha), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::NewProp_Alpha,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyBaseClass, nullptr, "TimelineProgress", nullptr, nullptr, sizeof(Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::MyBaseClass_eventTimelineProgress_Parms), Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyBaseClass_TimelineProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyBaseClass_TimelineProgress_Statics::FuncParams);
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BallMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BallMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnRateGamepad_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnRateGamepad;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pushForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pushForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_currentStamina_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_currentStamina;
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovementValue_MetaData[];
#endif
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_MovementValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RingCount_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_RingCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isJumping_MetaData[];
#endif
		static void NewProp_isJumping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isJumping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isBoosting_MetaData[];
#endif
		static void NewProp_isBoosting_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isBoosting;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isStomping_MetaData[];
#endif
		static void NewProp_isStomping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isStomping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsGrounded_MetaData[];
#endif
		static void NewProp_bIsGrounded_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsGrounded;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsHomingAttacking_MetaData[];
#endif
		static void NewProp_IsHomingAttacking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsHomingAttacking;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyBaseClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANinjaCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyBaseClass_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyBaseClass_TimelineProgress, "TimelineProgress" }, // 2829298357
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BallMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BallMesh = { "BallMesh", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, BallMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BallMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BallMesh_MetaData)) };
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce_MetaData[] = {
		{ "Category", "Forces" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce = { "pushForce", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, pushForce), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_currentStamina_MetaData[] = {
		{ "Category", "Boost Stamina" },
		{ "Comment", "//Unused at the moment\n" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "Unused at the moment" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_currentStamina = { "currentStamina", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, currentStamina), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_currentStamina_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_currentStamina_MetaData)) };
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_OldTarget = { "OldTarget", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, OldTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_OldTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_OldTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget_MetaData[] = {
		{ "Category", "Homing Attack2" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget = { "CurrentTarget", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, CurrentTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget_MetaData[] = {
		{ "Category", "Homing Attack3" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget = { "ChosenTarget", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, ChosenTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline = { "MainTimeline", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, MainTimeline), Z_Construct_UClass_UTimelineComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FloatCurve_MetaData[] = {
		{ "Category", "MyBaseClass" },
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MovementValue_MetaData[] = {
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MovementValue = { "MovementValue", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, MovementValue), Z_Construct_UDelegateFunction_Engine_OnTimelineFloat__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MovementValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MovementValue_MetaData)) }; // 1025672532
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount_MetaData[] = {
		{ "Category", "Rings" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount = { "RingCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBaseClass, RingCount), METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isJumping_MetaData[] = {
		{ "Category", "Jumping State" },
		{ "Comment", "// These are most likely gonna be replaced by enums later. - Ersan 04.03.2024\n" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
		{ "ToolTip", "These are most likely gonna be replaced by enums later. - Ersan 04.03.2024" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isJumping_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->isJumping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isJumping = { "isJumping", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isJumping_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isJumping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isJumping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isBoosting_MetaData[] = {
		{ "Category", "Boost State" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isBoosting_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->isBoosting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isBoosting = { "isBoosting", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isBoosting_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isBoosting_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isBoosting_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isStomping_MetaData[] = {
		{ "Category", "Stomp State" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isStomping_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->isStomping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isStomping = { "isStomping", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isStomping_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isStomping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isStomping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_MetaData[] = {
		{ "Category", "Grounded State" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->bIsGrounded = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded = { "bIsGrounded", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBaseClass_Statics::NewProp_IsHomingAttacking_MetaData[] = {
		{ "Category", "Homing State" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_IsHomingAttacking_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->IsHomingAttacking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_IsHomingAttacking = { "IsHomingAttacking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_IsHomingAttacking_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_IsHomingAttacking_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_IsHomingAttacking_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyBaseClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BallMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TurnRateGamepad,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_currentStamina,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_GroundAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_OldTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CurrentTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ChosenTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MainTimeline,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FloatCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_ActorLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_MovementValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isJumping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isBoosting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isStomping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_IsHomingAttacking,
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
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyBaseClass, AMyBaseClass::StaticClass, TEXT("AMyBaseClass"), &Z_Registration_Info_UClass_AMyBaseClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyBaseClass), 311603961U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_197274487(TEXT("/Script/MyProject"),
		Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
