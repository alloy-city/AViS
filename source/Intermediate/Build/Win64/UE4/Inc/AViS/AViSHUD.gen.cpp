// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AViS/AViSHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAViSHUD() {}
// Cross Module References
	AVIS_API UClass* Z_Construct_UClass_AAViSHUD_NoRegister();
	AVIS_API UClass* Z_Construct_UClass_AAViSHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_AViS();
// End Cross Module References
	void AAViSHUD::StaticRegisterNativesAAViSHUD()
	{
	}
	UClass* Z_Construct_UClass_AAViSHUD_NoRegister()
	{
		return AAViSHUD::StaticClass();
	}
	struct Z_Construct_UClass_AAViSHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAViSHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_AViS,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAViSHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "AViSHUD.h" },
		{ "ModuleRelativePath", "AViSHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAViSHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAViSHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAViSHUD_Statics::ClassParams = {
		&AAViSHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AAViSHUD_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AAViSHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAViSHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAViSHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAViSHUD, 4232882140);
	template<> AVIS_API UClass* StaticClass<AAViSHUD>()
	{
		return AAViSHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAViSHUD(Z_Construct_UClass_AAViSHUD, &AAViSHUD::StaticClass, TEXT("/Script/AViS"), TEXT("AAViSHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAViSHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
