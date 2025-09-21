CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2 -static -static-libgcc -static-libstdc++

TARGET = structs
SOURCES = main.cpp func.cpp

all: $(TARGET).exe

$(TARGET).exe: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET).exe

clean:
	del $(TARGET).exe 2>nul || rm -f $(TARGET).exe