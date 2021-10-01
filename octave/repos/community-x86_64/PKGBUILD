# Maintainer: Ronald van Haren <ronald.archlinux.org>
# Contributor : shining <shiningxc.at.gmail.com>
# Contributor : cyberdune <cyberdune@gmail.com>

pkgname=octave
pkgver=6.3.0
pkgrel=3
pkgdesc="A high-level language, primarily intended for numerical computations."
arch=('x86_64')
url="https://www.gnu.org/software/octave/"
license=('GPL')
depends=('fftw' 'curl' 'graphicsmagick' 'glpk' 'hdf5' 'qhull' 'arpack' 'glu' 'ghostscript'
 	   'sundials' 'gl2ps' 'qscintilla-qt5' 'libsndfile' 'qt5-tools' 'qrupdate')
makedepends=('gcc-fortran' 'texlive-core' 'suitesparse' 'texinfo' 'gnuplot' 'fltk' 'portaudio' 'jdk8-openjdk')
optdepends=('texinfo: for help-support in octave'
            'gnuplot: alternative plotting'
            'portaudio: audio support'
            'java-runtime: java support'
            'fltk: FLTK GUI'
            'texlive-bin: for the publish command')
source=(https://ftp.gnu.org/gnu/octave/octave-$pkgver.tar.gz{,.sig})
options=('!emptydirs')
validpgpkeys=('DBD9C84E39FE1AAE99F04446B05F05B75D36644B')  # John W. Eaton
sha512sums=('9582d7a7d84beef2a22d3dfaf45aee4778fc0dfc0ec1831c5bcb863dd0062e996e5b7aaaa40519c23d2c730c3408e26745b9dbf73db5127ebae22da0b2532788'
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
