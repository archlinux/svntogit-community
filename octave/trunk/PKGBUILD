# Maintainer: Ronald van Haren <ronald.archlinux.org>
# Contributor : shining <shiningxc.at.gmail.com>
# Contributor : cyberdune <cyberdune@gmail.com>

pkgname=octave
pkgver=5.2.0
pkgrel=7
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
            'fltk: FLTK GUI')
source=(https://ftp.gnu.org/gnu/octave/octave-$pkgver.tar.gz{,.sig}
        octave-sundials4.patch)
options=('!emptydirs')
validpgpkeys=('DBD9C84E39FE1AAE99F04446B05F05B75D36644B')  # John W. Eaton
sha512sums=('fa2076fb22415e0797964c66cfb8d24643f178f45eb9c14ebb4c082767e0a53509fde550f579fa4a816348bd0f7cbc74f24144f9a30a5b9c09ebe1b3949db498'
            'SKIP'
            '4b743602e8ca91e8be8dab69e09d3e476e9edd867b2eb0b9816fbe4ca344a16bff7a413c2e89b0c9fb769f4a815a696c4d67b70282b7e4fe8c24598bcce90d34')

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
