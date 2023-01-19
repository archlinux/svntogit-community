# Maintainer: Ronald van Haren <ronald.archlinux.org>
# Contributor : shining <shiningxc.at.gmail.com>
# Contributor : cyberdune <cyberdune@gmail.com>

pkgname=octave
pkgver=7.3.0
pkgrel=5
pkgdesc="A high-level language, primarily intended for numerical computations"
arch=('x86_64')
url="https://www.gnu.org/software/octave/"
license=('GPL')
depends=('fftw' 'curl' 'graphicsmagick' 'glpk' 'hdf5' 'qhull' 'arpack' 'glu' 'ghostscript'
 	   'sundials' 'gl2ps' 'qscintilla-qt5' 'libsndfile' 'qt5-tools' 'qrupdate' 'pcre')
makedepends=('gcc-fortran' 'texlive-core' 'suitesparse' 'texinfo' 'gnuplot' 'fltk' 'portaudio' 'jdk-openjdk' 'rapidjson')
optdepends=('texinfo: for help-support in octave'
            'gnuplot: alternative plotting'
            'portaudio: audio support'
            'java-runtime: java support'
            'fltk: FLTK GUI'
            'texlive-bin: for the publish command')
source=(https://ftp.gnu.org/gnu/octave/octave-$pkgver.tar.gz{,.sig}
        suitesparse-7.patch)
options=('!emptydirs')
validpgpkeys=('DBD9C84E39FE1AAE99F04446B05F05B75D36644B')  # John W. Eaton
sha512sums=('1289d22582f3b23d3cc843d2fc73e401371802ac6eab837026fd51170e78a2ae1cbaa856b9aad84e47d8e177345e8053b673280db411da5ab1164c6efa17b58c'
            'SKIP'
            '0312bfa9662d6c0eafa60fde29d37ef9f6e3e095e2cbb7846dc5b4b4b989a67534068f17db854813cc0b1b5e25b0013e70dcd8c899380714a73122fa33011714')

prepare() {
  patch -d $pkgname-$pkgver -p1 < suitesparse-7.patch # Fix build with suitesparse 7
}

build() {
  cd ${pkgname}-${pkgver}

  ./configure --prefix=/usr --libexecdir=/usr/lib \
    --enable-shared --disable-static \
    --with-quantum-depth=16
  make
}

package(){
  cd ${pkgname}-${pkgver}

  make DESTDIR="${pkgdir}" install

  # add octave library path to ld.so.conf.d
  install -d "${pkgdir}/etc/ld.so.conf.d"
  echo "/usr/lib/${pkgname}/${pkgver}" > "${pkgdir}/etc/ld.so.conf.d/${pkgname}.conf"
}
