# Maintainer: Ronald van Haren <ronald.archlinux.org>
# Contributor : shining <shiningxc.at.gmail.com>
# Contributor : cyberdune <cyberdune@gmail.com>

pkgname=octave
pkgver=5.1.0
pkgrel=5
pkgdesc="A high-level language, primarily intended for numerical computations."
arch=('x86_64')
url="https://www.gnu.org/software/octave/"
license=('GPL')
depends=('fftw' 'curl' 'graphicsmagick' 'glpk' 'hdf5' 'qhull' 'arpack' 'glu' 'ghostscript'
 	   'sundials' 'gl2ps' 'qscintilla-qt5' 'libsndfile' 'qt5-tools' 'qrupdate')
makedepends=('gcc-fortran' 'texlive-core' 'suitesparse' 'texinfo' 'gnuplot' 'fltk' 'portaudio' 'jdk8-openjdk' 'sundials')
optdepends=('texinfo: for help-support in octave'
            'gnuplot: alternative plotting'
            'portaudio: audio support'
            'java-runtime: java support'
            'fltk: FLTK GUI')
source=(https://ftp.gnu.org/gnu/octave/octave-$pkgver.tar.gz{,.sig}
        octave-sundials4.patch)
options=('!emptydirs')
validpgpkeys=('DBD9C84E39FE1AAE99F04446B05F05B75D36644B')  # John W. Eaton
sha256sums=('e36b1124cac27c7caa51cc57de408c31676d5f0096349b4d50b57bfe1bcd7495'
            'SKIP'
            'bfa7253f7b572158ce05fee117cd24325ec73e7f3acbcc73b3c34d6e52f01f5a')

prepare() {
  cd $pkgname-$pkgver
  patch -p1 -i ../octave-sundials4.patch # Fix sundials support https://savannah.gnu.org/bugs/?52475
  autoreconf -vif
}

build() {
  cd ${pkgname}-${pkgver}

  ./configure --prefix=/usr --libexecdir=/usr/lib \
    --enable-shared --disable-static \
    --with-quantum-depth=16 \
    --with-sundials_ida="-lsundials_ida -lsundials_sunlinsolklu"
  make
}

package(){
  cd "${srcdir}/${pkgname}-${pkgver}"

  make DESTDIR="${pkgdir}" install

  # add octave library path to ld.so.conf.d
  install -d "${pkgdir}/etc/ld.so.conf.d"
  echo "/usr/lib/${pkgname}/${pkgver}" > "${pkgdir}/etc/ld.so.conf.d/${pkgname}.conf"
}
