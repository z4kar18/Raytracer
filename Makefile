CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
LDFLAGS = -lconfig++

SRCS = src/Vec3.cpp src/Ray.cpp src/Camera.cpp src/Sphere.cpp src/ImageWriter.cpp \
       src/Plane.cpp main.cpp src/TranslatedPrimitive.cpp src/RayTracerUtils.cpp \
       src/Scene.cpp src/Cone.cpp src/Light.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = raytracer

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
