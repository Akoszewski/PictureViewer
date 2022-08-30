mkdir -p build
rm PictureViewer
cd build
qmake ..
make || exit -1
cd ..
./build/PictureViewer
