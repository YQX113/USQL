#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BluePrint/USqlObject.h"
#include "USQLibrary.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMySQL, Log, All);

#define LOG_INFO(Format, ...)     UE_LOG(LogTemp, Log,   TEXT(Format), ##__VA_ARGS__)
#define LOG_ERROR(Format, ...)    UE_LOG(LogTemp, Error, TEXT(Format), ##__VA_ARGS__)

#if 1
UCLASS()
class USQL_API USQLibrary : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

	

public:
	UFUNCTION(BlueprintCallable, meta = (Keywords = "USQL_CreateUSqlObject"), Category = "USQLTesting")
	static UUSqlObject* CreateUSqlObject//mysql_object
	(
		UObject* WorldContextObject,
		const FString& InHost,
		const FString& InUser,
		const FString& InPawd,
		const FString& InDB,
		const int32  InPort,
		const TArray<EUClientFlags>& InClientFlag,
		const FString& Unix_Socket = TEXT("")
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool QueryLink(UUSqlObject* _InObject, const FString& _InSQL, FString& _InErrorMsg);



	//·······································································
	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool ChangeDB(UUSqlObject* _InObject,const FString& _InNewDB, FString& _InErrorMsg);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool CreateDataBase
	(
		UUSqlObject* _InObject, 
		const FString& _InDataBaseName,							 
		const FMysqlCreateDateBaseParam& _InDataBaseParam,		 
		FString& _InErrorMsg
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool CreateAndSelectDataBase
	(
		UUSqlObject* _InObject,
		const FString& _InDataBaseName, 
		const FMysqlCreateDateBaseParam& _InDataBaseParam, 
		FString& _InErrorMsg
	);



	//·······································································
	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool CreateTable
	(
		UUSqlObject* _InObject,
		const bool _bTemporary,
		const FString& _InTableName,							 
		const TMap<FString, struct FUSqlFieldType>& _InFields,	 
		const TArray<FString>& _InPrimaryKeys,					 
		const TArray<FUSqlIndex>& _InIndex,						 
		const TArray<FUSqlForeignKey>& _InForeignKeys,			 
		const FMysqlCreateTableParam& _InTableParam,			 
		FString& _InErrorMsg									 
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool CreateTableALikeB
	(
		UUSqlObject* _InObject,
		const FString& _InNewTableName,
		const FString& _InSourceTableName,
		FString& _InErrorMsg,
		bool _bTemporary = false,
		bool _bIfNotExists = false
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool DropTable
	(
		UUSqlObject* _InObject,
		const TArray<FString>& _InTableName,
		const bool _bTemporary,
		FString& _InErrorMsg
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool TurncateTable
	(
		UUSqlObject* _InObject,
		const FString& _InTableName,
		FString& _InErrorMsg
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool DeleteFromTable
	(
		UUSqlObject* _InObject,
		const FString& _InTabelName,
		const FString& _InConditionStatement,
		FString& _InErrorMsg
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool DeleteFromTableCondition
	(
		UUSqlObject* _InObject,
		const FString& _InTabelName,
		const TArray<FUSQLComparisonOperator>& _InConditionStatement,
		const int32 _InLimit,
		FString& _InErrorMsg
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool OptimizeTable
	(
		UUSqlObject* _InObject,
		const FString& _InTabelName,
		FString& _InErrorMsg
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool CreateTableAsSelect
	(
		UUSqlObject* _InObject,
		const FString& _InNewTableName,
		const TMap<FString, FUSqlFieldType>& _InsertFields,
		const FUSQLQueryParameters& _InQueryParam,
		bool _bTemporary,                                     // CREATE TEMPORARY TABLE
		bool _bIfNotExists,                                   // IF NOT EXISTS
		FString& _InErrorMsg
	);



	//·······································································
	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool QueryLinkAndGetResult
	(
		UUSqlObject* _InObject,
		const FString& _InSQL,								 
		FString& _InErrorMsg,								 
		bool _InbStore,										 
		bool _InbDebugLength,
		const FUSQLDebugResult& _InDebug = FUSQLDebugResult()
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static TArray<FString> GetRow
	(
		UUSqlObject* _InObject,
		int32 _InResultIndex,				
		int32 _InRowIndex					
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static FString GetCell
	(
		UUSqlObject* _InObject,
		int32 _InResultIndex,			
		int32 _InRowIndex,				
		int32 _InColIndex				
	);



	//·······································································
	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool GetSelectTableDataSQL
	(
		UUSqlObject* _InObject,
		FString& _InSQL,
		const FUSQLQueryParameters& _InQueryParameters
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool GetSelectTableData
	(
		UUSqlObject* _InObject,
		const FUSQLQueryParameters& _InSelectParam,
		FString& _InErrMesg,
		bool _InbStore,
		bool _InbDebugLength,
		const FUSQLDebugResult& _InDebug = FUSQLDebugResult()
	);



	//·······································································
	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool UpdateTableData
	(
		UUSqlObject* _InObject,
		const FString& _InTableName, 
		const TArray<FUSQLAssignment>& _InFields,
		const TArray<FUSQLComparisonOperator>& _InCondition,
		FString& _InErrorMsg,
		int32 _InOffset,										
		int32 _InRowCount,										
		const TArray<FString>& _InOrderBy,							
		bool _bAllowFullTableUpdate = false						    
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool ReplaceTableData
	(
		UUSqlObject* _InObject,
		const FString& _InTableName,
		const TArray<FUSQLReplaceParameters>& _InReplaces,
		const TArray<FUSQLComparisonOperator>& _InCondition,
		FString& _InErrorMsg
	);



	//·······································································
	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool InsertTableData
	(
		UUSqlObject* _InObject,
		const FString& _InTableName,					
		const FUSQLInsertColumn& _InsertData,			
		const FUSQLQueryParameters& _InQueryParam,		
		FString& _InErrorMsg,							
		bool _bIgnore,									
		bool _bAppendOnDuplicate						
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool ReplaceIfConflict
	(
		UUSqlObject* _InObject,
		const FString& _InTableName,                    
		const FUSQLInsertColumn& _InsertData,           
		const FUSQLQueryParameters& _InQueryParam,      
		FString& _InErrorMsg                            
	);



	//·······································································
	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool StartTransaction(UUSqlObject* _InObject, FString& _OutErrorMsg);						  // START TRANSACTION

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool SetAutoCommit(UUSqlObject* _InObject, bool _bAuto, FString& _OutErrorMsg);				  // SET AUTOCOMMIT

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool Commit(UUSqlObject* _InObject, FString& _OutErrorMsg);									  // COMMIT

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool SetUpSavePoint(UUSqlObject* _InObject, const FString& _InSaveName, FString& _OutErrorMsg);// SAVEPOINT

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool ReleaseSavePoint(UUSqlObject* _InObject, const FString& _InSaveName, FString& _OutErrorMsg);// ROLLBACK

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool Rollback(UUSqlObject* _InObject, const FString& _InSaveName, FString& _OutErrorMsg);		  // RELEASE SAVEPOIN


	//·······································································
	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool AL_TableChangeEngine(UUSqlObject* _InObject, const FString& _InTableName, const EMysqlSaveEngine& _InEngine, FString& _ErrorMsg);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool AL_TableDropField(UUSqlObject* _InObject, const FString& _InTableName, const TArray<FString>& _InFieldsName, EAlterAlgorithm _InAlgorithm, FString& _ErrorMsg);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool AL_TableAddField
	(
		UUSqlObject* _InObject,
		const FString& _InTableName,
		const TMap<FString, FUSqlFieldType>& _InFields,
		FString& _InErrorMsg,
		EAlterAlgorithm _InAlgorithm
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool AL_TableModifyField
	(
		UUSqlObject* _InObject,
		const FString& _InTableName,
		const TMap<FString, FUSqlFieldType>& _InFields,
		FString& _InErrorMsg,
		EAlterAlgorithm _InAlgorithm
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool AL_TableChangeField
	(
		UUSqlObject* _InObject,
		const FString& _InTableName,
		const TArray<FString>& _InOldFieldNames,
		const TArray<FUSQLFieldChange>& _InFieldsArray,
		FString& _InErrorMsg,
		EAlterAlgorithm _InAlgorithm
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool AL_TableRename
	(
		UUSqlObject* _InObject,
		const FString& _InOldTableName,
		const FString& _InNewTableName,
		FString& _InErrorMsg
	);

	//·······································································
	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static void Stmt_SetParamsPerStmt
	(
		UUSqlObject* _InObject,
		const FUSQLQueryStmtSet& _InFUSQLQueryStmtSet
	);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool Stmt_InitializeAndPrepare(UUSqlObject* _InObject);
		

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool Stmt_BindAndExecuteStmtIndex(UUSqlObject* _InObject, const TArray<int32>& _InStmtIndex);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool Stmt_ExecuteStmtIndexs(UUSqlObject* _InObject, const TArray<int32>& _InStmtIndexs);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool Stmt_UpdateBoundParamValueSafe(UUSqlObject* _InObject, int32 _InStmtIndex, int32 _InParamIndex, const FString& _InNewValue);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool Stmt_UpdateBoundParamValues(UUSqlObject* _InObject, const FUSQLUpdateParamsSet& _InUpdateParamsSet);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool Stmt_PrepareAndBindResultForStmt(UUSqlObject* _InObject);

	UFUNCTION(BlueprintCallable, meta = (Category = "USQL"))
	static bool Stmt_FetchAllResults(UUSqlObject* _InObject, bool _bStmtStoreRes, const FUSQLDebugResult& _InDebug);
};
#endif






