// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/NinjaMovementComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNinjaMovementComponent() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_UNinjaMovementComponent_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_UNinjaMovementComponent();
	NINJACHARACTER_API UClass* Z_Construct_UClass_UNinjaCharacterMovementComponent();
	UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References
	void UNinjaMovementComponent::StaticRegisterNativesUNinjaMovementComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNinjaMovementComponent);
	UClass* Z_Construct_UClass_UNinjaMovementComponent_NoRegister()
	{
		return UNinjaMovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_UNinjaMovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNinjaMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UNinjaCharacterMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNinjaMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "NinjaMovementComponent.h" },
		{ "ModuleRelativePath", "NinjaMovementComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNinjaMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNinjaMovementComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNinjaMovementComponent_Statics::ClassParams = {
		&UNinjaMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UNinjaMovementComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UNinjaMovementComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UNinjaMovementComponent()
	{
		if (!Z_Registration_Info_UClass_UNinjaMovementComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNinjaMovementComponent.OuterSingleton, Z_Construct_UClass_UNinjaMovementComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNinjaMovementComponent.OuterSingleton;
	}
	template<> MYPROJECT_API UClass* StaticClass<UNinjaMovementComponent>()
	{
		return UNinjaMovementComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNinjaMovementComponent);
	struct Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NinjaMovementComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NinjaMovementComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNinjaMovementComponent, UNinjaMovementComponent::StaticClass, TEXT("UNinjaMovementComponent"), &Z_Registration_Info_UClass_UNinjaMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNinjaMovementComponent), 3175005131U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NinjaMovementComponent_h_916688012(TEXT("/Script/MyProject"),
		Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NinjaMovementComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NinjaMovementComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
