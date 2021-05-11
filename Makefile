all:
	mkdir -p bin; g++ ./source_files/main.cpp ./source_files/video_converter.cpp  -o ./bin/Practica1.bin \
		-I/home/ezhizhpon/Apps/opencv_i-4.5.2/include/opencv4 \
		-L/home/ezhizhpon/Apps/opencv_i-4.5.2/lib \
		-lstdc++fs \
		-lopencv_core \
		-lopencv_highgui \
		-lopencv_imgproc \
		-lopencv_imgcodecs \
		-lopencv_video  \
		-lopencv_videoio \

run:
	cd bin/; ./Practica1.bin