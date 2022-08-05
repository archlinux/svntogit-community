# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Ionut Biru  <ibiru@archlinux.ro>
# Contributor: William Rea <sillywilly@gmail.com>
# Contributor: Allan McRae <mcrae_allan@hotmail.com>

pkgname=geany
pkgver=1.38
pkgrel=3
pkgdesc='Fast and lightweight IDE'
arch=(x86_64)
url='https://www.geany.org/'
license=(GPL)
depends=(gtk3)
makedepends=(doxygen intltool python-lxml)
optdepends=('geany-plugins: additional functionality'
            'vte3: embedded terminal support')
source=("https://download.geany.org/$pkgname-$pkgver.tar.bz2"
        'paste.patch::https://github.com/geany/geany/commit/c832f316a670f7c3d34f5c75d63743e2f9bf6563.patch')
b2sums=('3dda3a7454f96be18de95f8dfeb7a6ee2627ffe370879fa3ee7aee851e21fa46076de6b9741b6e83af94b66afa245a0f69237db4582858bc40f819d8a3c78e6e'
        'f9ce30599d5cff6d72bd942217df78bf16f305d1a95fa04745bc730ba2112186717d9792f267259c03ea2614e505b429a2b17e7e0afafc8155d0ccea3d63803c')

prepare() {
  cd $pkgname-$pkgver
  patch -p1 -i ../paste.patch
}

build() {
  cd $pkgname-$pkgver
  ./configure --enable-gtk3 --enable-gtkdoc-header --prefix=/usr
  sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool
  make
}

package() {
  make -C $pkgname-$pkgver DESTDIR="$pkgdir" install
}
