// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/NitroEnemyClass.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNitroEnemyClass() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_ANitroEnemyClass_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_ANitroEnemyClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MyProject();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_UNitroHealthComponent_NoRegister();
// End Cross Module References
	void ANitroEnemyClass::StaticRegisterNativesANitroEnemyClass()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANitroEnemyClass);
	UClass* Z_Construct_UClass_ANitroEnemyClass_NoRegister()
	{
		return ANitroEnemyClass::StaticClass();
	}
	struct Z_Construct_UClass_ANitroEnemyClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnemyRootComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyRootComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnemyMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CapsuleCollider_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CapsuleCollider;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ArrowComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ArrowComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnemyHealthComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyHealthComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANitroEnemyClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANitroEnemyClass_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "NitroEnemyClass.h" },
		{ "ModuleRelativePath", "NitroEnemyClass.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyRootComponent_MetaData[] = {
		{ "Category", "NitroEnemyClass" },
		{ "Comment", "// Creating references for the required components\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NitroEnemyClass.h" },
		{ "ToolTip", "Creating references for the required components" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyRootComponent = { "EnemyRootComponent", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANitroEnemyClass, EnemyRootComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyRootComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyRootComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyMesh_MetaData[] = {
		{ "Category", "Customizable Variables" },
		{ "Comment", "// TODO - Remove this from the code and only do it through blueprints\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NitroEnemyClass.h" },
		{ "ToolTip", "TODO - Remove this from the code and only do it through blueprints" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyMesh = { "EnemyMesh", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANitroEnemyClass, EnemyMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_CapsuleCollider_MetaData[] = {
		{ "Category", "Customizable Variables" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NitroEnemyClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_CapsuleCollider = { "CapsuleCollider", nullptr, (EPropertyFlags)0x001000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANitroEnemyClass, CapsuleCollider), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_CapsuleCollider_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_CapsuleCollider_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_ArrowComponent_MetaData[] = {
		{ "Category", "Customizable Variables" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NitroEnemyClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_ArrowComponent = { "ArrowComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANitroEnemyClass, ArrowComponent), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_ArrowComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_ArrowComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyHealthComponent_MetaData[] = {
		{ "Category", "Health Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NitroEnemyClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyHealthComponent = { "EnemyHealthComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANitroEnemyClass, EnemyHealthComponent), Z_Construct_UClass_UNitroHealthComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyHealthComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyHealthComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANitroEnemyClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyRootComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_CapsuleCollider,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_ArrowComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANitroEnemyClass_Statics::NewProp_EnemyHealthComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANitroEnemyClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANitroEnemyClass>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANitroEnemyClass_Statics::ClassParams = {
		&ANitroEnemyClass::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANitroEnemyClass_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANitroEnemyClass_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ANitroEnemyClass_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANitroEnemyClass_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANitroEnemyClass()
	{
		if (!Z_Registration_Info_UClass_ANitroEnemyClass.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANitroEnemyClass.OuterSingleton, Z_Construct_UClass_ANitroEnemyClass_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANitroEnemyClass.OuterSingleton;
	}
	template<> MYPROJECT_API UClass* StaticClass<ANitroEnemyClass>()
	{
		return ANitroEnemyClass::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANitroEnemyClass);
	struct Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroEnemyClass_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroEnemyClass_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANitroEnemyClass, ANitroEnemyClass::StaticClass, TEXT("ANitroEnemyClass"), &Z_Registration_Info_UClass_ANitroEnemyClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANitroEnemyClass), 213627187U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroEnemyClass_h_3174041892(TEXT("/Script/MyProject"),
		Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroEnemyClass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject_Source_MyProject_NitroEnemyClass_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
