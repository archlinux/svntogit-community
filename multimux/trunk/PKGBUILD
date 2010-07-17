# Contributor: Jaroslaw Swierczynski <swiergot@juvepoland.com>
# Contributor: Shadowhand <woody.gilk@gmail.com>

pkgname=multimux
pkgver=0.2.5.2
pkgrel=1
pkgdesc='Combines up to 8 audio mono wave channels into one big multi channel wave file'
url='http://panteltje.com/panteltje/dvd/'
license=('GPL')
arch=('i686' 'x86_64')
source=("http://panteltje.com/panteltje/dvd/${pkgname}-${pkgver}.tgz")
md5sums=('a16531945db4eec67563fa8bfa143193')

build() {
  cd ${pkgname}-${pkgver}

  install -d ${pkgdir}/usr/bin

  sed -i "s|/usr/local/bin|${pkgdir}/usr/bin|g" Makefile

  make
}

package() {
  cd ${pkgname}-${pkgver}

  make install
}
