# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Ronald van Haren <ronald.archlinux.org>
# Contributor: Damir Perisa <damir.perisa@bluewin.ch>
# Contributor: K. Piche <kpiche@rogers.com>

pkgname=r
pkgver=4.2.1
pkgrel=3
pkgdesc='Language and environment for statistical computing and graphics'
arch=(x86_64)
license=(GPL)
url='https://www.r-project.org/'
depends=(lapack libtiff pcre2 perl libxmu pango zip unzip curl icu which)
makedepends=(jdk-openjdk gcc-fortran tk texlive-core)
optdepends=('tk: tcl/tk interface'
            'texlive-bin: latex sty files'
            'gcc-fortran: needed to compile some CRAN packages'
            'openblas: faster linear algebra')
backup=('etc/R/Makeconf' 'etc/R/Renviron' 'etc/R/ldpaths' 'etc/R/repositories' 'etc/R/javaconf')
options=(!emptydirs)
source=(https://cran.r-project.org/src/base/R-${pkgver%%.*}/R-$pkgver.tar.gz
	r.desktop
	r.png
	R.conf)
sha256sums=('4d52db486d27848e54613d4ee977ad952ec08ce17807e1b525b10cd4436c643f'
            '25b01ea93fa704884b65ba002d44d4e99725bd826997e8c73b6467df9f23c798'
            '1580d06a737951f4f3c903cbd514247d9071fc6868eb9c2de94bb999cc195cb1'
            'b7833166041b06f716b6a79095d27d4abd83549816dc53193213827139eae6ef')

prepare() {
  cd R-$pkgver
  # set texmf dir correctly in makefile
  sed -i 's|$(rsharedir)/texmf|${datarootdir}/texmf|' share/Makefile.in
}

build() {
  cd R-$pkgver
# -ffat-lto-objects is needed for third-party packages shipping static libraries
  CFLAGS+=" -ffat-lto-objects" \
  CXXFLAGS+=" -ffat-lto-objects" \
  ./configure  --prefix=/usr \
               --libdir=/usr/lib \
               --sysconfdir=/etc/R \
               --datarootdir=/usr/share \
               rsharedir=/usr/share/R/ \
               rincludedir=/usr/include/R/ \
               rdocdir=/usr/share/doc/R/ \
               --with-x \
               --enable-R-shlib \
               --enable-memory-profiling \
               --with-lapack \
               --with-blas \
               F77=gfortran \
               LIBnn=lib
  make
  make pdf info

  cd src/nmath/standalone
  make shared
}

package() {
  cd R-$pkgver
  make DESTDIR="$pkgdir" install install-pdf install-info

# install libRmath.so
  cd src/nmath/standalone
  make DESTDIR="$pkgdir" install

# Fixup R wrapper scripts.
  sed -i "s|$pkgdir ||" "${pkgdir}/usr/bin/R"
  rm "$pkgdir"/usr/lib/R/bin/R
  cd "$pkgdir"/usr/lib/R/bin
  ln -s ../../../bin/R

# install some freedesktop.org compatibility
  install -Dm644 "$srcdir"/r.desktop -t "$pkgdir"/usr/share/applications
  install -Dm644 "$srcdir"/r.png -t "$pkgdir"/usr/share/pixmaps

# move the config directory to /etc and create symlinks
  install -d "$pkgdir"/etc/R
  cd "$pkgdir"/usr/lib/R/etc
  for _i in *; do
    mv -f $_i "$pkgdir"/etc/R
    ln -s /etc/R/$_i $_i
  done

# Install ld.so.conf.d file to ensure other applications access the shared lib
  install -Dm644 "$srcdir"/R.conf -t "$pkgdir"/etc/ld.so.conf.d

# Add provides for bundled packages
  for _f in "$pkgdir"/usr/lib/R/library/*/DESCRIPTION; do
    _pkg=$(grep Package: $_f | cut -d' ' -f2 | tr '[:upper:]' '[:lower:]')
    _ver=$(grep Version $_f | cut -d' ' -f2)
    _prov="r-$_pkg=${_ver/-/.}"
    provides+=($_prov)
  done
}
