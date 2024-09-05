CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = main
SOURCES = main.cpp polynom.cpp polynom_plot.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
