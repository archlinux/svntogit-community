
include config

SRC = alpha.cpp clusterfit.cpp colourblock.cpp colourfit.cpp colourset.cpp maths.cpp rangefit.cpp singlecolourfit.cpp squish.cpp

OBJ = $(SRC:%.cpp=%.o)

LIB = libsquish.a

all : $(LIB)

install : $(LIB)
	install squish.h $(INSTALL_DIR)/include 
	install libsquish.a $(INSTALL_DIR)/lib

uninstall:
	$(RM) $(INSTALL_DIR)/include/squish.h
	$(RM) $(INSTALL_DIR)/lib/libsquish.a

$(LIB) : $(OBJ)
	$(CXX) -shared -Wl,-soname,libsquish.so.1 -o libsquish.so.1.0 $?
	ln -sf libsquish.so.1.0 libsquish.so
	ln -sf libsquish.so.1.0 libsquish.so.1

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -fPIC -I. $(CXXFLAGS) -o$@ -c $<

clean :
	$(RM) $(OBJ) $(LIB)



