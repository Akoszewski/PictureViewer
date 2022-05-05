mkdir -p build
rm PictureViewer
cd build
qmake ..
make
cd ..
./build/PictureViewer
