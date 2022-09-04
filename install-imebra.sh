cd ./imebra/
mkdir artifacts
cd artifacts/
cmake ..
make
cd ../..
sudo cp -R ./imebra/library/include /usr/include
sudo cp ./imebra/artifacts/libimebra.so* /usr/lib
