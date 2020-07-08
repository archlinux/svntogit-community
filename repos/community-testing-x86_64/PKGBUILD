# Maintainer: Jaroslav Lichtblau <dragonlord@aur.archlinux.org>
# Contributor: kfgz <kfgz at interia pl>
# Contributor: Adam Wolk <netprobe at gmail dot com>

pkgname=libewf
pkgver=20140608
pkgrel=6
pkgdesc="A library for support of the Expert Witness Compression Format (EWF)"
arch=('x86_64')
url="https://github.com/libyal/libewf/"
license=('LGPL3')
makedepends=('fuse2')
depends=('util-linux' 'zlib' 'bzip2')
optdepends=('fuse2: to be able to use ewfmount')
source=(https://pkgs.fedoraproject.org/repo/pkgs/libewf/libewf-20140608.tar.gz/fdf615f23937fad8e02b60b9e3e5fb35/libewf-20140608.tar.gz)
sha256sums=('d14030ce6122727935fbd676d0876808da1e112721f3cb108564a4d9bf73da71')

build() {
  cd "${srcdir}"/$pkgname-$pkgver

  CPPFLAGS="$CPPFLAGS -std=gnu89"
  ./configure --prefix=/usr --sysconfdir=/etc --without-openssl
  make
}

package() {
  cd "${srcdir}"/$pkgname-$pkgver

  make DESTDIR="${pkgdir}" install
}
