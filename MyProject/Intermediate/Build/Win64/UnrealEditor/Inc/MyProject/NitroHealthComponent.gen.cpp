// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/NitroHealthComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNitroHealthComponent() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_UNitroHealthComponent_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_UNitroHealthComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_MyProject();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UNitroHealthComponent::execOnCapsuleBeginOverlap)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnCapsuleBeginOverlap(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	void UNitroHealthComponent::StaticRegisterNativesUNitroHealthComponent()
	{
		UClass* Class = UNitroHealthComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnCapsuleBeginOverlap", &UNitroHealthComponent::execOnCapsuleBeginOverlap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics
	{
		struct NitroHealthComponent_eventOnCapsuleBeginOverlap_Parms
		{
			UPrimitiveComponent* OverlappedComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(NitroHealthComponent_eventOnCapsuleBeginOverlap_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OverlappedComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OverlappedComp_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(NitroHealthComponent_eventOnCapsuleBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(NitroHealthComponent_eventOnCapsuleBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OtherComp_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(NitroHealthComponent_eventOnCapsuleBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((NitroHealthComponent_eventOnCapsuleBeginOverlap_Parms*)Obj)->bFromSweep = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(NitroHealthComponent_eventOnCapsuleBeginOverlap_Parms), &Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(NitroHealthComponent_eventOnCapsuleBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_SweepResult_MetaData)) }; // 1416937132
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OverlappedComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OtherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OtherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_OtherBodyIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_bFromSweep,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Overlapping related functions\n" },
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
		{ "ToolTip", "Overlapping related functions" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNitroHealthComponent, nullptr, "OnCapsuleBeginOverlap", nullptr, nullptr, sizeof(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::NitroHealthComponent_eventOnCapsuleBeginOverlap_Parms), Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNitroHealthComponent);
	UClass* Z_Construct_UClass_UNitroHealthComponent_NoRegister()
	{
		return UNitroHealthComponent::StaticClass();
	}
	struct Z_Construct_UClass_UNitroHealthComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RingLossAmount_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_RingLossAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KnockbackForce_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_KnockbackForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RingSpawnAmount_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_RingSpawnAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnPoint_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnPoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Rings_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Rings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedActorRef_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedActorRef;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PhysicsRingRef_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_PhysicsRingRef;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RingDropSFX_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RingDropSFX;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNitroHealthComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UNitroHealthComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UNitroHealthComponent_OnCapsuleBeginOverlap, "OnCapsuleBeginOverlap" }, // 1300512893
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "NitroHealthComponent.h" },
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingLossAmount_MetaData[] = {
		{ "Category", "NitroHealthComponent" },
		{ "Comment", "// TODO - IMPORT ALL THE LOGIC INSIDE THE BLUEPRINT CLASS INTO HERE\n" },
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
		{ "ToolTip", "TODO - IMPORT ALL THE LOGIC INSIDE THE BLUEPRINT CLASS INTO HERE" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingLossAmount = { "RingLossAmount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UNitroHealthComponent, RingLossAmount), METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingLossAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingLossAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_KnockbackForce_MetaData[] = {
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_KnockbackForce = { "KnockbackForce", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UNitroHealthComponent, KnockbackForce), METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_KnockbackForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_KnockbackForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingSpawnAmount_MetaData[] = {
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingSpawnAmount = { "RingSpawnAmount", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UNitroHealthComponent, RingSpawnAmount), METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingSpawnAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingSpawnAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Radius_MetaData[] = {
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UNitroHealthComponent, Radius), METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Radius_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_SpawnPoint_MetaData[] = {
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_SpawnPoint = { "SpawnPoint", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UNitroHealthComponent, SpawnPoint), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_SpawnPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_SpawnPoint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Rings_MetaData[] = {
		{ "Category", "NitroHealthComponent" },
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Rings = { "Rings", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UNitroHealthComponent, Rings), METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Rings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Rings_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_OverlappedActorRef_MetaData[] = {
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_OverlappedActorRef = { "OverlappedActorRef", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UNitroHealthComponent, OverlappedActorRef), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_OverlappedActorRef_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_OverlappedActorRef_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_PhysicsRingRef_MetaData[] = {
		{ "Category", "NitroHealthComponent" },
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_PhysicsRingRef = { "PhysicsRingRef", nullptr, (EPropertyFlags)0x0014000000020001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UNitroHealthComponent, PhysicsRingRef), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_PhysicsRingRef_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_PhysicsRingRef_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingDropSFX_MetaData[] = {
		{ "ModuleRelativePath", "NitroHealthComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingDropSFX = { "RingDropSFX", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UNitroHealthComponent, RingDropSFX), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingDropSFX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingDropSFX_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNitroHealthComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingLossAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_KnockbackForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingSpawnAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_SpawnPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_Rings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_OverlappedActorRef,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_PhysicsRingRef,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNitroHealthComponent_Statics::NewProp_RingDropSFX,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNitroHealthComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNitroHealthComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNitroHealthComponent_Statics::ClassParams = {
		&UNitroHealthComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UNitroHealthComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UNitroHealthComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UNitroHealthComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UNitroHealthComponent()
	{
		if (!Z_Registration_Info_UClass_UNitroHealthComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNitroHealthComponent.OuterSingleton, Z_Construct_UClass_UNitroHealthComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNitroHealthComponent.OuterSingleton;
	}
	template<> MYPROJECT_API UClass* StaticClass<UNitroHealthComponent>()
	{
		return UNitroHealthComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNitroHealthComponent);
	struct Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroHealthComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroHealthComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNitroHealthComponent, UNitroHealthComponent::StaticClass, TEXT("UNitroHealthComponent"), &Z_Registration_Info_UClass_UNitroHealthComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNitroHealthComponent), 1187762357U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroHealthComponent_h_2632752249(TEXT("/Script/MyProject"),
		Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroHealthComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroHealthComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
