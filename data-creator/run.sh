g++ CopyPatientInfo.cpp -o copy.exe -limebra || exit -1
g++ ReplacePatientInfo.cpp -o replace.exe -limebra || exit -1
./replace.exe
./copy.exe
