mkdir -p build
rm PictureViewer
cd build
qmake ..
make || exit -1
cd ..
cp -R ./images/ ~/Documents/
./build/PictureViewer
