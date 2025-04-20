CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = makefile_demo.exe
SRCS = makefile_demo.cpp

$(TARGET): $(SRCS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
    del $(TARGET)