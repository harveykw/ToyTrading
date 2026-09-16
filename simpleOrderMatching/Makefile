CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = order_matching

.PHONY: all run clean

all: $(TARGET)

# main.cpp includes engine.cpp directly, so compile only main.cpp.
$(TARGET): main.cpp engine.cpp engine.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) main.cpp $(LDFLAGS) $(LDLIBS) -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET)
