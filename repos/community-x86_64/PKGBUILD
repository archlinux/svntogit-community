# Maintainer: Ronald van Haren <ronald.archlinux.org>
# Contributor : shining <shiningxc.at.gmail.com>
# Contributor : cyberdune <cyberdune@gmail.com>

pkgname=octave
pkgver=7.2.0
pkgrel=4
pkgdesc="A high-level language, primarily intended for numerical computations"
arch=('x86_64')
url="https://www.gnu.org/software/octave/"
license=('GPL')
depends=('fftw' 'curl' 'graphicsmagick' 'glpk' 'hdf5' 'qhull' 'arpack' 'glu' 'ghostscript'
 	   'sundials' 'gl2ps' 'qscintilla-qt5' 'libsndfile' 'qt5-tools' 'qrupdate' 'pcre')
makedepends=('gcc-fortran' 'texlive-core' 'suitesparse' 'texinfo' 'gnuplot' 'fltk' 'portaudio' 'jdk8-openjdk' 'rapidjson')
optdepends=('texinfo: for help-support in octave'
            'gnuplot: alternative plotting'
            'portaudio: audio support'
            'java-runtime: java support'
            'fltk: FLTK GUI'
            'texlive-bin: for the publish command')
source=(https://ftp.gnu.org/gnu/octave/octave-$pkgver.tar.gz{,.sig})
options=('!emptydirs')
validpgpkeys=('DBD9C84E39FE1AAE99F04446B05F05B75D36644B')  # John W. Eaton
sha512sums=('b1f484fb97ca9270c3090f73b01f1ec0dcd6d3f838ecf7f46c50eb6245a1fa454fbc15dcf87b462a71532ba324cccd4d547b8a5b6a8e7a0914ea14981386b024'
            'SKIP')

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
