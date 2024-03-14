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
// End Cross Module References
	void AMyBaseClass::StaticRegisterNativesAMyBaseClass()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyBaseClass);
	UClass* Z_Construct_UClass_AMyBaseClass_NoRegister()
	{
		return AMyBaseClass::StaticClass();
	}
	struct Z_Construct_UClass_AMyBaseClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
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
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyBaseClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANinjaCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
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
		{ "ModuleRelativePath", "MyBaseClass.h" },
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
		{ "Category", "IsGrounded State" },
		{ "ModuleRelativePath", "MyBaseClass.h" },
	};
#endif
	void Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_SetBit(void* Obj)
	{
		((AMyBaseClass*)Obj)->bIsGrounded = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded = { "bIsGrounded", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBaseClass), &Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyBaseClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_BallMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_TurnRateGamepad,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_pushForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_currentStamina,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_GroundAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_RingCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isJumping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isBoosting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_isStomping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBaseClass_Statics::NewProp_bIsGrounded,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyBaseClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyBaseClass>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyBaseClass_Statics::ClassParams = {
		&AMyBaseClass::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMyBaseClass_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
		{ Z_Construct_UClass_AMyBaseClass, AMyBaseClass::StaticClass, TEXT("AMyBaseClass"), &Z_Registration_Info_UClass_AMyBaseClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyBaseClass), 1282046963U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_2094435405(TEXT("/Script/MyProject"),
		Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_MyBaseClass_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
