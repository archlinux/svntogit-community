# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Mattias Andrée <`base64 -d`(bWFhbmRyZWUK)@member.fsf.org>
# Contributor: Jonathan Frawley <jonathanfrawley@gmail.com>

pkgname=xcftools
pkgver=1.0.7
pkgrel=6
pkgdesc='Command line tools for use with the open XCF image format (includes xcf2png)'
# no https available
url='http://henning.makholm.net/software'
arch=(x86_64)
license=(custom)
depends=(libpng perl)
source=("http://henning.makholm.net/xcftools/xcftools-$pkgver.tar.gz"
        xcftools.patch)
sha256sums=('1ebf6d8405348600bc551712d9e4f7c33cc83e416804709f68d0700afde920a6'
            'fc70dbef790bc708b1609c4393a08e565f0617e697c735078e3368048dd33a4d')

prepare() {
  grep -A16 License "$pkgname-$pkgver/README" > LICENSE
}

build() {
  cd "$pkgname-$pkgver"
  patch -i ../xcftools.patch
  ./configure --prefix=/usr
  make
}

package() {
  make DESTDIR="$pkgdir" -C "$pkgname-$pkgver" install
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim: ts=2 sw=2 et:
