REM Use this script as post build event in visual studio
REM call "vs_copy.bat" $(OutDir) $(TargetName) "Your\Zorro\Strategy\Path"

setlocal

set currentFilename=%~n0%~x0
set outDir=%1
set targetName=%2
set path=%3

echo Executing post build event: %currentFilename%
echo Target: %path%

for %%f in (
	"%outDir%%targetName%.dll"
	"%outDir%%targetName%.pdb"
	) do (
	echo Source: %%f
	copy %%f %path% /Y
)

endlocal
