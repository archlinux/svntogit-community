include Make.inc

all: libatlas.so libf77blas.so libcblas.so libblas.so liblapack.so


libatlas.so: libatlas.a
	ld $(LDFLAGS) -shared -soname $@ -o $@ --whole-archive libatlas.a \
	   --no-whole-archive -lc $(LIBS)

libf77blas.so : libf77blas.a libatlas.so
	ld $(LDFLAGS) -shared -soname libblas.so.3 -o $@ --whole-archive \
	   libf77blas.a --no-whole-archive $(F77SYSLIB) -L. -latlas

libblas.so: libf77blas.so
	ln -s $< $@

libcblas.so : libcblas.a libatlas.so libblas.so
	ld $(LDFLAGS) -shared -soname $@ -o $@ --whole-archive libcblas.a \
	    -L. -latlas -lblas

liblapack.so : liblapack.a libcblas.so libblas.so
	ld $(LDFLAGS) -shared -soname liblapack.so.3 -o $@ --whole-archive \
	   liblapack.a --no-whole-archive $(F77SYSLIB) -L. -lcblas -lblas -lgcc_s

