# Maintainer: Lukas Fleischer <archlinux at cryptocrack dot de>
# Contributor: Firmicus <firmicus α gmx δ net>
# Contributor: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=pdfedit
pkgver=0.4.5
pkgrel=2
pkgdesc='Full featured editor for manipulating PDF documents'
arch=('i686' 'x86_64')
url='http://pdfedit.petricek.net/index_e.html'
license=('GPL')
depends=('qt3' 't1lib' 'gsfonts')
makedepends=('boost' 'doxygen')
source=("http://downloads.sourceforge.net/pdfedit/${pkgname}-${pkgver}.tar.bz2"
        'pdfedit.png'
        'pdfedit.desktop')
md5sums=('80502ee7f08cdfb867ffdaa92d160a23'
         '70fd938b2ef9da748a093df7e20d1d7d'
         'c0572c2dd54065322321718aa49ed6b8')

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"

  sed -i 's:/usr/share/fonts/type1/gsfonts:/usr/share/fonts/Type1:' src/xpdf/xpdf/GlobalParams.cc
  QTDIR=/usr ./configure --prefix=/usr
  make CXXFLAGS+="-I/usr/include/qt3" MOC=/usr/bin/moc-qt3 UIC=/usr/bin/uic-qt3 QTDIR=/usr
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}"

  make INSTALL_ROOT="${pkgdir}" install

  install -Dm0644 ../pdfedit.desktop "${pkgdir}/usr/share/applications/pdfedit.desktop"
  install -Dm0644 ../pdfedit.png "${pkgdir}/usr/share/pixmaps/pdfedit.png"
}
