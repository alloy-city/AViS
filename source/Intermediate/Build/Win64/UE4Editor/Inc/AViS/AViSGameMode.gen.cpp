// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AViS/AViSGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAViSGameMode() {}
// Cross Module References
	AVIS_API UClass* Z_Construct_UClass_AAViSGameMode_NoRegister();
	AVIS_API UClass* Z_Construct_UClass_AAViSGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_AViS();
// End Cross Module References
	void AAViSGameMode::StaticRegisterNativesAAViSGameMode()
	{
	}
	UClass* Z_Construct_UClass_AAViSGameMode_NoRegister()
	{
		return AAViSGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AAViSGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAViSGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AViS,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAViSGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AViSGameMode.h" },
		{ "ModuleRelativePath", "AViSGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAViSGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAViSGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAViSGameMode_Statics::ClassParams = {
		&AAViSGameMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802A8u,
		METADATA_PARAMS(Z_Construct_UClass_AAViSGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AAViSGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAViSGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAViSGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAViSGameMode, 3445679264);
	template<> AVIS_API UClass* StaticClass<AAViSGameMode>()
	{
		return AAViSGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAViSGameMode(Z_Construct_UClass_AAViSGameMode, &AAViSGameMode::StaticClass, TEXT("/Script/AViS"), TEXT("AAViSGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAViSGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
