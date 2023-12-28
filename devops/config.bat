@echo.off

rem Engine params
set EnginePathInstalledBuild=c:\ue_pkgs\UE5_Windows_5.3.1-release_5ccd1d8
set VersionSelector=C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64\UnrealVersionSelector.exe

rem Current engine path
set CurrentEnginePath=%EnginePathInstalledBuild%

rem Editor path
set EditorPath=%CurrentEnginePath%\Engine\Binaries\Win64\UnrealEditor.exe

rem !! Engine version for packaging !!
@REM set RunUATPath=%EnginePath%\Engine\Build\BatchFiles\RunUAT.bat
set RunUATPath=%CurrentEnginePath%\Engine\Build\BatchFiles\RunUAT.bat

rem Project params
set ProjectRoot=C:\workdir\how_tos\howTo
set ProjectPureName=howTo
set ProjectName=%ProjectPureName%.uproject
set ProjectPath=%ProjectRoot%\%ProjectName%

rem Build params
set Platform=Win64
set Configuration=Development
set ArchivePath=%ProjectRoot%\Build

rem Other params
set SourceCodePath=%ProjectRoot%\Source
set dirsToRemove=Intermediate DerivedDataCache Saved Binaries .vs Build
set filesToRemove=*.sln
set COPYRIGTH_LINE=// All Rights Reserved. 2024 s_timokhin

rem Target params
set COPYRIGTH_LINE=// All Rights Reserved. 2024 s_timokhin
set EXTRA_MODULE_NAMES="%ProjectPureName%"
set TargetTemplateFilePath=%ProjectRoot%\devops\targets\GameModule.Target.cs.template

rem Run
set ServerExePath=%ProjectRoot%/Build/WindowsServer/%ProjectPureName%Server.exe
set ClientExePath=%ProjectRoot%/Build/WindowsClient/%ProjectPureName%Client.exe
set GameExePath=%ProjectRoot%/Build/WindowsNoEditor/%ProjectPureName%.exe

rem Tests
set TestOutputLogPath=%ProjectRoot%\Build\Tests\Tests.log
set ReportOutputPath=%ProjectRoot%\Build\Tests
set UEAutomationContentPath=%CurrentEnginePath%\Engine\Content\Automation
set TestNames=tan4iki
