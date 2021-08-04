# Maintainer: Anatol Pomozov <anatol.pomozov@gmail.com>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_target=aarch64-linux-gnu
pkgname=$_target-gcc
pkgver=11.2.0
_islver=0.24
pkgrel=1
#_snapshot=8-20190111
pkgdesc='The GNU Compiler Collection - cross compiler for ARM64 target'
arch=(x86_64)
url='https://gcc.gnu.org/'
license=(GPL LGPL FDL)
depends=($_target-binutils $_target-glibc libmpc zlib)
makedepends=(gmp mpfr)
options=(!emptydirs !strip staticlibs)
source=(https://ftp.gnu.org/gnu/gcc/gcc-$pkgver/gcc-$pkgver.tar.xz{,.sig}
        #https://gcc.gnu.org/pub/gcc/snapshots/$_snapshot/gcc-$_snapshot.tar.xz
        http://isl.gforge.inria.fr/isl-$_islver.tar.bz2)
sha256sums=('d08edc536b54c372a1010ff6619dd274c0f1603aa49212ba20f7aa2cda36fa8b'
            'SKIP'
            'fcf78dd9656c10eb8cf9fbd5f59a0b6b01386205fe1934b3b287a0a1898145c0')
validpgpkeys=(D3A93CAD751C2AF4F8C7AD516C35B99309B5FA62  # Jakub Jelinek <jakub@redhat.com>
              33C235A34C46AA3FFB293709A328C3A2C3C45C06  # Jakub Jelinek <jakub@redhat.com>
              13975A70E63C361C73AE69EF6EEB81F8981C74C7) # Richard Guenther <richard.guenther@gmail.com>

if [ -n "$_snapshot" ]; then
  _basedir=gcc-$_snapshot
else
  _basedir=gcc-$pkgver
fi

prepare() {
  cd $_basedir

  # link isl for in-tree builds
  ln -sf ../isl-$_islver isl

  echo $pkgver > gcc/BASE-VER

  # Do not run fixincludes
  sed -i 's@\./fixinc\.sh@-c true@' gcc/Makefile.in

  # hack! - some configure tests for header files using "$CPP $CPPFLAGS"
  sed -i "/ac_cpp=/s/\$CPPFLAGS/\$CPPFLAGS -O2/" "$srcdir"/$_basedir/{libiberty,gcc}/configure

  rm -rf "$srcdir"/gcc-build
  mkdir "$srcdir"/gcc-build
}

build() {
  cd gcc-build

  # using -pipe causes spurious test-suite failures
  # http://gcc.gnu.org/bugzilla/show_bug.cgi?id=48565
  CFLAGS=${CFLAGS/-pipe/}
  CXXFLAGS=${CXXFLAGS/-pipe/}

  "$srcdir"/$_basedir/configure \
      --prefix=/usr \
      --program-prefix=$_target- \
      --with-local-prefix=/usr/$_target \
      --with-sysroot=/usr/$_target \
      --with-build-sysroot=/usr/$_target \
      --with-native-system-header-dir=/include \
      --libdir=/usr/lib --libexecdir=/usr/lib \
      --target=$_target --host=$CHOST --build=$CHOST \
      --disable-nls --enable-default-pie \
      --enable-languages=c,c++,fortran \
      --enable-shared --enable-threads=posix \
      --with-system-zlib --with-isl --enable-__cxa_atexit \
      --disable-libunwind-exceptions --enable-clocale=gnu \
      --disable-libstdcxx-pch --disable-libssp \
      --enable-gnu-unique-object --enable-linker-build-id \
      --enable-lto --enable-plugin --enable-install-libiberty \
      --with-linker-hash-style=gnu --enable-gnu-indirect-function \
      --disable-multilib --disable-werror \
      --enable-checking=release

  make
}

package() {
  cd gcc-build

  make DESTDIR="$pkgdir" install-gcc install-target-{libgcc,libstdc++-v3,libgomp,libgfortran,libquadmath,libatomic}

  # strip target binaries
  find "$pkgdir"/usr/lib/gcc/$_target/ "$pkgdir"/usr/$_target/lib \
       -type f -and \( -name \*.a -or -name \*.o \) \
       -exec $_target-objcopy -R .comment -R .note -R .debug_info -R .debug_aranges \
           -R .debug_pubnames -R .debug_pubtypes -R .debug_abbrev -R .debug_line \
           -R .debug_str -R .debug_ranges -R .debug_loc '{}' \;

  # strip host binaries
  find "$pkgdir"/usr/bin/ "$pkgdir"/usr/lib/gcc/$_target/ -type f -and \( -executable \) -exec strip '{}' \;

  # Remove files that conflict with host gcc package
  rm -r "$pkgdir"/usr/share/man/man7
  rm -r "$pkgdir"/usr/share/info
  rm -r "$pkgdir"/usr/share/gcc-$pkgver
}
