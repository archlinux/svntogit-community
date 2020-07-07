# Maintainer: Robin Broda <robin@broda.me>
# Contributor: Pierre Neidhardt <ambrevar@gmail.com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Gergely Imreh <imrehgATgmailDOTcom>
# Contributor: dschauer <dschauerATgmailDOTcom>
# Contributor: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: Jeremy Cowgar <jeremy@cowgar.com>

pkgname=tcc
pkgver=0.9.27
pkgrel=4
pkgdesc="Tiny C Compiler"
arch=('x86_64')
url="https://bellard.org/tcc/"
license=('LGPL')
depends=('glibc')
options=('docs' 'staticlibs')
source=("https://download.savannah.nongnu.org/releases/tinycc/${pkgname}-${pkgver}.tar.bz2")
md5sums=('9cdb185555da76db90287db351ca40b8')

build() {
  cd ${pkgname}-${pkgver}
  unset CFLAGS
  unset LDFLAGS
  ./configure --prefix=/usr
  make
}

package() {
  cd ${pkgname}-${pkgver}

 make DESTDIR="$pkgdir" docdir="$pkgdir"/usr/share/doc/tcc install

 make clean
 make CFLAGS="-fPIC"
 gcc -shared -o libtcc.so *.o
 install -Dm755 libtcc.so -t "${pkgdir}/usr/lib/"
}
