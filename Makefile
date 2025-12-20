CXX = g++
CXXFLAGS = -std=c++20 -O2 -Wall -Wextra -Iinclude

TARGET = connection
SOURCES = src/connection.cpp src/static.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Build Successful"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)